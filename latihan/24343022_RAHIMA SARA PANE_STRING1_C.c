/*  Nama File       : 24343022_RAHIMA SARA PANE_STRING1_C
    Programmer      : Rahima Sara Pane (24343022)
    Tgl. pembuatan  : 25/10/24
    Deskripsi       : Membandingkan dua String
*/

#include<stdio.h>
#include<string.h>

int bandingkanString(char str1[], char str2[]) {
    return strcmp(str1, str2);
}

int main() {
    char str1[100];
    char str2[100];

    // Nama pemrogram
    printf("\tMenggabungkan Dua String\n");
    printf("\t========================\n\n");
    printf("Nama: Rahima Sara Pane\n");
    printf("NIM: 24343022\n");
    printf("Tgl pembuatan: 12/11/24\n\n");

    //meminta input dari pengguna
    printf("Masukkan String pertama: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("masukkan string kedua: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcmp(str2, "\n")] = '\0';

    //membandingkan kedua string
    int hasil = bandingkanString(str1, str2);

    //menampilkan hasil
    if (hasil == 0) {
        printf("String yang di masukan adalah sama. \n");
    } else {
        printf("String yang dimasukkan tidak sama. \n");
    }

    return 0;
}