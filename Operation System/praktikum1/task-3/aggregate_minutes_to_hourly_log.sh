#!/bin/bash
#

# Mendapatkan waktu saat ini dalam format YmdH
current_hour=$(date "+%Y%m%d%H")

# Pola nama file log
file_pattern="/home/anonymous/metrics/metrics_$current_hour*.log"
# Mendapatkan direktori log
log_dir="/home/anonymous/metrics"

# Membuat file log untuk hasil agregasi
aggregate_log_file="$log_dir/metrics_agg_$current_hour.log"

# membuat file
touch $aggregate_log_file

jumlah_loop=0
#untuk rata"
mem_total=0
mem_used=0
mem_free=0
mem_shared=0
mem_buff=0
mem_available=0
swap_total=0
swap_used=0
swap_free=0

path_size=0

#untuk minimum
min_mem_total=0
min_mem_used=0
min_mem_free=0
min_mem_shared=0
min_mem_buff=0
min_mem_available=0
min_swap_total=0
min_swap_used=0
min_swap_free=0
min_path_size=0

#untuk maximum
max_mem_total=0
max_mem_used=0
max_mem_free=0
max_mem_shared=0
max_mem_buff=0
max_mem_available=0
max_swap_total=0
max_swap_used=0
max_path_size=0


# Loop melalui setiap file yang cocok dengan pola
for file in $file_pattern; do
    # Pastikan file yang ada adalah file reguler
    if [ -f "$file" ]; then
        # Baca baris kedua dari file log
        line=$(head -n 2 "$file" | tail -n 1)
        
        # Atur IFS ke koma
        IFS=',' read -ra data <<< "$line"

        # konversi path size dari 60m > 60
        path_size_number=$(echo "${data[10]}" | sed 's/[^0-9]*//g')

        # mencari rata-rata
        # tambah nilai loop
        jumlah_loop=$((jumlah_loop+1))
        # Simpan setiap elemen ke dalam variabel
        mem_total=$((mem_total + ${data[0]}))
        mem_used=$((mem_used + ${data[1]}))
        mem_free=$((mem_free + ${data[2]}))
        mem_shared=$((mem_shared + ${data[3]}))
        mem_buff=$((mem_buff + ${data[4]}))
        mem_available=$((mem_available + ${data[5]}))
        swap_total=$((swap_total + ${data[6]}))
        swap_used=$((swap_used + ${data[7]}))
        swap_free=$((swap_free + ${data[8]}))
        path_size=$((path_size + path_size_number))

        # ambil data pertama untuk di cek data selanjutnya (khusus minimal)
        if [ $jumlah_loop -eq 1 ]; then 
            min_mem_total=${data[0]}
            min_mem_used=${data[1]}
            min_mem_free=${data[2]}
            min_mem_shared=${data[3]}
            min_mem_buff=${data[4]}
            min_mem_available=${data[5]}
            min_swap_total=${data[6]}
            min_swap_used=${data[7]}
            min_swap_free=${data[8]}
            min_path_size=${path_size_number}
        fi

        # min max
        if (( ${data[0]} < min_mem_total )); then min_mem_total=${data[0]}; fi
        if (( ${data[0]} > max_mem_total )); then max_mem_total=${data[0]}; fi
        if (( ${data[1]} < min_mem_used )); then min_mem_used=${data[1]}; fi
        if (( ${data[1]} > max_mem_used )); then max_mem_used=${data[1]}; fi
        if (( ${data[2]} < min_mem_free )); then min_mem_free=${data[2]}; fi
        if (( ${data[2]} > max_mem_free )); then max_mem_free=${data[2]}; fi
        if (( ${data[3]} < min_mem_shared )); then min_mem_shared=${data[3]}; fi
        if (( ${data[3]} > max_mem_shared )); then max_mem_shared=${data[3]}; fi
        if (( ${data[4]} < min_mem_buff )); then min_mem_buff=${data[4]}; fi
        if (( ${data[4]} > max_mem_buff )); then max_mem_buff=${data[4]}; fi
        if (( ${data[5]} < min_mem_available )); then min_mem_available=${data[5]}; fi
        if (( ${data[5]} > max_mem_available )); then max_mem_available=${data[5]}; fi
        if (( ${data[6]} < min_swap_total )); then min_swap_total=${data[6]}; fi
        if (( ${data[6]} > max_swap_total )); then max_swap_total=${data[6]}; fi
        if (( ${data[7]} < min_swap_used )); then min_swap_used=${data[7]}; fi
        if (( ${data[7]} > max_swap_used )); then max_swap_used=${data[7]}; fi
        if (( ${data[8]} < min_swap_free )); then min_swap_free=${data[8]}; fi
        if (( ${data[8]} > max_swap_free )); then max_swap_free=${data[8]}; fi

        # Periksa apakah path_size_number lebih kecil dari min_path_size
        if (( path_size_number < min_path_size )); then
            min_path_size=$path_size_number
        fi

        # Periksa apakah path_size_number lebih besar dari max_path_size
        if (( path_size_number > max_path_size )); then
            max_path_size=$path_size_number
        fi
    fi
done


# hitung nilai rata"

# Fungsi untuk melakukan perhitungan float menggunakan awk
calc_float() {
    awk "BEGIN {printf \"%.2f\", $1}"
}

# Menghitung rata-rata dalam float
avg_mem_total=$(calc_float "$mem_total/$jumlah_loop")
avg_mem_used=$(calc_float "$mem_used/$jumlah_loop")
avg_mem_free=$(calc_float "$mem_free/$jumlah_loop")
avg_mem_shared=$(calc_float "$mem_shared/$jumlah_loop")
avg_mem_buff=$(calc_float "$mem_buff/$jumlah_loop")
avg_mem_available=$(calc_float "$mem_available/$jumlah_loop")
avg_swap_total=$(calc_float "$swap_total/$jumlah_loop")
avg_swap_used=$(calc_float "$swap_used/$jumlah_loop")
avg_swap_free=$(calc_float "$swap_free/$jumlah_loop")
avg_path_size=$(calc_float "$path_size/$jumlah_loop")

# tampilkan hasil rata"
echo "type,mem_total,mem_used,mem_free,mem_shared,mem_buff,mem_available,swap_total,swap_used,swap_free,path,path_size"  >> "$aggregate_log_file"
echo "Minimum,$min_mem_total,$min_mem_used,$min_mem_free,$min_mem_shared,$min_mem_buff,$min_mem_available,$min_swap_total,$min_swap_used,$min_swap_free,$log_dir,${min_path_size}M"  >> "$aggregate_log_file"
echo "Maximum,$max_mem_total,$max_mem_used,$max_mem_free,$max_mem_shared,$max_mem_buff,$max_mem_available,$max_swap_total,$max_swap_used,$max_swap_free,$log_dir,${max_path_size}M"  >> "$aggregate_log_file"
echo "Average,$avg_mem_total,$avg_mem_used,$avg_mem_free,$avg_mem_shared,$avg_mem_buff,$avg_mem_available,$avg_swap_total,$avg_swap_used,$avg_swap_free,$log_dir,${avg_path_size}M"  >> "$aggregate_log_file"


