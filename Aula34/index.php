<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Aula 34</title>
  </head>
  <body>
    <?php
    require_once 'Caneta.php';

    $c1 = new Caneta ("BIC", "Azul", 0.5);
    $c2 = new Caneta ("KKK", "Verde", 1.0);

    print_r($c1);
    print_r($c2);
     ?>
  </body>
</html>