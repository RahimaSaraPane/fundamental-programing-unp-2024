/*  Nama File       : 24343022_RAHIMA SARA PANE_TUGAS1.c
    Programmer      : Rahima Sara Pane (24343022)
    Tgl. pembuatan  : 18/10/24
    Deskripsi       : game tebak angka dengan skor tertinggi dan pilihan level kesulitan.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int angkaTebakan, tebakan, kesempatan, mainLagi, skorTertinggi = 0, skorSaatIni;
    char pilihan;
    int maxRange, level;

    // Menginisialisasi generator angka acak
    srand(time(0));

    do {
        // Pilih level kesulitan
        printf("Pilih level kesulitan:\n");
        printf("1. Mudah (1-50)\n");
        printf("2. Normal (1-100)\n");
        printf("3. Sulit (1-200)\n");
        printf("Masukkan pilihan level Anda (1/2/3): ");
        scanf("%d", &level);

        switch (level) {
            case 1:
                maxRange = 50;
                break;
            case 2:
                maxRange = 100;
                break;
            case 3:
                maxRange = 200;
                break;
            default:
                printf("Pilihan level tidak valid. Menggunakan level Normal (1-100).\n");
                maxRange = 100;
        }

        // Pilih angka acak berdasarkan level kesulitan
        angkaTebakan = rand() % maxRange + 1;
        kesempatan = 5;
        printf("\nSelamat datang di permainan Tebak Angka!\n");
        printf("Saya telah memilih sebuah angka antara 1 dan %d.\n", maxRange);
        printf("Anda memiliki 5 kesempatan untuk menebaknya.\n");

        // Mulai permainan dengan struktur kontrol loop
        while (kesempatan > 0) {
            printf("\nMasukkan tebakan Anda: ");
            scanf("%d", &tebakan);

            // Struktur kontrol if-else untuk mengevaluasi tebakan
            if (tebakan > angkaTebakan) {
                printf("Tebakan Anda terlalu tinggi!\n");
            } else if (tebakan < angkaTebakan) {
                printf("Tebakan Anda terlalu rendah!\n");
            } else {
                printf("Selamat! Anda menebak dengan benar!\n");
                // Hitung skor berdasarkan sisa kesempatan
                skorSaatIni = kesempatan * 10;
                printf("Skor Anda: %d\n", skorSaatIni);

                // Cek apakah skor saat ini lebih tinggi dari skor tertinggi
                if (skorSaatIni > skorTertinggi) {
                    skorTertinggi = skorSaatIni;
                    printf("Selamat! Anda mencetak skor tertinggi baru: %d\n", skorTertinggi);
                } else {
                    printf("Skor tertinggi saat ini: %d\n", skorTertinggi);
                }
                break;
            }

            kesempatan--; // Kurangi jumlah kesempatan
            printf("Kesempatan tersisa: %d\n", kesempatan);
        }

        // Evaluasi akhir jika gagal menebak dalam 5 kesempatan
        if (kesempatan == 0) {
            printf("Maaf, Anda kehabisan kesempatan. Angka yang benar adalah %d.\n", angkaTebakan);
        }

        // Opsi untuk bermain lagi menggunakan switch
        printf("Apakah Anda ingin bermain lagi? (y/n): ");
        scanf(" %c", &pilihan);  // Spasi sebelum %c untuk menghindari masalah input

        switch (pilihan) {
            case 'y':
            case 'Y':
                mainLagi = 1;
                break;
            case 'n':
            case 'N':
                mainLagi = 0;
                printf("Terima kasih telah bermain!\n");
                break;
            default:
                printf("Pilihan tidak valid, keluar dari permainan.\n");
                mainLagi = 0;
                break;
        }

    } while (mainLagi);

    return 0;
}
