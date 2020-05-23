<html>
  <head>
    <title>anonymous_functions</title>
  </head>
  <body>
    <?php
      $anonymous = function(){
        return 'ABC';
      };
      func($anonymous);
      function func($ref){
        echo "func start<br />\n";
        $var = $ref();
        echo "$var<br />\n";
        echo "func end<br />\n";
      }
    ?>
  </body>
</html>
