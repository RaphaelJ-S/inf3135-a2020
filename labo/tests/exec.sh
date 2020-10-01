#!/bin/bash

./exec > result
grep "Réussite" result
