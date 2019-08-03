#!/usr/bin/perl

# 右辺値が多い場合は切り捨て.
($x[0], $x[1]) = (1, 2, 3); # 3は切り捨て.
for ($i = 0; $i < @x; $i++){
  print '$x['."$i] = $x[$i]\n";
}

# 左辺値が多い場合は割り当てられてない要素はundef.
($x[0], $x[1], $x[2]) = (1, 2); # $x[2]はundef.
for ($i = 0; $i < @x; $i++){
  if (defined $x[$i]){
    print '$x['."$i] = $x[$i]\n";
  }
  else{
    print '$x['."$i] = "."undef\n";
  }
}

# 要素が抜けている場合もundef.
($y[0], $y[2]) = (1, 2); # $y[1]はundef.
for ($i = 0; $i < @y; $i++){
  if (defined $y[$i]){
    print '$y['."$i] = $y[$i]\n";
  }
  else{
    print '$y['."$i] = "."undef\n";
  }
}

# 複数の配列に割り当て.
($a[0], $a[1], @y) = (1, 2, 3, 4, 5); # @a = (1, 2), @y = (3, 4, 5)となる.
for ($i = 0; $i < @a; $i++){
  print '$a['."$i] = $a[$i]\n";
}
for ($i = 0; $i < @y; $i++){
  print '$y['."$i] = $y[$i]\n";
}
