#!/usr/bin/perl

use strict; #$B87L)$JJ8K!%A%'%C%/(B.

# $B%5%V%k!<%A%s$N8F$S=P$7(B.
default_arguments_func();

# $B%5%V%k!<%A%s(Bdefault_arguments_func$B$NDj5A(B.
sub default_arguments_func{
  my %default_arguments = (-value1 => 'AAA',
                           -value2 => 'BBB',
                           -value3 => 'CCC'); # $B0z?t$N%G%U%)%k%HCM$O$3$&$J$C$F$$$k(B.
  my %arguments = (%default_arguments, @_); # $B<B:]$N0z?t$O%G%U%)%k%H$N%-!<$r;}$D%O%C%7%e$HEO$5$l$?%O%C%7%e$G9=@.$5$l$k(B.
  foreach my $key (keys(%arguments)){
    print "$key = $arguments{$key}\n";
  }
}
