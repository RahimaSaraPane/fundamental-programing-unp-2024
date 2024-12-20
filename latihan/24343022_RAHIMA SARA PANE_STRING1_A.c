/*  Nama File       : 24343022_RAHIMA SARA PANE_STRING1_A
    Programmer      : Rahima Sara Pane (24343022)
    Tgl. pembuatan  : 25/10/24
    Deskripsi       : Menghitung Panjang String
*/
#include <stdio.h>
#include <string.h>

// Deklarasi fungsi hitungPanjangString
int hitungPanjangString(char str[]) {
    return strlen(str);
}

int main() {
    char input[100];

    // Nama pemrogram
    printf("\tMenghitung Panjang String\n");
    printf("\t=========================\n\n");
    printf("Nama: Rahima Sara Pane\n");
    printf("NIM: 24343022\n");
    printf("Tgl pembuatan: 12.11.24\n\n");

    // Meminta input string dari pengguna
    printf("Masukkan sebuah string: ");
    fgets(input, sizeof(input), stdin);
    
    // Menghitung panjang string menggunakan fungsi hitungPanjangString
    int panjang = hitungPanjangString(input);
    
    // Menampilkan panjang string
    printf("Panjang string yang dimasukkan adalah: %d\n", panjang - 1);
    
    return 0;
}
