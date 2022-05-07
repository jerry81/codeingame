<?php
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

// $N: the total number of nodes in the level, including the gateways
// $L: the number of links
// $E: the number of exit gateways
fscanf(STDIN, "%d %d %d", $N, $L, $E);


$neighbors = [];
for ($i = 0; $i < $N; $i++)
{
    array_push($neighbors, []);
}
/*
first example 3 nodes
*/
$edges = [];
for ($i = 0; $i < $L; $i++)
{
    // $N1: N1 and N2 defines a link between these nodes
    fscanf(STDIN, "%d %d", $N1, $N2);
    array_push($edges, [$N1, $N2]);
    array_push($neighbors[$N1], $N2);
    array_push($neighbors[$N2], $N1);
}
error_log(print_r($edges, true));
$gateways = [];
for ($i = 0; $i < $E; $i++)
{
    // $EI: the index of a gateway node
    fscanf(STDIN, "%d", $EI);
    array_push($gateways,$EI);
}

error_log(print_r($gateways, true));

error_log(print_r("neighbors", true));
error_log(print_r($neighbors, true));

// build map of neighbors 
// init the map 

function popNeighbor($a,$b, $neighbors) {
  unset($neighbors[$a][array_search($b, $neighbors[$a])]);
  unset($neighbors[$b][array_search($a, $neighbors[$b])]);
  return $neighbors;
}
// game loop
while (TRUE)
{
    // $SI: The index of the node on which the Bobnet agent is positioned this turn
    fscanf(STDIN, "%d", $SI);
    // first handle single gateway case
    if (count($gateways) == 1) {
        $g = $gateways[0];
        $ns = $neighbors[$g];
        if (count($ns) == 1) {
            echo($g." ".$ns[0]."\n");
            $newNeighbors = popNeighbor($g, $ns[0], $neighbors);
            error_log(print_r("neighbors is now\n", true));
            error_log(print_r($newNeighbors, true));
        } else {
            $idx = array_search($SI, $ns);
            if ($idx === false) {
                $idx = 0;
            }
            echo($g." ".$ns[$idx]."\n");
            $newNeighbors = popNeighbor($g, $ns[$idx], $neighbors);
        }
    }
    // Write an action using echo(). DON'T FORGET THE TRAILING \n
    // To debug: error_log(var_export($var, true)); (equivalent to var_dump)


    // Example: 0 1 are the indices of the nodes you wish to sever the link between
}
?>