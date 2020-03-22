our $our_var1 = 1;
our $our_var2 = 2;
print '$our_var1'." = $our_var1\n";
print '$our_var2'." = $our_var2\n";

package PackageA;
{

  $our_var1 = 10;
  local $our_var2 = 20; # 元の値2を退避して, このスコープ内では20とする.
  print '$our_var1'." = $our_var1\n";
  print '$our_var2'." = $our_var2\n";

}

print '$our_var1'." = $our_var1\n"; # 10のまま.
print '$our_var2'." = $our_var2\n"; # 2に戻る.
