# CustomModule
package CustomModule;
use Exporter; # Exporter.pm
@ISA = qw/Exporter/; # 継承関係

# メソッドの公開.
@EXPORT = qw/public_method_1 public_method_2/; # @EXPORTにpublic_method_1, public_method_2をセットし, 公開.

# BEGIN
BEGIN{
  print "This is BEGIN.\n";
}

# public method 1.
sub public_method_1{
  print "public_method_1.\n";
}

# public method 2.
sub public_method_2{
  print "public_method_2.\n";
  private_method(); # private_methodを呼ぶ.
}

# private method.
sub private_method{
  print "private_method.\n";
}

1; # これがないとエラーメッセージ.
