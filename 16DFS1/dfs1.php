<?php
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

// $N: the total number of nodes in the level, including the gateways
// $L: the number of links
// $E: the number of exit gateways
fscanf(STDIN, "%d %d %d", $N, $L, $E);

error_log(var_export("expect 3 $N expect 2 $L expect 1 $E", true));
/*
first example 3 nodes
*/
$edges = [];
for ($i = 0; $i < $L; $i++)
{

    // $N1: N1 and N2 defines a link between these nodes
    fscanf(STDIN, "%d %d", $N1, $N2);
    
}
$gateways = [];
for ($i = 0; $i < $E; $i++)
{
    // $EI: the index of a gateway node
    fscanf(STDIN, "%d", $EI);
    array_push($gateways,$EI);
}

error_log(print_r($gateways, true));

// game loop
while (TRUE)
{
    // $SI: The index of the node on which the Bobnet agent is positioned this turn
    fscanf(STDIN, "%d", $SI);

    // Write an action using echo(). DON'T FORGET THE TRAILING \n
    // To debug: error_log(var_export($var, true)); (equivalent to var_dump)


    // Example: 0 1 are the indices of the nodes you wish to sever the link between
    echo("0 1\n");
}
?>