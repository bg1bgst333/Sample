#!/usr/bin/perl

# printで文字列を出力.
print "ABC\n"; # printで"ABC"を出力.

# main::printを定義.(ここでの関数はmainパッケージに含まれる.)
sub print{
  print "DEF\n"; # printで"DEF"を出力.
}

# main::printで文字列を出力.
main::print "GHI\n"; # 上のmain::printで出力するので, "GHI"ではなく"DEF"が出力される.

# ただのprintは, 組み込み関数.
print "JKL\n"; # "JKL"が出力される.
