#!/bin/bash

act=$1
mingyu="https://cdn.idntimes.com/content-images/community/2020/09/d0494a15-67dc-408e-9ba8-c1398b6c7877-5fd1838e18152d2676bf01ac045c1d7b.jpg"
levi="https://cdn1-production-images-kly.akamaized.net/4qA2byH-SS1qZt3iPZq8Vb2_86Q=/1280x720/smart/filters:quality(75):strip_icc():format(webp)/kly-media-production/medias/4244869/original/051747100_1669794079-HL_hafidz.levi.jpg"
eren="https://posterwa.com/cdn/shop/files/AOT342.jpg?v=1686078600"

download() {
    loop_gambar=0
    for ((a=0; a<$1; a++)); do
        ((loop_gambar++))
        wget "$mingyu" -O "$2/foto_$loop_gambar.jpg"
    done
}

if [ "$act" == 1 ]; then

    time_=$(date +'%-H')
    loop_folder=1

    path="./folder_$loop_folder"
    while [ -d "$path" ]; do
        ((loop_folder++))
        path="./folder_$loop_folder"
    done
    mkdir -p "$path"

    if [ "$time_" -eq "00" ]; then
        download 10 "$path"
    elif [ "$((time_%2))" -eq 0 ]; then
        download 5 "$path"
    else
        download 3 "$path"
    fi

elif [ "$act" = 2 ]; then
    loop_zip=1
    file_zip="./ayang_$loop_zip.zip"

    while [ -e "$file_zip" ]; do
        ((loop_zip++))
        file_zip="./ayang_$loop_zip.zip"
    done

    cd ./
    zip -r "ayang_$loop_zip.zip" folder_*

elif [ "$act" = 3 ]; then
    rm -rf ./folder_*
    rm -rf ./ayang_*

elif [ "$act" = 4 ]; then
    date_=$(date +'%Y%m%d')
    tanggal=$(date +'%d')
    path="./AttackOnTitan"

    if [ ! -d "$path" ]; then
        mkdir -p "$path"
    fi

    if [ "$((tanggal%2))" -eq 0 ]; then
        wget "$levi" -O "$path/levi_$date_.jpg"
    else
        wget "$eren" -O "$path/eren_$date_.jpg"
    fi

else
    echo "Kesalahan. Gunakan 1 diantara syntax berikut"
    echo "./isabel.sh 1 --> Download Foto Mingyu"
    echo "./isabel.sh 2 --> Zip File"
    echo "./isabel.sh 3 --> Menghapus Semua Folder & Zip"
    echo "./isabel.sh 4 --> Download Gambar Levi & Eren"
    exit 1

fi
