/*  Nama File       : 24343022_RAHIMA SARA PANE_FILE_PENGELOLA DATA SISWA.c 
    Programmer      : Rahima Sara Pane (24343022)
    Tgl. pembuatan  : 29/11/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// mendefinisikan tipe struct
typedef struct {
    char nama[30];
    char nisn[10];
    char jenisKelamin[10];
    char tempatTanggalLahir[30];
    int umur;
    char agama[20]; 
    char kewarganegaraan[20];
    int anakKe;
    int jumlahSaudara;
    char alamat[100];
    char noTelp[15];
    double nilaiBahasaIndonesia;
    double nilaiMatematika;
    double nilaiBahasaInggris;
    double nilaiIPA;
    double totalNilai;
} Siswa;

// deklarasi fungsi
void tambahSiswa(Siswa *siswa, int *jumlah, int kapasitas);
void tambahBeberapaSiswa(Siswa *siswa, int *jumlah, int kapasitas);
void editSiswa(Siswa *siswa, int jumlah);
void tampilkanSiswa(Siswa *siswa, int jumlah);
void hitungTotalNilai(Siswa *siswa);

int main() {
    int pilihan;
    int kapasitas = 100;
    Siswa *daftarSiswa = malloc(kapasitas * sizeof(Siswa));
    int jumlahSiswa = 0;

    if (daftarSiswa == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1;
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah Siswa\n");
        printf("2. Edit Siswa\n");
        printf("3. Tampilkan Siswa\n");
        printf("4. Keluar\n");
        printf("Pilih opsi (1-4): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahBeberapaSiswa(daftarSiswa, &jumlahSiswa, kapasitas);
                break;
            case 2:
                editSiswa(daftarSiswa, jumlahSiswa);
                break;
            case 3:
                tampilkanSiswa(daftarSiswa, jumlahSiswa);
                break;
            case 4:
                free(daftarSiswa);
                exit(0);
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }
    return 0;
}

// fungsi untuk menambah beberapa siswa
void tambahBeberapaSiswa(Siswa *siswa, int *jumlah, int kapasitas) {
    int jumlahBaru, i;

    printf("Masukkan jumlah siswa yang akan diinput: ");
    scanf("%d", &jumlahBaru);

    for (i = 0; i < jumlahBaru; i++) {
        if (*jumlah >= kapasitas) {
            printf("Kapasitas maksimal tercapai.\n");
            return;
        }
        printf("\nEntri Siswa ke-%d\n", *jumlah + 1);
        
        printf("Nama Siswa: ");
        scanf(" %[^\n]", siswa[*jumlah].nama); 
        fflush(stdin);
        
        printf("Ketikkan NISN : ");
        scanf("%s", siswa[*jumlah].nisn);
        
        printf("Jenis Kelamin: ");
        scanf("%s", siswa[*jumlah].jenisKelamin);
        
        printf("Tempat Tanggal Lahir: ");
        scanf(" %[^\n]", siswa[*jumlah].tempatTanggalLahir);
        
        printf("Umur: ");
        scanf("%d", &siswa[*jumlah].umur);
        
        printf("Agama: ");
        scanf("%s", siswa[*jumlah].agama);
        
        printf("Kewarganegaraan: ");
        scanf("%s", siswa[*jumlah].kewarganegaraan);
        
        printf("Anak ke-: ");
        scanf("%d", &siswa[*jumlah].anakKe);
        
        printf("Jumlah Saudara: ");
        scanf("%d", &siswa[*jumlah].jumlahSaudara);
        
        printf("Alamat: ");
        scanf(" %[^\n]", siswa[*jumlah].alamat);
        
        printf("No Telp: ");
        scanf("%s", siswa[*jumlah].noTelp);

        printf("Nilai Bahasa Indonesia: ");
        scanf("%lf", &siswa[*jumlah].nilaiBahasaIndonesia);

        printf("Nilai Matematika: ");
        scanf("%lf", &siswa[*jumlah].nilaiMatematika);

        printf("Nilai Bahasa Inggris: ");
        scanf("%lf", &siswa[*jumlah].nilaiBahasaInggris);

        printf("Nilai IPA: ");
        scanf("%lf", &siswa[*jumlah].nilaiIPA);

        hitungTotalNilai(&siswa[*jumlah]);
        (*jumlah)++;
    }
}

void editSiswa(Siswa *siswa, int jumlah) {
    if (jumlah == 0) {
        printf("Tidak ada data untuk diubah.\n");
        return;
    }

    char nisn[10];
    printf("\nMasukkan NISN Siswa yang ingin diubah: ");
    scanf("%s", nisn);

    for (int i = 0; i < jumlah; i++) {
        if (strcmp(siswa[i].nisn, nisn) == 0) {
            printf("Data ditemukan. Masukkan data baru.\n");
            
            printf("Nama Siswa: ");
            scanf(" %[^\n]", siswa[i].nama);
            
            printf("Jenis Kelamin: ");
            scanf("%s", siswa[i].jenisKelamin);
            
            printf("Tempat Tanggal Lahir: ");
            scanf(" %[^\n]", siswa[i].tempatTanggalLahir);
            
            printf("Umur: ");
            scanf("%d", &siswa[i].umur);
            
            printf("Agama: ");
            scanf("%s", siswa[i].agama);
            
            printf("Kewarganegaraan: ");
            scanf("%s", siswa[i].kewarganegaraan);
            
            printf("Anak ke-: ");
            scanf("%d", &siswa[i].anakKe);
            
            printf("Jumlah Saudara: ");
            scanf("%d", &siswa[i].jumlahSaudara);
            
            printf("Alamat: ");
            scanf(" %[^\n]", siswa[i].alamat);
            
            printf("No Telp: ");
            scanf("%s", siswa[i].noTelp);

            printf("Nilai Bahasa Indonesia: ");
            scanf("%lf", &siswa[i].nilaiBahasaIndonesia);

            printf("Nilai Matematika: ");
            scanf("%lf", &siswa[i].nilaiMatematika);

            printf("Nilai Bahasa Inggris: ");
            scanf("%lf", &siswa[i].nilaiBahasaInggris);

            printf("Nilai IPA: ");
            scanf("%lf", &siswa[i].nilaiIPA);

            hitungTotalNilai(&siswa[i]);
            printf("Data berhasil diubah.\n");
            return;
        }
    }
    
    printf("Siswa dengan NISN %s tidak ditemukan.\n", nisn);
}

void tampilkanSiswa(Siswa *siswa, int jumlah) {
    if (jumlah == 0) {
        printf("Tidak ada data untuk ditampilkan.\n");
        return;
    }

    // Tabel Data Siswa
    printf("\n%-4s | %-30s | %-10s | %-15s | %-4s | %-10s | %-15s | %-7s | %-7s | %-15s\n", 
           "No", "Nama", "NISN", "Jenis Kelamin", "Umur", "Agama", "Kewarganegaraan", 
           "Anak Ke", "Saudara", "No Telp");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < jumlah; i++) {
        printf("%-4d | %-30s | %-10s | %-15s | %-4d | %-10s | %-15s | %-7d | %-7d | %-15s\n", 
               i + 1, siswa[i].nama, siswa[i].nisn, siswa[i].jenisKelamin, siswa[i].umur, 
               siswa[i].agama, siswa[i].kewarganegaraan, siswa[i].anakKe, 
               siswa[i].jumlahSaudara, siswa[i].noTelp);
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
    }

    // Tabel Nilai Siswa
    printf("\n%-4s | %-30s | %-20s | %-15s | %-20s | %-10s | %-11s\n", 
           "No", "Nama", "Bahasa Indonesia", "Matematika", "Bahasa Inggris", "IPA", "Total Nilai");
    printf("---------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < jumlah; i++) {
        printf("%-4d | %-30s | %-20.2lf | %-15.2lf | %-20.2lf | %-10.2lf | %-11.2lf\n", 
               i + 1, siswa[i].nama, siswa[i].nilaiBahasaIndonesia, siswa[i].nilaiMatematika, 
               siswa[i].nilaiBahasaInggris, siswa[i].nilaiIPA, siswa[i].totalNilai);
        printf("-----------------------------------------------------------------------------------------------------------------------------\n");
    }
}

void hitungTotalNilai(Siswa *siswa) {
	siswa->totalNilai = (siswa->nilaiBahasaIndonesia + 
						siswa->nilaiMatematika + 
						siswa->nilaiBahasaInggris + 
						siswa->nilaiIPA) / 4.0;
}