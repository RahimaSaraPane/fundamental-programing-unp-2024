/*  Nama File       : 24343022_RAHIMA SARA PANE_TUGAS5.1_B.c
    Programmer      : Rahima Sara Pane (24343022)
    Tgl. pembuatan  : 25/10/24
    Deskripsi       : Menghitung keliling lingkaran
*/
#include <stdio.h>

// Fungsi untuk menghitung keliling lingkaran
float hitungKelilingLingkaran(float jariJari)
{
    return 2 * 3.14 * jariJari;
}

int main()
{
    float jariJari;

    // Nama pemrogram
    printf("Nama: Rahima Sara Pane\n");
    printf("NIM: 24343022");
    printf("Tgl pembuatan: 25.10.24\n");

    printf("Masukkan jari-jari lingkaran: ");
    scanf("%f", &jariJari);

    // Memanggil fungsi dan menampilkan hasil
    float keliling = hitungKelilingLingkaran(jariJari);
    printf("Keliling lingkaran adalah: %.2f\n", keliling);

    return 0;
}
