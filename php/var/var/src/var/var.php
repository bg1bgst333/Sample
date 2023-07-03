<html>
  <head>
    <title>var</title>
  </head>
  <body>
    <?php
      class RootClass{
        function func1(){
          echo "RootClass";
          echo "<br />";
          echo $this->var1;
          echo "<br />";
        }
      }
      class BaseClass extends RootClass{
        var $var1 = "var1";
        function func2(){
          echo "BaseClass";
          echo "<br />";
          echo $this->var1;
          echo "<br />";
        }
      }
      class DerivedClass extends BaseClass{
        function func3(){
          echo "DerivedClass";
          echo "<br />";
          echo $this->var1;
          echo "<br />";
        }
      }
      $d = new DerivedClass();
      $d->func1();
      $d->func2();
      $d->func3();
    ?>
  </body>
</html>
