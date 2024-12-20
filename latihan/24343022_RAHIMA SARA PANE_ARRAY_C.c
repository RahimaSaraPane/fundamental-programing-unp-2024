/*  Nama File       : 24343022_RAHIMA SARA PANE_ARRAY_C
    Programmer      : Rahima Sara Pane (24343022)
    Tgl. pembuatan  : 12/11/24
    Deskripsi       : Mengganti nilai elemen array
*/
#include <stdio.h>

int main() {

    // Nama pemrogram
    printf("\tMengganti nilai elemen array\n");
    printf("\t========================\n\n");
    printf("Nama: Rahima Sara Pane\n");
    printf("NIM: 24343022\n");
    printf("Tgl pembuatan: 12/11/24\n\n");

    // Deklarasikan array bertipe int dengan nama angka dan ukuran 5
    int angka[5] = {1, 2, 3, 4, 5};
    int indeks, nilaiBaru;

    // Menampilkan array sebelum diganti
    printf("Array sebelum diganti:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", angka[i]);
    }
    printf("\n");

    // Meminta pengguna memasukkan nomor elemen yang ingin diganti (indeks) dan nilai baru
    printf("Masukkan nomor elemen yang ingin diganti (0-4): ");
    scanf("%d", &indeks);
    printf("Masukkan nilai baru: ");
    scanf("%d", &nilaiBaru);

    // Mengganti nilai pada elemen yang dipilih
    if (indeks >= 0 && indeks < 5) {
        angka[indeks] = nilaiBaru;
    } else {
        printf("Indeks tidak valid.\n");
        return 1; // Keluar program dengan kode kesalahan
    }

    // Menampilkan array setelah nilai elemen diganti
    printf("Array setelah diganti:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", angka[i]);
    }
    printf("\n");

    return 0;
}
