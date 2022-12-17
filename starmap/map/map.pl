use strict;
use warnings;

my $filename = shift @ARGV || 'Spinward Marches.tab';

open my $in, '<', $filename;
my $header = <$in>;
# Sector	SS	Hex	Name	UWP	Bases	Remarks	Zone	PBG	Allegiance	Stars	{Ix}	(Ex)	[Cx]	Nobility	W	RU
my @lines = <$in>;
close $in;

my $tl = 0;
my %hex = map{ $_ => $tl++ } split '', '0123456789ABCDEFGHJKLMNPQRSTUVWXYZ';
my @letter = ('A'..'P');

my @data = ();
my $sectorAbbr;

for my $line (@lines)
{
   my ($sectorName, $ss, $hex, $name, $uwp, $bases, $remarks, $zone, $pbg, $alleg, $stellar, $ix, $ex, $cx, $nobility, $w, $ru) = split /\t/, uc $line;

   next if $uwp =~ /\?\?\?/;  # ignore junk

   $sectorAbbr = $sectorName;

   my ($col, $row) = $hex =~ /^(..)(..)/;                      							# split hex col, row
   $name = substr( $name, 0, 15 );                             							# limit name length
   $name =~ s/\s*//;																    # and remove any padding
   my ($starport, $siz, $atm, $hyd, $pop, $gov, $law, $junk, $tl) = split '', $uwp;  	# split up the UWP

   # compress the SAHPGL
   my $sizatm = ($hex{$siz} & 15) + (($hex{$atm} & 15) * 16);
   my $hydpop = ($hex{$hyd} & 15) + (($hex{$pop} & 15) * 16);
   my $govlaw = ($hex{$gov} & 15) + (($hex{$law} & 15) * 16);

   my ($p, $b, $gg) = split '', $pbg;

   # ---------------------------------------------
   #
   #   Manage bases, belts, GGs, and Zone (1 byte)
   #
   # ---------------------------------------------
   $bases =~ s/[JK]/N/;
   $bases =~ s/M/S/;
   $bases =~ s/[- ]//g;
   $bases = '' unless $bases =~ /[A-Z]/;	# empty

   $bases =~ s/NS/A/;
   $bases =~ s/NW/B/;

   my $bggz = 0;                 #
   $bggz  = 1 if  $zone eq 'A';  # zone = bits 0 & 1
   $bggz  = 2 if  $zone eq 'R';  # 
   # there is no '3'

   $bggz += 4 if  $b > 0;              # belt presence is bit 2
   $bggz += 8 if $gg > 0;              # gg presence is bit 3

   $bggz += 16  if $bases =~  /S|A|W|B/;  # scout presence is bit 4
   $bggz += 32  if $bases =~  /N|A|D|B/;  # navy presence is bit 5

   # ---------------------------------------------
   #
   #  Gather up the trade remarks (3 bytes)
   #
   # ---------------------------------------------
   my $tc1 = 0;
   for my $code (reverse qw/Ag As Ba De Fl Hi In Lo Na Ni Po Ri Va Wa/)
   {
      $tc1 <<= 1;
      $tc1++ if $remarks =~ /$code\b/;
   }

   my $tc2 = 0;
   for my $code (reverse qw/An Cp He Ic Mr Re Rs Sa/)
   {
      $tc2 <<= 1;
      $tc2++ if $remarks =~ /$code\b/;
   }

   # ---------------------------------------------
   #
   #  Prepare Stellar Data (6 bytes in 2 variables)
   #
   #  example 1:
   #  1.  G3 IV M0 V M3 V
   #  2.  G34M05M35
   #  3.  G,34,M,5,M,35 = 6 bytes
   # ---------------------------------------------
   $stellar =~ s/BD/M0 D/g;
   $stellar =~ s/\s//g;

   $stellar =~ s/VI|D/6/g;
   $stellar =~ s/IV/4/g;
   $stellar =~ s/V/5/g;

   $stellar =~ s/III/3/g;
   $stellar =~ s/II/2/g;
   $stellar =~ s/I/1/g;

   my @starray = split '', $stellar;
   push @starray, ( 0, 0, 0, 0, 0, 0 ); # just to pad it out.

   my $stp1 = pack 'AC', 	$starray[0], 
   							$starray[1] * 8 + $starray[2];  # (3:5) little-endian

   my $stp2 = pack 'ACAC', 	$starray[3],
							$starray[4] * 8 + $starray[5],  # (3:5) little-endian
							$starray[6],
							$starray[7] * 8 + $starray[8];  # (3:5) little-endian

   # --------------------------------------
   #
   #  Build binary data
   #
   # --------------------------------------
   my $rec;
   $rec  = pack 'CC', 		$col, $row;  				# 00-01
   $rec .= pack 'Z15x',		$name; 		 				# 02-11
   $rec .= pack 'A',        $starport;   				# 12
   $rec .= pack 'CCC',      $sizatm, $hydpop, $govlaw;	# 13, 14, 15
   $rec .= pack 'C',        $hex{$tl}; 	 				# 16
   $rec .= pack 'C',        $bggz;       				# 17
   $rec .= pack 'v', 		$tc1;						# 18-19
   $rec .= pack 'C', 		$tc2;						# 1a
   $rec .= pack 'A2',       $alleg;						# 1b-1c
   $rec .= $stp1;  										# 1d-1e
   $rec .= pack 'x';

   push @data, $rec;
}
close $in;

my ($sectorName) = $filename =~ /^(.*?)\.tab/;
$sectorName = uc substr( $sectorName, 0, 16 ); # max 16 char

my $outfilename = "$sectorAbbr.BIN";

my $sx = 0;
my $sy = 0;

open my $out, '>', $outfilename;
print $out pack 'xx';					     # CBM padding
print $out pack 'CC', $sx, $sy;          # sector offset
print $out pack 'v', scalar @data;       # UWP count
print $out pack 'Z16', $sectorName;      # truncated sector name (16c max)
print $out pack 'x12';                   # pad to 32 bytes
print $out @data;
close $out;

printf "$filename in, $outfilename out, %d records\n", scalar @data;
