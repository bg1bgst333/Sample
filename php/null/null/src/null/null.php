<html>
  <head>
    <title>null</title>
  </head>
  <body>
    <?php
      $var = null;
      if (!isset($var) && is_null($var) && empty($var)){
        echo "null!";
      }
    ?>
  </body>
</html>
