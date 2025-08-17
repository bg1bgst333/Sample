<html>
  <head>
    <title>__construct</title>
  </head>
  <body>
    <?php
      class CustomClass{
        function __construct(){
          echo "[CustomClass#__construct]<br/>";
        }
      }
      class DerivedClass extends CustomClass{
        function __construct(){
          parent::__construct();
          echo "[DerivedClass#__construct]<br/>\n";
        }
      }
      $dc = new DerivedClass();
    ?>
  </body>
</html>
