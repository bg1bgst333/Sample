<html>
  <head>
    <title>static_property</title>
  </head>
  <body>
    <?php
      class CustomClass{
        static $str = "ABC";
      }
      echo CustomClass::$str;
      echo "\n";
    ?>
  </body>
</html>
