#!/bin/bash

Q1:
man printf | head -n 20 > resultats/resultats05-2-1.txt 

Q2:
curl https://githup.com/guyfrancoeur/INF3135_A2020/blob/master/labo/atelier-05.md | grep "chaine" > resultats/resultats05-2-2.txt

Q3:
git log | grep Author: | uniq | sort

Q4:
git log | grep Author: | sed 's/Author: //' | sed 's/ <.*>//' | uniq | sort

