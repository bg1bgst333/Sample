# CustomModule
package CustomModule;
use Exporter;
use Carp;
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
  croak "func exception";

}

1; # これがないとエラーメッセージ.
