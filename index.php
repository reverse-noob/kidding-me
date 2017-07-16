<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <title>Ambiente de Desenvolvimento - Ramos</title>
</head>


<body>

<div align="center">
    <form method="POST">
        <input type="text" name="usuario" />
        <br>
        <input type="password" name="senha" />
        <br>
        <input type="submit" />
    </form>

    <?php
    if(isset($_POST["senha"]) and isset($_POST["usuario"])){
        echo "<br/>Usuario: " . $_POST["usuario"];
        echo "<br/>Senha: " . $_POST["senha"];
    }
    ?>
</div>
</body>
</html>