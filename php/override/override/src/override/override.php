<html>
  <head>
    <title>override</title>
  </head>
  <body>
    <?php
      class BaseClass{
        function func(){
	  echo "AAA\n";
	}
      }
      class DerivedClass{
	function func(){
	  echo "BBB\n";
	}
      }
      $obj = new DerivedClass();
      $obj->func();
    ?>
  </body>
</html>
