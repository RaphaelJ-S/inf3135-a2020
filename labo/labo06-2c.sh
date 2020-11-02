#!/bin/bash

avg() {
  in="$1"
  resultat=0
  while IFS= read -r ligne ; do
    while IFS= read -n1 car ; do
      intCar=$( printf "%d" "'${car}" )
      resultat=`expr $resultat + $intCar`
      
    done < <(echo -n "$ligne")
  done < "$in"
  echo $resultat 
}


if [ $# -eq 2 ] ; then
  avg $1
fi

