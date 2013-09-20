use List::Util qw (min);
use constant START => 100;
use constant MUL => 10;
$q = pop @ARGV;
open my $result, ">", $q;# or die "cannot open file $w: $!";
open my $f, "<", pop @ARGV or die "cannot open file $w: $!";
my $fence = <$f>;
close $f;
my $i = @ARGV;
my $exp = START;
for(1..$i) {
	$q = shift @ARGV;
	open my $source, "<", $q or die "cannot open file $q: $!";
	my $min = <$source>;
	print $result (($min - $fence)/$exp);
	print $result "\n";
	$exp *= MUL;
	close $source;
}
close $result;
