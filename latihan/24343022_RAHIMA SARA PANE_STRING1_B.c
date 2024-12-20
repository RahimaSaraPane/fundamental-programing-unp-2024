/*  Nama File       : 24343022_RAHIMA SARA PANE_STRING1_B 
    Programmer      : Rahima Sara Pane (24343022)
    Tgl. pembuatan  : 25/10/24
    Deskripsi       : Menggabungkan Dua String
*/
#include <stdio.h>
#include <string.h>

void gabungkanString(char hasil[], char str1[], char str2[]) { 
    strcpy(hasil, str1);
    strcat(hasil, str2);
}

int main() {
    char str1[100];
    char str2[100];
    char hasil[200];

    // Nama pemrogram
    printf("\tMenggabungkan Dua String\n");
    printf("\t========================\n\n");
    printf("Nama: Rahima Sara Pane\n");
    printf("NIM: 24343022\n");
    printf("Tgl pembuatan: 12/11/24\n\n");

    // Meminta dua input dari pengguna
    printf("Masukkan string pertama: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  

    printf("Masukkan string kedua: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; 

    // Menggabungkan kedua string
    gabungkanString(hasil, str1, str2);

    // Menampilkan hasil
    printf("Hasil penggabungan: %s\n", hasil);

    return 0;
}
