# CustomModule
package CustomModule;
use Exporter; # Exporter.pm
@ISA = qw/Exporter/; # 継承関係

# メソッドの公開.
@EXPORT = qw/public_method_1 public_method_2/; # @EXPORTにpublic_method_1, public_method_2をセットし, 公開.
@EXPORT_OK = qw/public_method_3/; # @EXPORT_OKにpublic_method_3をセット.

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

# public method 3.
sub public_method_3{
  print "public_method_3.\n";
}

# private method.
sub private_method{
  print "private_method.\n";
}

1; # これがないとエラーメッセージ.
