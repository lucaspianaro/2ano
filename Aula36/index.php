<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Aula 36</title>
  </head>
  <body>
    <pre>
      <?php
        echo "<h1>Projeto Controle Remoto</h1>";
        require_once 'ControleRemoto.php';
        $c = new ControleRemoto();

        $c->ligar();
        $c->maisVolume();
        $c->abrirMenu();
       ?>
     </pre>
  </body>
</html>