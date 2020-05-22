<html>
  <head>
    <title>list</title>
  </head>
  <body>
    <?php
      function func(){
        return array('aaa', 'bbb', 'ccc');
      }
      list($a, $b, $c) = func();
      echo "$a<br />\n";
      echo "$b<br />\n";
      echo "$c<br />\n";
    ?>
  </body>
</html>
