#!/usr/bin/perl

use strict; # 厳密な文法チェック.

# ファイルpacked.binのファイルサイズを取得する.
my $filesize = -s "packed.bin"; # -sでサイズを取得.
print "filesize = $filesize\n"; # printで$filesizeを出力.

# packed.binを開く.
my $ret = open(my $fh, "<", "packed.bin"); # openでpacked.binを読み込みモードで開く.
if ($ret){ # オープン成功.
  binmode($fh); # バイナリモード
  read($fh, my $buf, $filesize); # readで$fhから$filesize読み込み$bufに格納.
  my @unpacked = unpack("l3", $buf); # unpackで$bufを戻す.
  foreach my $val (@unpacked){ # @unpackedを取り出し$valに格納.
    print $val."\n"; # 取り出した$valを出力.
  }
  close($fh); # 閉じる.
}
