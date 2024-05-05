#!/bin/bash

read -p "Username : " username
read -p "Password : " user_password

file_path="../resources/data-pkm.csv"
log_file="log.txt"

logger() {
    echo "$(date +"%y/%m/%d %H:%M:%S") $1" >> "$log_file"
}

scrap() {
    if [ -f "$file_path" ]; then
        match=0
        while IFS=',' read -r no nama_pengusul departemen fakultas judul pendamping skema; do
            nama_depan=$(echo "$nama_pengusul" | cut -d '_' -f1)
            if [ "$nama_depan" == "$username" ]; then
                nipd_dosen=$(echo "$pendamping" | awk -F '[()]' '{print $2}')
                password="${fakultas}${nipd_dosen}"
                if [ "$user_password" == "$password" ]; then
                    echo "Login Berhasil!"
                    logger "LOGIN: SUCCESS $username is logged in"
                else
                    echo "Login Gagal! Password Salah."
                    logger "LOGIN: ERROR Failed login attempt on $username"
                fi
                match=1
                break
            fi
        done < "$file_path"
        if [ "$match" -eq 0 ]; then
            echo "Login Gagal! Username Tidak Ditemukan."
            logger "LOGIN: ERROR Failed login attempt on $username"
        fi
    else
        echo "Login Gagal! File CSV Tidak Ditemukan."
    fi
}

scrap
