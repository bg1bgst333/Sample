# CustomDirectory::CustomModule
package CustomDirectory::CustomModule;

# Exporter
use Exporter;
@ISA = qw(Exporter);
@EXPORT = qw/func/;

# BEGIN
BEGIN{
  print "This is BEGIN.\n";
}

# END
END{
  print "This is END.\n";
}

# func.
sub func{
  print "func.\n";
}

1; # これがないとエラーメッセージ.
