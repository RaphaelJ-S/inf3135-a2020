#!/bin/sh

grep "passed" - | grep -o "valider\w*"
