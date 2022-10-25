<?php
echo"<h2>Pierwszy skrypt PHP</h2>";
$n=4567;
$x=10.123456789;

printf("%.2f", $x);






function galeria($rows, $cols)
{
    echo"<h2>Galeria zdjec</h2>";
    $tresc = '<table id="tabela">';
    $nazwa = 'obraz1';
    for($i = 0; $i < $rows; $i++)
    {
        $tresc .= '<tr>';
        for($j = 0; $j < $cols; $j++)
        {
            $tresc .= '<td>';
            $tresc .= "<img src='obrazki/$nazwa.jpg' alt='$nazwa' />";
            $tresc .= '</td>';
        }
        $tresc .= '</tr>';
        $tresc .= '</br>';
    }
    $tresc .= '</table>';
    printf($tresc);
}
//galeria(3,3);


function typy()
{
    $a = 1234;
    $b = 567.789;
    $c = 1;
    $d = 0;
    $e = true;
    $f = "0";
    $g = "Typy w PHP";
    $h = [1, 2, 3, 4];
    $i = [];
    $j = ["zielony", "czerwony", "niebieski"];
    $k = ["Agata", "Agatowska", 4.67, true];
    echo '</br>';
    for($i = 0; $i < count($h); $i++)
        printf($h[$i]);

    echo '</br>';
    print(is_numeric($a));
}

typy();

?>