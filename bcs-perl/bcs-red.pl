use strict;

my $limit = shift || 2_000_000;

srand();

my ($type, $classname, $maneuver, $jump, $tl, $ad, $bd, $cd, $dd, $ed, $aa, $ba, $ca, $da, $ea, $tons);

my @crt = (

	[ 6, 7, 8, 9, 10, 12, 13, 14, 15, 16 ],  
	[ 3, 4, 5, 7, 8,  10, 11, 12, 13, 14 ],  
	[ 2, 3, 4, 5, 7,  8,  9,  11, 12, 13 ],  
	[ 1, 2, 3, 4, 6,  7,  8,  9,  10, 11 ],  
	[ 0, 1, 2, 3, 5,  6,  8,  9,  10, 11 ],  
	[ 0, 0, 1, 2, 3,  5,  6,  7,  8,  9 ],   
	[ 0, 0, 1, 2, 3,  4,  5,  6,  7,  8 ],   
	[ 0, 0, 0, 2, 2,  3,  4,  5,  6,  7 ],   
	[ 0, 0, 0, 1, 2,  2,  3,  4,  5,  6 ],   
	[ 0, 0, 0, 1, 1,  1,  2,  2,  3,  3 ],   
	[ 0, 0, 0, 1, 1,  1,  1,  1,  2,  2 ],   
   [ 0, 0, 0, 0, 1,  1,  1,  1,  1,  2 ],   
   [ 0, 0, 0, 0, 0,  1,  1,  1,  1,  2 ],   
   [ 0, 0, 0, 0, 0,  0,  1,  1,  1,  2 ],   
   [ 0, 0, 0, 0, 0,  0,  1,  1,  1,  1 ],   
   [ 0, 0, 0, 0, 0,  0,  0,  1,  1,  1 ],   
   [ 0, 0, 0, 0, 0,  0,  0,  1,  1,  1 ],   
   [ 0, 0, 0, 0, 0,  0,  0,  1,  1,  1 ],   

);

my %shipdb;

$|=1;
foreach (<DATA>)
{
   ($classname, $type, $maneuver, $jump, $ad, $bd, $cd, $dd, $ed, $aa, $ba, $ca, $da, $ea, $tons) = split /\s+/;
   ($type, $tl) = split '-', $type;

   $shipdb{ $classname } = 
   {
      type => $type,
      classname => $classname,
      maneuver => $maneuver,
      jump => $jump,
      tl => $tl,
      ad => $ad,
      bd => $bd,
      cd => $cd,
      dd => $dd,
      ed => $ed,
      aa => $aa,
      ba => $ba,
      ca => $ca,
      da => $da,
      ea => $ea,
      tons => $tons
   };

   $classname = sprintf("%-18s", $classname);
   $classname = "\U$classname";

   print "$classname  $type-$tl    M$maneuver J$jump    Def: $ad$bd$cd$dd$ed    Off: $aa$ba$ca$da$ea    $tons kt\n";
}
print "\n";
$|=0;

my @ships = keys %shipdb;
my %combatdb;

for (1..$limit)
{
   print STDERR $_/100_000, ' ' unless $_ % 200_000;

   my $ship1 = $shipdb{ $ships[ rand(scalar(@ships)) ] };
   my $ship2 = $shipdb{ $ships[ rand(scalar(@ships)) ] };

   my $ship1class = $ship1->{ classname };
   my $ship2class = $ship2->{ classname };

   redo if $ship1class eq $ship2class;

   my ($ship1choice, $ship1arank, $ship2drank) = chooseWeapon( $ship1, $ship2 ); 
   my ($ship1attValue, $ship2defValue) = resolveAttack( $ship1choice, $ship1arank, $ship2drank );


   #my ($ship2choice, $ship2arank, $ship1drank) = chooseWeapon( $ship2, $ship1 );
   #my ($ship2attValue, $ship1defValue) = resolveAttack( $ship2choice, $ship2arank, $ship1drank );

   #$ship1class = "$ship1class (att:$ship1choice)";
   #$ship2class = "$ship2class (att:$ship2choice)";

   my $key = "$ship1class -> $ship2class ($ship1choice)";

   $combatdb{ $key }->{ 'trials' }++;
   $combatdb{ $key }->{ 'ships' }->{ $ship1class }++ if $ship1attValue > $ship2defValue;
   #$combatdb{ $key }->{ 'ships' }->{ $ship2class }++ if $ship2attValue > $ship1defValue;
}

print STDERR "\n";

printf "%-45s  %-20s       %-20s\n", 'Match', 'Success %'; # , 'Success % /Class';
printf "------------------------------------------     --------------------\n"; #       --------------------\n";

foreach my $scenario (sort keys %combatdb)
{
   my $results = $combatdb{ $scenario };

   printf "%-45s: ", $scenario;
   foreach my $shipclass (sort keys %{$results->{ 'ships' }})
   {
      printf "%3d%", $results->{ 'ships' }->{ $shipclass } * 100/$results->{ 'trials' };
   }
   print "\n";
}

#
#   Choose weapon type and return rank
#
sub chooseWeapon
{
   my $attacking_ship = shift;
   my $defending_ship = shift;
   
   my $choice;
   my $a_rank;
   my $d_rank;
   my $use_primary = int(rand(2)); # 0 or 1
   $use_primary = 0 if $attacking_ship->{ 'aa' } == 0; # no primary weapon
  
   if ($use_primary)
   {
      $choice = 'PRI';
      $a_rank = $attacking_ship->{ 'aa' };
      $d_rank = $defending_ship->{ 'ad' };
   }
   else
   {
      $choice = '2RY';
      $a_rank = $attacking_ship->{ 'ba' };
      $d_rank = $defending_ship->{ 'bd' };
   }

   return ($choice, $a_rank, $d_rank);
}

#
#  Make the appropriate rolls based on the attack type.
#
sub resolveAttack
{
   my $attackType = shift; # PRI or 2RY
   my $rank1      = shift; # rank of attacker
   my $rank2      = shift; # rank of defender

   #
   #  OK here's the thing. The weapon factors are hexadecimal values.
   #  I.E. A=10.  So convert to decimal before using them.
   #
   $rank1 = hex $rank1;
   $rank2 = hex $rank2;

   #
   #  OK here's the other thing. The arrays are indexed from zero, right? 
   #  But, the weapon ratings are ranked from one.
   #  Therefore, adjust the ranks by subtracting one.
   #
   $rank1--; 
   $rank2--;  

   return CRT1D( $rank1, $rank2) if $attackType eq 'PRI';
   return CRT2D( $rank1, $rank2) if $attackType eq '2RY';
}

#
#   Make two 1D rolls on the CRT, using the two passed-in ranks.
#
sub CRT1D
{
   my ($rank1, $rank2) = @_;

   my $attRoll = int(rand(6));
   my $defRoll = int(rand(6));

   my $attValue = $crt[ $attRoll ]->[ $rank1 ];
   my $defValue = $crt[ $defRoll ]->[ $rank2 ];

   return ($attValue, $defValue, $attRoll, $defRoll);
}

#
#   Make two 2D rolls on the CRT, using the two passed-in ranks.
#
sub CRT2D
{
   my ($rank1, $rank2) = @_;

   my $attRoll = int(rand(6)) + int(rand(6)) + 1;
   my $defRoll = int(rand(6)) + int(rand(6)) + 1;

   my $attValue = $crt[ $attRoll ]->[ $rank1 ];
   my $defValue = $crt[ $defRoll ]->[ $rank2 ];

   return ($attValue, $defValue, $attRoll, $defRoll);
}


# Class       Code-TL  M J    Defenses     Offenses     KTons
__DATA__
Tigress       BB-15    6 3    A A A 0 0    A 7 5 0 A    500
Idlev         BB-14    5 3    A A A A 0    A 7 5 A 0    560
Viepchakl     BB-14    5 3    9 9 9 8 0    9 6 4 8 0    200
Kokirrak      BB-15    6 3    8 8 8 0 0    8 6 4 0 0    200
Plankwell     BB-15    5 4    8 7 7 0 0    8 6 4 0 0    200
Vrapkenchkinj BC-14    5 3    7 7 7 5 0    8 5 3 4 0     56
Kefchenzh     CA-14    5 3    7 8 8 0 0    8 6 4 0 0     52
Nolikian      BR-15    6 0    7 7 7 0 0    7 6 4 0 0     20
Anzha         BR-14    6 0    7 7 7 0 0    8 6 4 0 0     28
Lightning     FI-14    2 5    6 5 5 0 0    6 4 3 0 0     60
Gionetti      CL-15    5 5    5 5 5 5 0    5 4 3 5 0     30
Zhdavidlits   CL-14    5 3    4 4 4 0 0    4 3 2 0 0     14
Wind          SC-15    6 3    4 4 4 4 0    4 3 2 4 0     75
Sloan         EF-15    4 6    3 3 3 0 0    0 3 2 0 0      5
