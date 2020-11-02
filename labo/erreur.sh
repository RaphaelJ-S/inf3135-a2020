#!/bin/bash
echo -ne "\nallo\n"

echo -ne "\nerreur\n" 2>&1
  
echo -ne "\nerreur2\n" >&2 
