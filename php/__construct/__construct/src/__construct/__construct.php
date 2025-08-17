<html>
  <head>
    <title>__construct</title>
  </head>
  <body>
    <?php
      class CustomClass{
        function __construct(){
          echo "[CustomClass#__construct]";
        }
      }
      $cc = new CustomClass();
    ?>
  </body>
</html>
