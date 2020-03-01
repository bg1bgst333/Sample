# CustomModule
package CustomModule;

# BEGIN
BEGIN{
  print "This is BEGIN.\n";
}

# END
END{
  print "This is END.\n";
}

# error func.
sub error_func{
  print "error_func.\n";
  die "error!\n";
  print "error after!\n";
}

1; # これがないとエラーメッセージ.
