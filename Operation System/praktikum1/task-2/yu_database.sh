#!/bin/bash

file_path="../resources/data-pkm.csv"
result="users.txt"

scrap() {
    echo -n "No,Username,Password" > "$result"
    while IFS=',' read -r no nama_pengusul departemen fakultas judul pendamping skema; do
        if [[ "$no" =~ ^[0-9]+$ ]]; then
            username=$(echo "$nama_pengusul" | cut -d '_' -f1)
            nipd_dosen=$(echo "$pendamping" | awk -F '[()]' '{print $2}')
            password="${fakultas}${nipd_dosen}"
            new=$(printf "\n%s,%s,%s" "$no" "$username" "$password")
            echo -n "$new" >> "$result"
        fi
    done < "$file_path"
    lastLineHandling
}

lastLineHandling() {
    last_line=$(tail -n 1 "$file_path")
    IFS=',' read -r no nama_pengusul departemen fakultas judul pendamping skema <<< "$last_line"
    username=$(echo "$nama_pengusul" | cut -d '_' -f1)
    nipd_dosen=$(echo "$pendamping" | awk -F '[()]' '{print $2}')
    password="${fakultas}${nipd_dosen}"
    new=$(printf "\n%s,%s,%s" "$no" "$username" "$password")
    echo -n "$new" >> "$result"
}

scrap
