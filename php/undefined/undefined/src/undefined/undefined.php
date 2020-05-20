<html>
  <head>
    <title>undefined</title>
  </head>
  <body>
    <?php
      $var = "abc";
      unset($var);
      if (!isset($var) && is_null($var) && empty($var)){
        echo "$var\n";
        echo "undefined!";
      }
    ?>
  </body>
</html>
