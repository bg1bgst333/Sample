<html>
  <head>
    <title>static_method</title>
  </head>
  <body>
    <?php
      class CustomClass{
        static function method(){
          echo "ABC<br />\n";
        }
      }
      CustomClass::method();
    ?>
  </body>
</html>
