<html>
  <head>
    <title>class</title>
  </head>
  <body>
    <?php
      class CustomClass{
        public $str;
      }
      $obj = new CustomClass();
      $obj->$str = "ABC";
      echo $obj->$str;
      echo "\n";
    ?>
  </body>
</html>
