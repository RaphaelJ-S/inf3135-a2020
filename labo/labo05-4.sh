#!/bin/bash

if [ $# -eq 0 ] ; then
  exit 10
fi
ecrire()
{
  resultat=0
  comp=1
  for car in $* ; do
    while read -n1 c; do
      compteur=1
      pres=""
      while [ $compteur -lt $comp ] ; do
        echo -ne ' '
        compteur=$((compteur+1))
        
      done
      echo $pres$c
      comp=$(($comp+1))
      resultat=$((resultat+1))
    done < <(echo -n "$car")
    comp=$((comp+1))
    echo ' '
  done
  resultat=$((resultat+($#-1)))
  return $resultat
} 

ecrire $*
code_retn=$?
echo $code_retn

exit $code_retn
