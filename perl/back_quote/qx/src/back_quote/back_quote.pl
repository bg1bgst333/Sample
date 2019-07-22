#!/usr/bin/perl

# lsを実行.
$command = qx/ls/; # $commandにqx/ls/を格納.
print $command; # $commandは変数展開時にコマンド実行される.(lsの改行出力があるので, printで改行は不要.)
