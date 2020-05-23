<html>
  <head>
    <title>global</title>
  </head>
  <body>
    <?php
    $var = 'ABC';
    func();
    echo "out: $var\n";
    function func(){
      global $var;
      $var = 'XYZ';
      echo "in: $var\n";
    }
    ?>
  </body>
</html>
