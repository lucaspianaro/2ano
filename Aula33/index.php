<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Aula33</title>
  </head>
  <body>
    <?php
      require_once 'Caneta.php';
      $c1 = new Caneta;
      $c1->modelo = "BIC Crystal";
      $c1->cor = "Azul";
      //$c1->ponta = 0.5;
      //$c1->carga = 99;
      //$c1->tampada = true;
      $c1->rabiscar();
      $c1->destampar();
      print_r($c1);
     ?>
  </body>
</html>