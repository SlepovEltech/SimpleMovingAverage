#!/bin/bash

for i in 1 2 3 4 5; do
$1 | grep -e Perf | cut -f2 -d " " | tr . ,
done
