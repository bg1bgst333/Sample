#!/usr/bin/perl

# ハッシュにキーと値をセット.
$hash1{'key1'} = 'value1';
$hash1{'key2'} = 'value2';
$hash1{'key3'} = 'value3';

# 指定されたキーでハッシュの値を取得し, 出力.
print "$hash1{'key1'}\n";
print "$hash1{'key2'}\n";
print "$hash1{'key3'}\n";

# リストでキーと値をセット.
%hash2 = ('keya', 'valuea',
          'keyb', 'valueb',
          'keyc', 'valuec');

# 指定されたキーでハッシュの値を取得し, 出力.
print "$hash2{'keya'}\n";
print "$hash2{'keyb'}\n";
print "$hash2{'keyc'}\n";

# "=>"を使ってキーと値をセット.
%hash3 = ('keyx' => 'valuex',
          'keyy' => 'valuey',
          'keyz' => 'valuez');

# 指定されたキーでハッシュの値を取得し, 出力.
print "$hash3{'keyx'}\n";
print "$hash3{'keyy'}\n";
print "$hash3{'keyz'}\n";
