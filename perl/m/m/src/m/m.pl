#!/usr/bin/perl

# 配列の初期化
@array = ('ABC', 'aaB', 'aBC', 'BAC', 'AAC', 'AbC', 'AaB', 'Abc'); # リストで文字列配列を初期化.

# パターンマッチング
for $var (@array){ # 配列から取り出す.
  if ($var =~ m/A[bB]C/){ # "AbC"または"ABC"に一致する時.
    print $var."\n"; # $varを出力.
  }
}
