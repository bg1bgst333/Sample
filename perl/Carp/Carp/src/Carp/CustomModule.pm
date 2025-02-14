# CustomModule
package CustomModule;
use Exporter;
@ISA = qw/Exporter/;
@EXPORT = qw/testfunc/;

# BEGIN
BEGIN{
  print "This is BEGIN.\n";
}

# testfunc
sub testfunc{

  print "test1\n";
  print "test2\n";
  die "func exception";

}

1; # これがないとエラーメッセージ.
