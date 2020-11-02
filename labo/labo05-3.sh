#!/bin/bash

valider_args() 
{
  if [ $1 -lt -10000 -a $1 -gt 10000 ] ; then
    return 4
    if [ $2 != "+" -o $2 != "-" -o $2 != "/" -o $2 != "*" ] ; then
      return 5 
      if [ $1 -lt -10000 -a $1 -gt 10000 ] ; then
         return 6 
      fi
    fi
  fi
  return 0
}

if [ $# -eq 3 ] ; then
  valider_args $1 $2 $3
  if [ $? -ne 0 ] ; then
    exit -1
  else 
    echo "Tous les paramètre sont valides"
    
    resultat=$(($1$2$3))
    echo "$1 $2 $3 = $resultat"
    echo "le resultat est : $resultat" 2>
  fi
else
  exit 1
fi  



