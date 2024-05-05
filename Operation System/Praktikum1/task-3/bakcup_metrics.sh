#!/bin/bash

# Mendapatkan tanggal dan jam saat ini dalam format YmdH
current_datetime=$(date "+%Y%m%d%H")

# Nama file untuk menyimpan semua log metrics aggregasi dalam satu file .gz
backup_file="backup_metrics_${current_datetime}.gz"

# Pola nama file log yang ingin Anda agregasikan
file_pattern="/home/anonymous/metrics/metrics_agg_${current_datetime:0:8}*.log" #0:8 artinya ambil 8 huruf pertama

# Mendapatkan direktori log
log_dir="/home/anonymous/metrics"

# Menggabungkan semua file log yang cocok dengan pola ke dalam satu file
cat $file_pattern | gzip > "$log_dir/$backup_file"

echo "Logs aggregated and saved to $log_dir/$backup_file"
