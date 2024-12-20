#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definisi struct untuk menyimpan data siswa
typedef struct Siswa {
    char nama[50];
    char nisn[20];
    char kelas[20];
    char ttl[30];
    char jenisKelamin[2]; // L/P
    char noHp[15];
    char hobi[30];
    char alamat[100];
} Siswa;

// Fungsi untuk membaca data dari file
int bacaData(Siswa **data, FILE *file) {
    int jumlah = 0, kapasitas = 1000;
    char buffer[1000]; 

    *data = malloc(kapasitas * sizeof(Siswa));
    if (*data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 0;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        // Parsing data dari buffer
        if (sscanf(buffer, "nama:%49[^ ] nisn:%19s kelas:%19s ttl:%29[^ ] jeniskelamin:%1s nohp:%14s hobi:%29[^ ] alamat:%99[^\n]",
                   (*data)[jumlah].nama,
                   (*data)[jumlah].nisn,
                   (*data)[jumlah].kelas,
                   (*data)[jumlah].ttl,
                   (*data)[jumlah].jenisKelamin,
                   (*data)[jumlah].noHp,
                   (*data)[jumlah].hobi,
                   (*data)[jumlah].alamat) == 8) {
            jumlah++;

            // Periksa apakah perlu menambah kapasitas
            if (jumlah >= kapasitas) {
                kapasitas += 500; // Tambah kapasitas dalam kelipatan 500 siswa
                Siswa *temp = realloc(*data, kapasitas * sizeof(Siswa));
                if (temp == NULL) {
                    fprintf(stderr, "Memory reallocation failed\n");
                    free(*data);
                    return jumlah;
                }
                *data = temp;
            }
        }
    }
    return jumlah;
}

// Fungsi untuk menampilkan data siswa
void tampilkanData(Siswa *data, int jumlah) {
    printf("\n%-4s | %-20s | %-10s | %-10s | %-25s | %-5s | %-15s | %-20s | %-30s\n",
           "No", "Nama", "NISN", "Kelas", "TTL", "JK", "No HP", "Hobi", "Alamat");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < jumlah; i++) {
        printf("%-4d | %-20s | %-10s | %-10s | %-25s | %-5s | %-15s | %-20s | %-30s\n",
               i + 1, data[i].nama, data[i].nisn, data[i].kelas, data[i].ttl, data[i].jenisKelamin,
               data[i].noHp, data[i].hobi, data[i].alamat);
    }
}

// Fungsi untuk menyimpan data siswa ke dalam file
void simpanData(Siswa *data, int jumlah, FILE *file) {
    for (int i = 0; i < jumlah; i++) {
        fprintf(file, "nama:%s nisn:%s kelas:%s ttl:%s jeniskelamin:%s nohp:%s hobi:%s alamat:%s\n",
                data[i].nama, data[i].nisn, data[i].kelas, data[i].ttl, data[i].jenisKelamin,
                data[i].noHp, data[i].hobi, data[i].alamat);
    }
}

// Fungsi utama
int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    FILE *inputFile, *outputFile;
    Siswa *data;
    int jumlahSiswa;

    // Membuka file input untuk membaca
    inputFile = fopen("data_siswa.txt", "r");
    if (inputFile == NULL) {
        fprintf(stderr, "File 'data_siswa.txt' tidak ditemukan!\n");
        return 1;
    }

    // Membaca data siswa dari file
    jumlahSiswa = bacaData(&data, inputFile);
    fclose(inputFile);

    // Menampilkan data siswa jika ada yang dibaca
    if (jumlahSiswa > 0) {
        tampilkanData(data, jumlahSiswa);

        // Menyimpan data kembali ke file
        outputFile = fopen("output_data_siswa.txt", "w");
        if (outputFile == NULL) {
            fprintf(stderr, "File 'output_data_siswa.txt' tidak dapat dibuat!\n");
            free(data);
            return 1;
        }

        simpanData(data, jumlahSiswa, outputFile);
        fclose(outputFile);

        printf("\nData telah disimpan di 'output_data_siswa.txt'\n");
    } else {
        printf("Tidak ada data siswa yang ditemukan.\n");
    }

    // Membebaskan memori
    free(data);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nWaktu eksekusi program: %.2f detik\n", cpu_time_used);

    return 0;
}