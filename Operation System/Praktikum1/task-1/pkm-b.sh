#!bin/bash

echo "Bidang yang paling banyak diminati:"
awk -F'\t' '{
hitung[$7]++} END {
for(j in hitung) print hitung[j],j
}' DataPKM.tsv |
sort -nr |
head -1 |
awk '{print $2}'
