## Magang Bubu _(Bubu's Internship)_

Bubu adalah seorang IT Support magang di PT. Pencari Cinta. Bubu diminta oleh atasannya untuk memonitor setiap server yang dimiliki oleh kantor. Karena Bubu sangat sibuk mengawal PKM, maka Bubu meminta kalian untuk membuatkan program monitoringnya.

_Bubu is an IT Support intern at PT Pencari Cinta. Bubu was asked by his boss to monitor every server owned by the office. Because Bubu is very busy working on his PKM proposal, Bubu asks you to make the monitoring programme._

Buatlah program monitoring resource pada setiap server. Cukup monitoring RAM dan monitoring size suatu directory. Untuk RAM gunakan command `free -m`. Untuk disk gunakan command `du -sh <target_path>`. Catat semua metrics yang didapatkan dari hasil `free -m`. Untuk hasil `du -sh <target_path>` catat size dari path directory tersebut. Untuk `target_path` yang akan dimonitor adalah `/home/{user}/`.

_Make a resource monitoring programme on each server. Simply monitor RAM and monitor the size of a directory. For RAM use the `free -m` command. For disc use the command `du -sh <target_path>`. Record all metrics obtained from the results of `free -m`. For the results of `du -sh <target_path>` note the size of the directory path. For the `target_path` to be monitored is `/home/{user}/`._

- a. Masukkan semua metrics ke dalam suatu file log bernama `metrics_{YmdHms}.log`. `{YmdHms}` adalah waktu disaat file script bash kalian dijalankan. Misal dijalankan pada 2024-03-30 15:00:00, maka file log yang akan tergenerate adalah `metrics_20240330150000.log`.

  <em>

  a. Put all metrics into a log file called `metrics_{YmdHms}.log`. `{YmdHms}` is the time when your bash script file was run. For example, run on 2024-03-30 15:00:00, then the log file that will be generated is `metrics_20240330150000.log`.

  </em>

- b. Script untuk mencatat metrics diatas diharapkan dapat berjalan otomatis setiap menit.

  _b. The script to log the above metrics is expected to run automatically every minute._

- c. Kemudian, buat satu script untuk membuat aggregasi file log ke satuan jam. Script aggregasi akan memiliki info dari file-file yang tergenerate tiap menit. Dalam hasil file aggregasi tersebut, terdapat nilai minimum, maximum, dan rata-rata dari tiap-tiap metrics. File aggregasi akan ditrigger untuk dijalankan setiap jam secara otomatis. Berikut contoh nama file hasil aggregasi `metrics_agg_2023033015.log` dengan format `metrics_agg_{YmdH}.log`.

  <em>

  c. Then, create a script to aggregate the log files to hourly units. The aggregation script will have info from the files that are generated every minute. In the aggregation file results, there are minimum, maximum, and average values of each metrics. The aggregation file will be triggered to run every hour automatically. The following is an example of the name of the aggregation result file `metrics_agg_2023033015.log` with the format `metrics_agg_{YmdH}.log`

  </em>

- d. Selanjutnya agar lebih menghemat penyimpan, buatlah script [backup_metrics.sh](./bakcup_metrics.sh). Dimana script ini akan menyimpan semua log metrics aggregasi mulai dari pukul 00:00 sampai 23:59 didalam 1 file .gz menggunakan gunzip. Contoh nama file hasil zip `backup_metrics_{date_YmdH}.gz`

  <em>

  d. Next, to save more storage, create a [backup_metrics.sh](./bakcup_metrics.sh) script. Where this script will save all aggregated metrics logs from 00:00 to 23:59 in 1 .gz file using gunzip. Example of the zip file name `backup_metircs_{date_YmdH}.gz`.

  </em>

- e. Karena file log bersifat sensitif pastikan semua file log hanya dapat dibaca oleh user pemilik file.

  _e. Because log files are sensitive, make sure all log files can only be read by the user who owns the file._

**Notes:**

- Nama file untuk script per menit adalah [minute_log.sh](./minute_log.sh)

  _The file name for the minutely script is [minute_log.sh](./minute_log.sh)_

- Nama file untuk script aggregasi per jam adalah [aggregate_minutes_to_hourly_log.sh](./aggregate_minutes_to_hourly_log.sh)

  _The file name for the hourly aggregation script is [aggregate_minutes_to_hourly_log.sh](./aggregate_minutes_to_hourly_log.sh)_

- Semua file log terletak di `/home/{user}/metrics`

  _All log files are located in `/home/{user}/metrics`_

- Konfigurasi cron diletakkan di file [crontabs](./crontabs)

  _The cron configuration is placed in the [crontabs](./crontabs) file_

**Berikut adalah contoh isi dari file metrics yang dijalankan tiap menit:**

_**The following is an example of the contents of the metrics file that is run every minute:**_

```csv
mem_total,mem_used,mem_free,mem_shared,mem_buff,mem_available,swap_total,swap_used,swap_free,path,path_size
15949,10067,308,588,5573,4974,2047,43,2004,/home/$USER/test/,74M
```

**Berikut adalah contoh isi dari file aggregasi yang dijalankan tiap jam:**

_**The following is an example of the contents of the aggregation file that is run every hour:**_

```csv
type,mem_total,mem_used,mem_free,mem_shared,mem_buff,mem_available,swap_total,swap_used,swap_free,path,path_size
minimum,15949,10067,223,588,5339,4626,2047,43,1995,/home/$USER/test/,50M
maximum,15949,10387,308,622,5573,4974,2047,52,2004,/home/$SERtest/,74M
average,15949,10227,265.5,605,5456,4800,2047,47.5,1999.5,/home/$USER/test/,62M
```
