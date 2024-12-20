/*  Nama File       : 24343022_RAHIMA SARA PANE_STRUCT_C
    Programmer      : Rahima Sara Pane (24343022)
    Tgl. pembuatan  : 15/11/24
    Deskripsi       : Struck data siswa
*/
#include <stdio.h>
#include <string.h>

//definisi tipe struct secara global
struct tanggal
{
    int hari, bulan, tahun;
};

struct mahasiswa
{
    char nama[30];
    int nim;
    struct tanggal tanggal_lahir;
};

// deklarasi variabel data_mahasiswa secara global
struct mahasiswa data_mahasiswa;

int main(){
    // Nama pemrogram
    printf("\tStruck Data Mahasiswa\n");
    printf("\t======================\n\n");
    printf("Nama         : Rahima Sara Pane\n");
    printf("NIM          : 24343022\n");
    printf("Tgl pembuatan: 15/11/24\n\n");

    // mengisi data kedalam variabel struct data_mahasiswa
    strcpy(data_mahasiswa.nama, "Rahima sara pane");
    data_mahasiswa.nim = 24343022;
    data_mahasiswa.tanggal_lahir.hari = 18;
    data_mahasiswa.tanggal_lahir.bulan = 02;
    data_mahasiswa.tanggal_lahir.tahun = 2006;

    // menampilkan data dalam struct data_mahasiswa
    printf("Nama Mahasiswa: %s\n", data_mahasiswa.nama);
    printf("Nomer Induk Mahasiswa: %d\n", data_mahasiswa.nim);
    printf("Tanggal Lahir: %d-%d-%d\n", data_mahasiswa.tanggal_lahir.hari,
           data_mahasiswa.tanggal_lahir.bulan,
           data_mahasiswa.tanggal_lahir.tahun);
}
