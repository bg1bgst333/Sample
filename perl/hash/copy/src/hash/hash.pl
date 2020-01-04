#!/usr/bin/perl

# バッシュにキーと値をセット.
$hash1{'key1'} = 'value1';
$hash1{'key2'} = 'value2';
$hash1{'key3'} = 'value3';

#ハッシュのコピー
%hash2 = %hash1; # %hash1を%hash2にコピー.
print $hash1{'key1'}."\n";
print $hash1{'key2'}."\n";
print $hash1{'key3'}."\n";
print $hash2{'key1'}."\n";
print $hash2{'key2'}."\n";
print $hash2{'key3'}."\n";
print "\n";
$hash1{'key2'} = 'value4'; # $hash1{'key2'}だけ変更.
$hash2{'key3'} = 'value5'; # $hash2{'key3'}だけ変更.
print $hash1{'key1'}."\n";
print $hash1{'key2'}."\n";
print $hash1{'key3'}."\n";
print $hash2{'key1'}."\n";
print $hash2{'key2'}."\n";
print $hash2{'key3'}."\n";
