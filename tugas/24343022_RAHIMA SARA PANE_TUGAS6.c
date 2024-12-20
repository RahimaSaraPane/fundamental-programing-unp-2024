/*
    nama file         : tugas6.c
    programer         : Rahima Sara Pane
    nim               : 24343022
    program           : program memebaca file teks, menghitung jumlah kata dan waktu eksekusi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//fungsi menampilkan biodata
void biodata(){
	printf("program membuat fungsi judul \n");
	printf("-----------------------------------\n");
	printf("Nama : Rahima Sara Pane\n");
	printf("Nim  : 24343022\n");
	printf("-------------------------------\n");
}

// Untuk mengukur waktu eksekusi
#define MAX_BUFFER 1000 // Ukuran buffer untuk membaca file

// Fungsi untuk menghitung kata dalam file
int hitungKata(FILE *file) {
    char buffer[MAX_BUFFER];
    int jumlahKata = 0;
    char *kata;

    // Baca file baris per baris dan hitung jumlah kata
    while (fgets(buffer, MAX_BUFFER, file) != NULL) {
        // Tokenisasi string dengan delimiter spasi, tab, atau newline
        kata = strtok(buffer, " \t\n");
        while (kata != NULL) {
            jumlahKata++; // Tambahkan jumlah kata
            kata = strtok(NULL, " \t\n"); // Ambil kata berikutnya
        }
    }

    return jumlahKata;
}

int main() {
    biodata();
    FILE *file;
    char namaFile[100];
    int jumlahKata;
    clock_t start, end; // Untuk mengukur waktu
    double waktuEksekusi;

    // Meminta pengguna memasukkan nama file
    printf("Masukkan nama file: ");
    scanf("%s", namaFile);

    // Membuka file
    file = fopen(namaFile, "r");
    if (file == NULL) {
        printf("Gagal membuka file %s.\n", namaFile);
        return 1;
    }

    // Mengukur waktu mulai
    start = clock();

    // Menghitung jumlah kata dalam file
    jumlahKata = hitungKata(file);

    // Mengukur waktu selesai
    end = clock();

    // Menghitung waktu eksekusi dalam detik
    waktuEksekusi = (double)(end - start) / CLOCKS_PER_SEC;

    // Menutup file
    fclose(file);

    // Menampilkan hasil
    printf("Jumlah kata dalam file: %d\n", jumlahKata);
    printf("Waktu eksekusi: %.5f detik\n", waktuEksekusi);

    return 0;
}