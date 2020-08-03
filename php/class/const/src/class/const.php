<html>
  <head>
    <title>class#const</title>
  </head>
  <body>
    <?php
      class TestClass{
        const NUM = 10;
      }
      //TestClass::NUM = 20;
      echo TestClass::NUM;
    ?>
  </body>
</html>
