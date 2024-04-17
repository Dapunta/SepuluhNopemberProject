#!/bin/bash

file_path="../resources/data-pkm.csv"
log_file="log.txt"

checkUsername() {
    local nama_pengusul="$1"
    if grep -q ",${nama_pengusul}," $file_path; then
        echo "Registrasi Gagal! Username Sudah Ada."
        logger "REGISTER: ERROR $nama_pengusul is already existed"
        exit 1
    fi
}

showError() {
    echo "$1 Tidak Boleh Kosong"
    exit 1
}

addToCSV() {
    local username="$1"
    local proposal_number="$2"
    local new_line="$3"
    echo -n "$new_line" >> "$file_path"
    echo "Registrasi Berhasil"
    logger "REGISTER: SUCCESS $username is registered. Proposal $proposal_number is added"
}

logger() {
    echo "$(date +"%y/%m/%d %H:%M:%S") $1" >> "$log_file"
}

input() {

    read -p "Nama Pengusul     : " nama_pengusul
    if [[ "$nama_pengusul" == *" "* ]]; then
        echo "Username Tidak Boleh Menggunakan Spasi, Gunakan (_)"
        exit 1
    fi

    checkUsername "$nama_pengusul"

    read -p "Asal Departemen   : " departemen
    if [[ "$departemen" == "" ]]; then
        showError "Asal Departemen"
    fi

    read -p "Fakultas          : " fakultas
    if [[ "$fakultas" == "" ]]; then
        showError "Fakultas"
    fi

    read -p "Judul Proposal    : " judul
    if [[ "$judul" == "" ]]; then
        showError "Judul Proposal"
    fi

    read -p "Pendamping (NIDN) : " pendamping
    if [[ "$pendamping" == "" ]]; then
        showError "Pendamping"
    fi

    read -p "Skema PKM         : " skema
    if [[ "$skema" == "" ]]; then
        showError "Skema PKM"
    fi

    proposal_number="$(( $(wc -l < $file_path) + 1))"
    new_line=$(printf "\n%s,%s,%s,%s,%s,%s,%s" "$proposal_number" "$nama_pengusul" "$departemen" "$fakultas" "$judul" "$pendamping" "$skema")
    addToCSV "$nama_pengusul" "$proposal_number" "$new_line"
}

input
