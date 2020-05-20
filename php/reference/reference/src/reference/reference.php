<html>
  <head>
    <title>reference</title>
  </head>
  <body>
    <?php
      $var = "ABC";
      $ref = &$var;
      $ref = "XYZ";
      echo "$ref\n";
      echo "$var\n";
    ?>
  </body>
</html>
