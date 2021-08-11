#!/usr/bin/perl

use strict; # $B87L)$JJ8K!%A%'%C%/(B.
use CGI; # CGI

# CGI$B%*%V%8%'%/%H$N:n@.(B.
my $q = CGI->new; # CGI::new$B$G(BCGI$B%*%V%8%'%/%H$r@8@.$7(B, $q$B$K3JG<(B.

# HTTP$B%X%C%@$N=PNO(B.
print $q->header;

# HTML$B%X%C%@$N=PNO(B.
print $q->start_html("CGI::start_form"); # <html>$B%?%0$J$I$N=PNO(B.

# $B%Q%i%a!<%?$NM-L5(B.
my @keys = $q->param; # $B%-!<G[Ns$,JV$C$F$/$k(B.
if (@keys == 0){ # $B=i2s%"%/%;%9(B.
  print $q->start_form; # <form>$B%?%0$N=PNO(B.
  print "\n"; # $B2~9T$N=PNO(B.
  print "<input name=\"key1\" value=\"value1\">\n"; # key1
  print "<input name=\"key2\" value=\"value2\">\n"; # key2
  print "<input type=\"submit\" value=\"submit\">\n"; # submit
  print "</form>"; # </form>$B%?%0$N=PNO(B.
}
else{ # $B%j%/%(%9%H8e(B.
  my $i = 0; # $i$B$r(B0$B$G=i4|2=(B.
  while ($i < @keys){ # $B%Q%i%a!<%??tL$K~$N4V7+$jJV$9(B.
    print $keys[$i]." = ".$q->param($keys[$i]); # $i$BHVL\$N%-!<$H(B, $i$BHVL\$NCM$r=PNO(B.
    if ($i == @keys - 1){ # $B:G8e$N%Q%i%a!<%?(B.
      last; # $BH4$1$k(B.
    }
    else{ # $B:G8e$G$O$J$$(B.
      print "<br />\n"; # <br />$B$H2~9T$N=PNO(B.
    }
    $i++; # $i$B$N%$%s%/%j%a%s%H(B.
  } 
}

# HTML$B%U%C%?$N=PNO(B.
print $q->end_html; # </html>$B%?%0$J$I$N=PNO(B.

