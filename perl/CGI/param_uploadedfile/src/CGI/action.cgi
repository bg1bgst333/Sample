#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.
  
# パラメータの有無.
if ($ENV{'REQUEST_METHOD'} eq 'POST'){ # 'POST'の時.

  # CGIヘッダの出力.
  print "Content-type: text/plain\n"; # "Content-type: text/plain\n"を出力.
  print "\n"; # "\n"を出力.

  # リクエストの読み込み.
  my $file = $q->param('uploadedfile'); # アップロード対象のファイルが返る.
  print '$file = '."$file\n"; # printだとファイル名.
  my $buf; # バッファ.
  my $numbytes = 1024; # 1回で読み込むバイト数を1024とする.
  my $bytesread; # 実際に読み込んだバイト数.
  print "-----file begin-----\n"; # 開始.
  while ($bytesread = read($file, $buf, $numbytes)){ # 全部読み込む.
    print $buf; # バッファ出力.
  }
  print "-----file end-----\n"; # 終了.
  print 'ref($file) = '.ref($file)."\n"; # ref($file)を出力.

}
else{ # 'POST'以外.('GET'など.)

  # HTTPヘッダの出力.
  print $q->header;

  # HTMLヘッダの出力.
  print $q->start_html("CGI::param(uploadedfile)"); # <html>タグなどの出力.

  # HTMLフォームの出力.
  print $q->start_form; # <form>タグの出力.
  print "\n"; # 改行の出力.
  print $q->filefield(-name => 'uploadedfile'); # ファイル選択.
  print $q->submit; # submit
  print $q->end_form; # </form>タグの出力.

  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
