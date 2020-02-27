# CustomModule
package CustomModule;

# BEGIN
BEGIN{
  print "This is BEGIN.\n";
}

# import
sub import{
  print "This is import.\n";
}

1; # これがないとエラーメッセージ.
