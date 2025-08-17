<html>
  <head>
    <title>__destruct</title>
  </head>
  <body>
    <?php
      class CustomClass{
        function __construct(){
          echo "[CustomClass#__construct]<br />";
        }
        function __destruct(){
          echo "[CustomClass#__destruct]<br />";
        }
      }
      $cc = new CustomClass();
      echo "-----<br />";
      unset($cc);
    ?>
  </body>
</html>
