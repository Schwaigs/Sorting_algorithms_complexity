#!/usr/bin/env bash

test $# -eq 6 || { echo "Usage: `basename $0` nbRepetition tailleMax min max firsttype secondtype" 1>&2
                   exit 1; }

rep=$1
tailleMax=$2
min=$3
max=$4
ftype=$5
stype=$6



echo -e "iTest\ttaille\tmin\tmax\tnom_tri\ttype_tab\tindexChange\tpremierType\tdeuximeType\ttemps\tmem"

for iTest in `seq 1 $rep`
do
  taille=$(($((`od -An -N4 -tu < /dev/urandom` % $(($tailleMax-4)) )) + 4 ))
  change=$((`od -An -N4 -tu < /dev/urandom` % $(($taille-2))))
  change=$(($change + 1))
  for nom_tri in 'f'
  do
    for type_tab in 'm'
    do
      res=`( /usr/bin/time -f "%U\t%M" ./main $nom_tri $taille $type_tab $min $max $ftype $stype $change > /dev/null ) 2>&1`
      echo -e "$iTest\t$taille\t$min\t$max\t$nom_tri\t$type_tab\t$change\t$ftype\t$stype\t$res"
    done
  done
done
