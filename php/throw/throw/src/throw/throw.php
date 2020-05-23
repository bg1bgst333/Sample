<html>
  <head>
    <title>throw</title>
  </head>
  <body>
    <?php
      function func($x, $y){
        if ($y == 0){
          throw new Exception("divided by zero!");
        }
        return $x / $y;
      }
      try{
        $ret = func(6, 0);
      }
      catch(Exception $e){
        echo $e->getMessage();
      }
      echo "$ret\n";
    ?>
  </body>
</html>
