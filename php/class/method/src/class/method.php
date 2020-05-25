<html>
  <head>
    <title>method</title>
  </head>
  <body>
    <?php
      class CustomClass{
        function method(){
          echo "ABC\n";
        }
      }
      $obj = new CustomClass();
      $obj->method();
    ?>
  </body>
</html>
