# CustomModule
package CustomModule;
use Exporter; # Exporter.pm
@ISA = qw/Exporter/; # 継承関係

# メソッドの公開.
@EXPORT = qw/func1 func2 func3/; # func1, func2, func3を公開.

sub func1{
  print "func1\n";
}

sub func2{
  print "func2\n";
}

sub func3{
  print "func3\n";
  ($pkg, $file, $line) = caller; # callerで呼び出し元情報を取得.
  print '$pkg = '."$pkg\n"; # パッケージ名.
  print '$file = '."$file\n"; # ファイル名.
  print '$line = '."$line\n"; # 行番号.
}

1;
