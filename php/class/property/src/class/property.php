<html>
  <head>
    <title>property</title>
  </head>
  <body>
    <?php
      class CustomClass{
        public $str;
        function method(){
          echo "ABC<br />\n";
        }
      }
      $obj = new CustomClass();
      $obj->$str = "XYZ";
      $obj->method();
      echo $obj->$str;
      echo "<br />\n";
    ?>
  </body>
</html>
