<html>
  <head>
    <title>call_by_reference</title>
  </head>
  <body>
    <?php
      $var = "ABC";
      echo "$var\n";
      func($var);
      echo "$var\n";
      function func(&$ref){
        $ref = "XYZ";
      }
    ?>
  </body>
</html>
