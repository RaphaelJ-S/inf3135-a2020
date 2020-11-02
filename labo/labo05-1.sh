#!/bin/bash
fichier=labo05-1.txt
compt=0
echo -ne "Rang,Nom,Pays,Population\r\n----,---,----,----------\r\n" > tmpLab05-1.txt
pres=""
while IFS= read -r ligne
do
  compt=$(expr $compt + 1)
  if [ $compt -lt 10 ]
  then
    pres=000$compt
  elif [ $compt -lt 100 ]
  then
    pres=00$compt
  elif [ $compt -lt 1000 ]
  then
    pres=0$compt
  else
    pres=$compt
  fi
    
  pres="$pres,$ligne\r\n"
  echo -ne "$pres" >> tmpLab05-1.txt
done < $fichier 
column -t -s, tmpLab05-1.txt
