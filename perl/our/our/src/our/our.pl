$unknown_var1 = 1;
my $my_var1 = 2;
our $our_var1 = 3;
print '$unknown_var1'." = $unknown_var1\n";
print '$my_var1'." = $my_var1\n";
print '$our_var1'." = $our_var1\n";

package PackageA;
{

  print '$unknown_var1'." = $unknown_var1\n"; # PackageA::$unknown_var1
  print '$my_var1'." = $my_var1\n"; # main::$my_var1
  print '$our_var1'." = $our_var1\n"; # main::$our_var1

  $unknown_var2 = 10;
  my $my_var2 = 20;
  our $our_var2 = 30;

  print '$unknown_var2'." = $unknown_var2\n";
  print '$my_var2'." = $my_var2\n";
  print '$our_var2'." = $our_var2\n";

}

print '$unknown_var1'." = $unknown_var1\n"; # PackageA::$unknown_var1
print '$my_var1'." = $my_var1\n";
print '$our_var1'." = $our_var1\n";

print '$unknown_var2'." = $unknown_var2\n";
print '$my_var2'." = $my_var2\n"; # main::$var2
print '$PackageA::our_var2'." = $PackageA::our_var2\n"; # 完全修飾名でアクセス可.

print '$our_var2'." = $our_var2\n"; # 完全修飾名なしでもアクセスできちゃうな.

print '$main::our_var2'." = $main::our_var2\n"; # mainには無いよね.

package PackageB;
{

  print '$unknown_var2'." = $unknown_var2\n";
  print '$PackageA::unknown_var2'." = $PackageA::unknown_var2\n"; # これ読めちゃうのか.(中でourになってる?)
  print '$my_var2'." = $my_var2\n";
  print '$PackageA::my_var2'." = $PackageA::my_var2\n"; # レキシカル変数はスコープ外でアクセス不可.
  print '$our_var2'." = $our_var2\n";
  print '$PackageA::our_var2'." = $PackageA::our_var2\n"; # パッケージ変数は完全修飾名でアクセス可.

}
