#!bin/bash

echo "Mahasiswa yang mengajukan lebih dari 1 proposal:"
awk -F'\t' '{
hitung[$2]++;nama[$2]=nama[$2]" "$6} END {
for(i in hitung) if(hitung[i]>1) print i,nama[i]
}' DataPKM.tsv
