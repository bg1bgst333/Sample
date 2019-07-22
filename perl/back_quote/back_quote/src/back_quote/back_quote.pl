#!/usr/bin/perl

# lsを実行.
$command = `ls`; # $commandにバッククォートで`ls`を格納.
print $command."\n"; #$commandは変数展開時にコマンド実行される.
