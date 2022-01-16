<html>
  <head>
    <title>class#self</title>
  </head>
  <body>
    <?php
      class TestClass{
        const TEN = 10;
        public static $num = 100;
        public static function static_func1(){
          echo "func1";
          echo "<br />";
          self::static_func2();
        }
        public static function static_func2(){
          echo "func2";
          echo "<br />";
          echo "TEN = " + self::TEN;
          echo "<br />";
          echo "num = " + self::$num;
        }
      }
      TestClass::static_func1();
    ?>
  </body>
</html>
