/*  Nama File       : 24343022_RAHIMA SARA PANE_ARRAY_A
    Programmer      : Rahima Sara Pane (24343022)
    Tgl. pembuatan  : 12/11/24
    Deskripsi       : Menampilkan elemen array
*/
#include <stdio.h>

int main() {

    // Nama pemrogram
    printf("\tMenampilkan elemen array\n");
    printf("\t========================\n\n");
    printf("Nama: Rahima Sara Pane\n");
    printf("NIM: 24343022\n");
    printf("Tgl pembuatan: 12/11/24\n\n");

    // Deklarasikan array 
    int angka[5] = {1, 2, 3, 4, 5};

    //menampilkan semua elemen array menggunakan loop
    printf("Elemen-elemen dalam array angka:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", angka[i]);
    }
    printf("\n");

    return 0;
}
