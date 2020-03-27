#!/usr/bin/env bash

test $# -eq 4 || { echo "Usage: `basename $0` nbRepetition tailleMax min max" 1>&2
                   exit 1; }

rep=$1
tailleMax=$2
min=$3
max=$4

echo -e "iTest\ttaille\tmin\tmax\tnom_tri\ttype_tab\ttemps\tmem"

for iTest in `seq 1 $rep`
do
  taille=$((`od -An -N4 -tu < /dev/urandom` % $tailleMax ))
  for nom_tri in 'f' 'r' 'x'
  do
    for type_tab in 'a' 'd' 'c'
    do
      (res=`( /usr/bin/time -f "%U\t%M" ./main $nom_tri $taille $type_tab $min $max > /dev/null ) 2>&1`
      echo -e "$iTest\t$taille\t$min\t$max\t$nom_tri\t$type_tab\t$res") &
    done
  done
done
