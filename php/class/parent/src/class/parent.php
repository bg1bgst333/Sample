<html>
  <head>
    <title>class#parent</title>
  </head>
  <body>
    <?php
      class BaseClass{
        public function func1(){
          echo "BaseClass::func1()";
          echo "<br />";
        }
      }
      class DerivedClass extends BaseClass{
        public function func1(){
          parent::func1();
          echo "DerivedClass::func1()";
          echo "<br />";
        }
      }
      $d = new DerivedClass();
      $d->func1();
    ?>
  </body>
</html>
