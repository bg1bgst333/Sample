<html>
  <head>
    <title>protected</title>
  </head>
  <body>
    <?php
      class RootClass{
        function func1(){
          echo "[RootClass]";
          echo "<br />";
          echo $this->var1;
          echo "<br />";
          echo $this->private1; // 呼べるが表示されない.
          echo "<br />";
          //echo $this->privatefunc(); // 呼べるが以降実行されない.
          //echo "<br />";
          echo $this->protected1;
          echo "<br />";
          echo $this->protectedfunc();
          echo "<br />";
        }
      }
      class BaseClass extends RootClass{
        var $var1 = "var1";
        private $private1 = "private1";
        protected $protected1 = "protected1";
        function func2(){
          echo "[BaseClass]";
          echo "<br />";
          echo $this->var1;
          echo "<br />";
          echo $this->private1;
          echo "<br />";
          echo $this->privatefunc();
          echo "<br />";
          echo $this->protected1;
          echo "<br />";
          echo $this->protectedfunc();
          echo "<br />";
        }
        private function privatefunc(){
           echo "[BaseClass#privatefunc]";
           echo "<br />";
        }
        protected function protectedfunc(){
           echo "[BaseClass#protectedfunc]";
           echo "<br />";
        }
      }
      class DerivedClass extends BaseClass{
        function func3(){
          echo "[DerivedClass]";
          echo "<br />";
          echo $this->var1;
          echo "<br />";
          echo $this->private1; // 呼べるが表示されない.
          echo "<br />";
          //echo $this->privatefunc(); // 呼べるが以降実行されない.
          //echo "<br />";
          echo $this->protected1;
          echo "<br />";
          echo $this->protectedfunc();
          echo "<br />";
        }
      }
      $d = new DerivedClass();
      $d->func1();
      $d->func2();
      $d->func3();
      echo '[$d->var1]';
      echo "<br />";
      echo $d->var1;
      echo "<br />";
      echo '[$d->private1]';
      echo "<br />";
      echo $d->private1; // 呼べるが表示されない.
      echo "<br />";
      $r = new RootClass();
      echo '[$r->privatefunc()]';
      echo "<br />";
      //echo $r->privatefunc(); // 呼べるが以降実行されない.
      echo "<br />";
      $b = new BaseClass();
      echo '[$b->privatefunc()]';
      echo "<br />";
      //echo $b->privatefunc(); // 呼べるが以降実行されない.
      echo "<br />";
      echo '[$d->privatefunc()]';
      echo "<br />";
      //echo $d->privatefunc(); // 呼べるが以降実行されない.
      echo "<br />";
      echo '[$d->protected1]';
      echo "<br />";
      //echo $d->protected1; // 呼べるが以降表示されない.
      echo "<br />";
      echo '[$r->protectedfunc()]';
      echo "<br />";
      //echo $r->protectedfunc(); // 呼べるが以降実行されない.
      echo "<br />";
      echo '[$b->protectedfunc()]';
      echo "<br />";
      //echo $b->protectedfunc(); // 呼べるが以降実行されない.
      echo "<br />";
      echo '[$d->protectedfunc()]';
      echo "<br />";
      //echo $d->protectedfunc(); // 呼べるが以降実行されない.
    ?>
  </body>
</html>
