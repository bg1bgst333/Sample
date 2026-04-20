<html>
  <head>
    <title>class#final</title>
  </head>
  <body>
    <?php
      class BaseClass{
        final public function func(){
	  echo "AAA\n";
	}
      }
      class DerivedClass extends BaseClass{
	/*
	public function func(){
	  echo "BBB\n";
	}
	*/
      }
      $obj = new DerivedClass();
      $obj->func();
    ?>
  </body>
</html>
