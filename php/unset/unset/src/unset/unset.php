<html>
  <head>
    <title>unset</title>
  </head>
  <body>
    <?php
      $var = "abc";
      echo '$var = ';
      echo $var;
      echo "<br/>";
      unset($var);
      echo '$var = ';
      echo $var;
    ?>
  </body>
</html>
