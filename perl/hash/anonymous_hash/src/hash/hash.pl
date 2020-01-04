#!/usr/bin/perl

# 無名ハッシュの生成
$anonymous_hash = {'key1' => 'value1',
                   'key2' => 'value2'};

# 無名ハッシュの参照
print $anonymous_hash."\n"; # これはリファレンス.
print %$anonymous_hash."\n"; # これはハッシュだが, サイズが出力される.
print $$anonymous_hash{'key1'}."\n"; #value1.
print $$anonymous_hash{'key2'}."\n"; #value2.
