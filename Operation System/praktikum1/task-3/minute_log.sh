#!/bin/bash

# Function to monitor RAM and directory size
monitor_metrics() {
    # RAM metrics
    #mengambil nilai" metrics dengan perintah free -m
    ram_metrics=$(free -m | awk 'NR==2 {
    total_ram=$2;              # Nilai kolom kedua adalah Total RAM
    used_ram=$3;               # Nilai kolom ketiga adalah RAM yang digunakan
    free_ram=$4;               # Nilai kolom keempat adalah RAM yang tersedia atau bebas
    shared_ram=$5;             # Nilai kolom kelima adalah RAM yang digunakan untuk alokasi memori bersama
    buffer_ram=$6;             # Nilai kolom keenam adalah RAM yang digunakan untuk buffering data
    available_ram=$7;          # Nilai kolom ketujuh adalah RAM yang tersedia untuk penggunaan, termasuk yang bebas dan yang digunakan untuk buffering

    # Menggabungkan nilai-nilai di atas dalam satu string yang dipisahkan dengan koma (,)
    print total_ram "," used_ram "," free_ram "," shared_ram "," buffer_ram "," available_ram
    }')

    # mengambil swap metrics
    swap_metrics=$(free -m | awk 'NR==3 {
    swap_total=$2;      # Nilai kolom kedua adalah Total Swap
    swap_used=$3;       # Nilai kolom ketiga adalah Swap yang digunakan
    swap_free=$4;       # Nilai kolom keempat adalah Swap yang tersedia atau bebas

    # Menggabungkan nilai-nilai di atas dalam satu string yang dipisahkan dengan koma (,)
    print swap_total "," swap_used "," swap_free
    }')

    # Directory size metrics
    directory_path="/home/anonymous"                                #directory yang akan di cek sizenya
    directory_size=$(du -sh $directory_path | awk '{print $1}')     #cek size dengan du -sh <path>
    
    # Write metrics to log file
    echo "mem_total,mem_used,mem_free,mem_shared,mem_buff,mem_available,swap_total,swap_used,swap_free,path,path_size" >> /home/anonymous/metrics/metrics_$(date "+%Y%m%d%H%M%S").log
    echo "$ram_metrics, $swap_metrics, $directory_path, $directory_size" >> /home/anonymous/metrics/metrics_$(date "+%Y%m%d%H%M%S").log
}

# Main function
main() {
    monitor_metrics
}

main
