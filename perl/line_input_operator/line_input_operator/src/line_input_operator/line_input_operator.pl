#!/usr/bin/perl

# ファイルから1行読み込み.
$ret = open(IN, "<", "test.txt"); # "test.txt"は存在するのでtrueが返る.
if ($ret){ # trueの時.
  print "open success \"test.txt\".\n"; # "open success "test.txt"."と出力.
  $line = <IN>; # ファイルハンドルINから取り出した1行の文字列を$lineに格納.
  chomp($line); # 末尾の改行を取り除く.
  print '$line = ' . $line . "\n"; # $lineの中身を出力.
  close(IN); # ファイハンドル"IN"をクローズ.
}
