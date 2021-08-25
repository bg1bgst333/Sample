#!C:\Users\bg1\AppData\Local\activestate\d0653c90\bin\perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# パラメータの有無.
if ($ENV{'REQUEST_METHOD'} eq 'POST'){ # 'POST'の時.

  # CGIヘッダの出力.
  print "Content-type: image/bmp\n"; # "Content-type: image/bmp\n"を出力.
  print "\n"; # "\n"を出力.

  # CGIオブジェクトの作成.
  my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

  # リクエストの読み込み.
  my $buf; # バッファ.
  $buf = $q->param('POSTDATA'); # マルチパートやURLエンコードでない場合はCGI::param('POSTDATA')でボディを取得できる.

  # ファイルへの書き出し.
  my $ret = open(OUT, ">", "image1.bmp"); # image1.bmpを開く.
  if ($ret){ # trueの時.
    binmode(OUT); # OUTをバイナリモードにセット.
    print OUT $buf; # OUTに$bufを書き込む.
  }

}