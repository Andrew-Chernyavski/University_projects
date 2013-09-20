use List::Util qw (min);
$q = pop @ARGV;
$w = pop @ARGV;
open my $source, "<", $w or die "cannot open file $q: $!";
open my $result, ">", $q;# or die "cannot open file $w: $!";
@q = <$source>;
#print "@q";
print $result min @q;