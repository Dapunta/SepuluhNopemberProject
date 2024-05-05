# Gunakan base image yang sesuai (misalnya: Ubuntu)
FROM ubuntu:latest

# Update package list
RUN apt-get update

# Instal Python 3, pip, dan python3-venv
RUN apt-get install -y python3 python3-pip python3-venv unzip

# Upgrade pip
# RUN pip3 install --upgrade pip

# Buat dan aktifkan virtual environment
RUN python3 -m venv /venv
ENV PATH="/venv/bin:$PATH"

# Instal Kaggle CLI menggunakan pip di dalam virtual environment
RUN pip install kaggle

# Tambahkan langkah-langkah lain yang diperlukan dalam Dockerfile sesuai kebutuhan

# Buat direktori /usr/src
RUN mkdir -p /usr/src

# Salin file ayamgoreng.c ke dalam direktori /usr/src
COPY ayamgoreng.c /usr/src/

# Set working directory
WORKDIR /usr/src

# Kompilasi ayamgoreng.c
RUN gcc -o ayamgoreng ayamgoreng.c

# Command default yang akan dijalankan saat container dimulai
CMD ["./ayamgoreng"]
