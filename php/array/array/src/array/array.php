<html>
  <head>
    <title>array</title>
  </head>
  <body>
    <?php
      $ary = array('aaa', 'bbb', 'ccc');
      echo "$ary[0], $ary[1], $ary[2]<br />\n";
      $ary[1] = 'ddd';
      echo "$ary[0], $ary[1], $ary[2]<br />\n";
      $var = $ary[2];
      echo "$var<br />\n"
    ?>
  </body>
</html>
