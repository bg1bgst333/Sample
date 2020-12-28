<html>
  <head>
    <title>class#this</title>
  </head>
  <body>
    <?php
      $a = 10;
      class TestClass{
        public $a = 30;
        function func($a){
          echo "argument_a = " + $a;
          echo "member_a = " + $this->a;
          $this->a = $a;
        }
      }
      echo $a;
      $obj = new TestClass();
      $obj->func(20);
      echo "<br />";
      echo $a;
      $obj->func(50);
    ?>
  </body>
</html>
