#!/usr/bin/perl

# ファイルから1行読み込み.
$ret = open(IN, "<", "test.txt"); # "test.txt"は存在するのでtrueが返る.
if ($ret){ # trueの時.

  # 読み込んだ行の表示.
  print "open success \"test.txt\".\n"; # "open success "test.txt"."と出力.
  $line = <IN>; # ファイルハンドルのシンボルINから取り出した1行の文字列を$lineに格納.
  chomp($line); # 末尾の改行を取り除く.
  print '$line = ' . $line . "\n"; # $lineの中身を出力.

  # 別のファイルへ書き込み.
  open(OUT, ">", "output.txt"); # "output.txt"を書き込み用にオープン.
  print OUT $line; # ファイルハンドルのシンボルOUTの指すファイルに$lineを出力.
  close(OUT); # ファイルをクローズ.

  # 終了処理.
  close(IN); # ファイハンドル"IN"をクローズ.

}
