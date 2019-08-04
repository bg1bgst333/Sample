#!/usr/bin/perl

# ローカル時刻の取得
($sec, $min, $hour, $day, $mon, $year, $wday) = localtime; # ローカル時刻の各種値をリストで受け取る.
$yearstr = $year + 1900; # 1900を足すことで$yearの文字列版$yearstrをセット.
$monstr = $mon + 1; # 1を足すことで$monの文字列版$monstrをセット.
$wdaystr = ("Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat")[$wday]; # リストの添字を使って$wdayの文字列版$wdaystrをセット.
print "$yearstr/$monstr/$day $hour:$min:$sec ($wdaystr)\n"; # ローカル時刻文字列の出力.
