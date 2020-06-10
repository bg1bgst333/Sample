<html>
  <head>
    <title>new</title>
  </head>
  <body>
    <?php
      class CustomClass{
        public $str;
        public function method(){
          echo "XYZ<br />\n";
        }
      }
      $obj = new CustomClass();
      $obj->$str = "ABC<br />";
      echo $obj->$str;
      echo "\n";
      $obj->method();
    ?>
  </body>
</html>
