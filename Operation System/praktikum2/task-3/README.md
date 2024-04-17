## Rama's Weather Forecast

Rama is a university student taking an Operating Systems course. He has been assigned a project by his professor to manage weather data from various districts in Indonesia. The data is available in a zip file, which can be downloaded [here](https://drive.usercontent.google.com/u/0/uc?id=1U1-9v9pJeX5MoofwoBHCcD9nA7YWy_np&export=download). Rama enjoys challenges and will perform analysis using Linux processes. Help Rama complete the task with a single C program called [weather_manager.c](./weather_manager.c). Here are the steps Rama needs to follow:

- a. Download the zip file and save it to local storage. Extract the weather data into a folder named “weather”. Once done, delete the zip file to save memory.

  ```
  weather/
  ├── kecamatanforecast.csv
  └── kecamatan_geofeatures.csv
  ```

- b. After successfully completing the process, Rama performed data preprocessing by identifying and removing rows with unreasonable data in the "Suhu Udara" column. He then updated the "kecamatanforecast.csv" dataset.

- c. Group the data from the “kecamatanforecast.csv” dataset by ID Lokasi, and separate it into new datasets named in the format “city\_{ID Lokasi}.csv” (e.g., city_5012725.csv). Place all the new datasets in a folder named “city_group”.

- d. Rama needs to create a logbook for reporting to his professor, so all the above activities should be recorded in a file called “logbook.txt” with the format {[YYYY-MM-dd HH:mm:ss] [message]}.

  | Activity      | Message                                                                     |
  | ------------- | --------------------------------------------------------------------------- |
  | Downloading   | [24-4-12 12:11:10] Successfully download file..                             |
  | Unzipping     | [24-4-12 12:20:10] Successfully unzip file..                                |
  | Preprocessing | [24-4-12 12:40:10] Successfully drop row with {parameter} {parameter value} |
  | Grouping      | [24-4-12 12:40:10] Successfully data grouping..                             |

### Notes:

- The kecamatanforecast.csv dataset uses numeric headers.
- Order of parameters in kecamatanforecast.csv (left to right, separated by ;):

  - Location ID
  - Time in UTC (YYYY-MM-DD HH:mm:ss)
  - Air temperature (average) minimum in °C
  - Air temperature (average) maximum in °C
  - Air humidity (average) minimum in %
  - Air humidity (average) maximum in %
  - Air humidity in %
  - Air temperature in °C
  - Weather code
  - Wind direction as a cardinal direction (e.g., N, NE, E, etc.)
  - Wind speed in km/h

- Hint: According to a Science Advances journal article (2020), the human body can tolerate heat up to 35 degrees Celsius.

- Submit only the [weather_manager.c](./weather_manager.c) file and [logbook.txt](./logbook.txt) to GitHub.

- Use `fork()` and `exec()` for the tasks above.

## Ramalan Cuaca Rama

Rama adalah seorang mahasiswa yang mengambil mata kuliah Sistem Operasi. Ia diberikan proyek oleh dosennya untuk mengelola data cuaca dari berbagai kecamatan di Indonesia. Data tersebut tersedia dalam file zip yang bisa didownload disini. Karena suka tantangan, Rama melakukan analisis dengan menggunakan process di linux. Bantulah Rama untuk menyelesaikan tugas ini dengan satu program C bernama [weather_manager.c](./weather_manager.c). Berikut langkah-langkah yang bisa dilakukan Rama:

- a. Rama harus mendownload dan menyimpan file tersebut ke dalam penyimpanan lokal dan mengekstrak data cuaca tersebut pada folder yang bernama “weather”. Untuk menghemat memori Rama menghapus file zip tersebut.

  ```
  weather/
  ├── kecamatanforecast.csv
  └── kecamatan_geofeatures.csv
  ```

- b. Setelah berhasil, Rama melakukan data preprocessing dengan cara mencari data yang tidak masuk akal pada kolom “Suhu Udara” dan melakukan drop pada row tersebut. Lalu update dataset “kecamatanforecast.csv”.

- c. Kemudian dari dataset tersebut, Rama mengelompokkannya berdasarkan ID Lokasi dan memisahkannya menjadi dataset baru dengan format nama “city\_{ID Lokasi}” contoh “city_5012725.csv”. Semua dataset baru tersebut dimasukan ke dalam folder bernama “city_group”.

- d. Rama harus membuat logbook untuk laporan kepada dosen, sehingga semua activities diatas harus disimpan dalam “logbook.txt” dengan format { [YYYY-MM-dd HH:mm:ss] [message]}

  | Activity      | Message                                                                   |
  | ------------- | ------------------------------------------------------------------------- |
  | Downloading   | [24-4-12 12:11:10] Berhasil download file..                               |
  | Unzipping     | [24-4-12 12:20:10] Berhasil unzip file..                                  |
  | Preprocessing | [24-4-12 12:40:10] Berhasil drop row dengan {parameter} {parameter value} |
  | Grouping      | [24-4-12 12:40:10] Berhasil melakukan group data..                        |

### Notes:

- Dataset “kecamatanforecast.csv” headernya memang berupa angka

- Urutan Parameter kecamatanforecast.csv (kiri ke kanan, separator ";")

  - ID Lokasi
  - Waktu dalam UTC
  - YYYY-MM-DD HH:mm:ss
  - Suhu Udara (rata-rata) Minimum dalam °C
  - Suhu Udara (rata-rata) Maksimum dalam °C
  - Kelembaban Udara (rata-rata) Minimum dalam %
  - Kelembaban Udara (rata-rata) Maksimum dalam %
  - Kelembaban Udara dalam %
  - Suhu Udara dalam °C
  - Cuaca berupa kode cuaca
  - Arah Angin berupa CARD
  - Kecepatan Angin dalam km/jam

- Hint : Menurut jurnal Science Advances (2020), tubuh manusia dapat mentoleransi suhu panas hingga 35 derajat Celcius.

- Untuk mencari outliers **tidak** perlu menggunakan metode IQR.

- Hanya file [weather_manager.c](./weather_manager.c) dan [logbook.txt](./logbook.txt) yang dikumpulkan di github.

- Gunakan `fork()`, `exec()` untuk melakukan aktivitas di atas.
