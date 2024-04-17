#!bin/bash

echo "Tim yang judul proposalnya lebih dari 20 kata:"
awk -F'\t' '{
if(NR>1) {
gsub("_", " ", $2)
if(split($5, words, " ")>20) print $2" "$3
}
}' DataPKM.tsv
