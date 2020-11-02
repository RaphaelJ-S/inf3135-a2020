#!/bin/bash

if [ $# -ne 2 ] ; then
  exit 1
else
  if [ $1 == "nouveau" ] && [ $2 == "projet" ] ; then
    cd && mkdir Depot_$1_$2 && cd Depot_$1_$2 && git init
  fi
fi

