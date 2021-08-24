#!C:\Users\bg1\AppData\Local\activestate\d0653c90\bin\perl

use strict; # 厳密な文法チェック.

binmode STDIN; # 標準入力をバイナリモードにセット.

# パラメータの有無.
if ($ENV{'REQUEST_METHOD'} eq 'POST'){ # 'POST'の時.

  # CGIヘッダの出力.
  print "Content-type: image/bmp\n"; # "Content-type: image/bmp\n"を出力.
  print "\n"; # "\n"を出力.

  # リクエストの読み込み.
  my $buf; # バッファ.
  read(STDIN, $buf, $ENV{'CONTENT_LENGTH'});

  # ファイルへの書き出し.
  my $ret = open(OUT, ">", "image1.bmp"); # test.txtを開く.
  if ($ret){ # trueの時.
    binmode(OUT); # OUTをバイナリモードにセット.
    print OUT $buf; # OUTに$bufを書き込む.
  }

}