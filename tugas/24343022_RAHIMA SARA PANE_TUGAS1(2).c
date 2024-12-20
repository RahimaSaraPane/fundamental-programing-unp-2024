/*  Nama File       : 24343022_RAHIMA SARA PANE_TUGAS1_C
    Programmer      : Rahima Sara Pane (24343022)
    Tgl. pembuatan  : 15/11/24
    Deskripsi       : Sistem Manajemen Pesanan Restoran
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struct untuk menyimpan informasi pesanan
struct Pesanan {
    char namaMakanan[50];
    int jumlah;
    float harga;
    struct Pesanan *next; // Pointer ke pesanan berikutnya (untuk linked list)
};

// Fungsi untuk menambah pesanan
struct Pesanan* tambahPesanan(struct Pesanan *head) {
    struct Pesanan *newPesanan = (struct Pesanan*) malloc(sizeof(struct Pesanan));
    if (newPesanan == NULL) {
        printf("Memori tidak cukup!\n");
        return head;
    }

    // Input pesanan dari pengguna
    printf("Masukkan nama makanan: ");
    fgets(newPesanan->namaMakanan, 50, stdin);
    newPesanan->namaMakanan[strcspn(newPesanan->namaMakanan, "\n")] = '\0'; // Menghapus newline
    printf("Masukkan jumlah: ");
    scanf("%d", &newPesanan->jumlah);
    printf("Masukkan harga per unit: ");
    scanf("%f", &newPesanan->harga);
    getchar(); // Membersihkan karakter newline dari input

    // Menambahkan pesanan ke pesanan berikutnya
    newPesanan->next = head;
    printf("Pesanan berhasil ditambahkan!\n");

    return newPesanan; // Mengembalikan pesanan terbaru sebagai head dari linked list
}

// Fungsi untuk menampilkan daftar pesanan
void tampilkanPesanan(struct Pesanan *head) {
    struct Pesanan *current = head;
    if (current == NULL) {
        printf("Tidak ada pesanan.\n");
        return;
    }

    printf("\n--- Daftar Pesanan ---\n");
    while (current != NULL) {
        printf("Nama Makanan: %s\n", current->namaMakanan);
        printf("Jumlah: %d\n", current->jumlah);
        printf("Harga: %.2f\n", current->harga);
        printf("----------------------\n");
        current = current->next;
    }
}

// Fungsi untuk menghapus pesanan
struct Pesanan* hapusPesanan(struct Pesanan *head, char *namaMakanan) {
    struct Pesanan *current = head;
    struct Pesanan *prev = NULL;

    while (current != NULL && strcmp(current->namaMakanan, namaMakanan) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Pesanan tidak ditemukan.\n");
        return head;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current); // Mengembalikan memori
    printf("Pesanan %s telah dihapus.\n", namaMakanan);

    return head;
}

// Fungsi untuk mengedit pesanan
void editPesanan(struct Pesanan *head, char *namaMakanan) {
    struct Pesanan *current = head;

    while (current != NULL && strcmp(current->namaMakanan, namaMakanan) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Pesanan tidak ditemukan.\n");
        return;
    }

    printf("Pesanan ditemukan. Masukkan data baru:\n");
    printf("Jumlah baru: ");
    scanf("%d", &current->jumlah);
    printf("Harga baru per unit: ");
    scanf("%f", &current->harga);
    getchar(); // Membersihkan karakter newline dari input

    printf("Pesanan %s berhasil diperbarui.\n", namaMakanan);
}

// Fungsi untuk menghitung total pendapatan
void hitungTotalPendapatan(struct Pesanan *head) {
    struct Pesanan *current = head;
    float totalPendapatan = 0;

    while (current != NULL) {
        totalPendapatan += current->jumlah * current->harga;
        current = current->next;
    }

    printf("Total Pendapatan: %.2f\n", totalPendapatan);
}

int main() {
    struct Pesanan *pesananList = NULL;
    int pilihan;
    char namaMakanan[50];

    // Nama pemrogram
    printf("\tSistem Manajemen Pesanan Restoran\n");
    printf("\t==================================\n\n");
    printf("Nama         : Rahima Sara Pane\n");
    printf("NIM          : 24343022\n");
    printf("Tgl pembuatan: 15/11/24\n\n");

    do {
        // Menu utama
        printf("\n--- Sistem Manajemen Pesanan Restoran ---\n");
        printf("1. Tambah Pesanan\n");
        printf("2. Tampilkan Semua Pesanan\n");
        printf("3. Hapus Pesanan\n");
        printf("4. Edit Pesanan\n"); // Menambahkan opsi Edit Pesanan
        printf("5. Hitung Total Pendapatan\n");
        printf("6. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);
        getchar(); // Membersihkan karakter newline

        switch (pilihan) {
            case 1:
                pesananList = tambahPesanan(pesananList);
                break;
            case 2:
                tampilkanPesanan(pesananList);
                break;
            case 3:
                printf("Masukkan nama makanan yang akan dihapus: ");
                fgets(namaMakanan, 50, stdin);
                namaMakanan[strcspn(namaMakanan, "\n")] = '\0'; // Menghapus newline
                pesananList = hapusPesanan(pesananList, namaMakanan);
                break;
            case 4:
                printf("Masukkan nama makanan yang akan diedit: ");
                fgets(namaMakanan, 50, stdin);
                namaMakanan[strcspn(namaMakanan, "\n")] = '\0'; // Menghapus newline
                editPesanan(pesananList, namaMakanan);
                break;
            case 5:
                hitungTotalPendapatan(pesananList);
                break;
            case 6:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 6);

    // Menghapus semua pesanan dan membebaskan memori sebelum keluar
    while (pesananList != NULL) {
        struct Pesanan *temp = pesananList;
        pesananList = pesananList->next;
        free(temp);
    }

    return 0;
}
