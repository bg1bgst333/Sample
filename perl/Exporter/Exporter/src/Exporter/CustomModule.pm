# CustomModule
package CustomModule;
use Exporter; # Exporter.pm
@ISA = qw/Exporter/; # 継承関係

# メソッドの公開.
@EXPORT = qw/public_method_1/; # @EXPORTにpublic_method_1をセットし, 公開.

# BEGIN
BEGIN{
  print "This is BEGIN.\n";
}

# public method 1.
sub public_method_1{
  print "public_method_1.\n";
}

1; # これがないとエラーメッセージ.
