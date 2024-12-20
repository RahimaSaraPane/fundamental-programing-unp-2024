#include <stdio.h>

int main()
{
    // Deklarasi variabel
    float nilaiTugas, nilaiUTS, nilaiUAS, nilaiAkhir;
    int lulus;

    // Nama pemrogram
    printf("Nama: Rahima Sara Pane\n");
    printf("NIM: 24343022");
    printf("Tgl pembuatan: 04.10.24");

    // Input nilai dari pengguna
    printf("masukkan nilai Tugas (0-100): ");
    scanf("%f", &nilaiTugas);
    printf("masukkan nilai UTS (0-100): ");
    scanf("%f", &nilaiUTS);
    printf("masukkan nilai UAS (0-100): ");
    scanf("%f", &nilaiUAS);

    // Hitung nilai akhir
    nilaiAkhir = (0.3 * nilaiTugas) + (0.3 * nilaiUTS) + (0.4 * nilaiUAS);

    // Tentukan apakah lulus atau tidak
    lulus = (nilaiAkhir >= 60) && (nilaiUAS >= 50);

    // Output hasil
    printf("\nNilai Akhir Anda: %.2f\n", nilaiAkhir);

    if (lulus)
    {
        printf("Selamat! anda LULUS.\n");
    }
    else
    {
        printf("Maaf, anda TIDAK LULUS.\n");
    }

    return 0;
}