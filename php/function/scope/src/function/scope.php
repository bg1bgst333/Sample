<html>
  <head>
    <title>scope</title>
  </head>
  <body>
    <?php
    $var = 'ABC';
    func();
    echo "out: $var\n";
    function func(){
      $var = 'XYZ';
      echo "in: $var\n";
    }
    ?>
  </body>
</html>
