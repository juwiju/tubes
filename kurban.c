#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nama[50];
    char kategori[10]; 
} Pengkurban;
Pengkurban kurban;
int jumlahPengkurban;

typedef struct {
    int jumlahSapi;
    int beratSapi; 
    int jmlPengkurbanSapi;
    float dagingPerPengkurbanSapi;
    
    int jumlahKambing;
    int beratKambing; 
    int jmlPengkurbanKambing;
    float dagingPerPengkurbanKambing;
    
    int jumlahWarga;
    float dagingPerWarga;
    
    int jumlahFakirMiskin;
    float dagingPerFakirMiskin;
} Panitia;
Panitia data, editData;

typedef struct {
    int jumlahWarga;
    int jumlahFakirMiskin;
} Warga;
Warga warga;

int i=0, pilih, nomorTarget, nomor;
void pengkurban ();
void pengkurban () {
    char merata[5], tambah[5];
    do {
        printf ("==================================================\n\n");
        printf ("-------------------- DASHBOARD -------------------\n");
        printf ("1. Tambah data\n");
        printf ("2. Edit data\n");
        printf ("3. Keluar\n\n");

        printf ("Pilihan anda: \n");
        scanf ("%d", &pilih);
        printf ("==================================================\n\n");

        if (pilih == 1) {
            FILE *file = fopen("adha.txt", "a+");

            // Hitung jumlah baris di file untuk menentukan nomor urut awal
            int nomorUrut = 1;
            char line[100];
            FILE *count = fopen("adha.txt", "r");
            while (fgets(line, sizeof(line), count) != NULL) {
                if (strlen(line) > 1) nomorUrut++; // Hindari baris kosong
            }
            fclose(count);

            printf ("==================================================\n\n");
            printf ("------------------- Tambah Data ------------------\n");

            do {
                printf("Kategori hewan (sapi/kambing): ");
                scanf("%s", kurban.kategori);

                printf("Jumlah pengkurban: ");
                scanf("%d", &jumlahPengkurban);

                for (i = 0; i < jumlahPengkurban; i++) {
                    printf("Masukkan nama pengkurban %d: ", i + 1);
                    scanf("%s", kurban.nama);

                    fprintf(file, "%d %s %s\n", nomorUrut, kurban.kategori, kurban.nama);
                    nomorUrut++; // Naikkan nomor urut untuk pengkurban berikutnya
                }

                printf("Tambah hewan lagi? (y/n): ");
                scanf("%s", tambah);
            } while (strcmp(tambah, "y") == 0);

            fclose(file);

            // Tampilkan data hasil input
            file = fopen("adha.txt", "r");
            printf("\n------------------ Data Pengkurban -----------------\n");
            printf("Nomor \tKategori Hewan \tNama Pengkurban\n");
            printf("-----------------------------------------------------\n");

            while (fscanf(file, "%d %s %s", &nomor, kurban.kategori, kurban.nama) == 3) {
                printf("%d \t%s \t\t%s\n", nomor, kurban.kategori, kurban.nama);
            }

            printf("-----------------------------------------------------\n");
            fclose(file);

        } else if (pilih == 2) {
            FILE *file = fopen ("adha.txt", "r");
            FILE *new = fopen ("new.txt", "w+");

            printf ("==================================================\n\n");
            printf ("-------------------- Edit Data -------------------\n");

            printf ("Data mana yang ingin di edit? \n");
            printf ("1. Data kurban sapi\n");
            printf ("2. Data kurban kambing\n");

            printf ("Pilihan anda: \n");
            scanf ("%d", &pilih);

            if (pilih == 1){
                rewind(file);
                printf("\n------------------ Data Pengkurban Sapi -----------------\n");
                printf("Nomor \tKategori Hewan \tNama Pengkurban\n");
                printf("----------------------------------------------------------\n");

                while (fscanf(file, "%d %s %s", &nomor, kurban.kategori, kurban.nama) == 3) {
                    if (strcmp(kurban.kategori, "sapi") == 0) {
                        printf("%d \t%s \t\t%s\n", nomor, kurban.kategori, kurban.nama);
                    }
                }
                printf("----------------------------------------------------------\n");

                printf ("------------- Edit Data Pengkurban Sapi-------------\n");
                printf ("1. Edit nama\n");
                printf ("2. Hapus data\n");

                printf ("Pilihan anda: \n");
                scanf ("%d", &pilih);

                if (pilih == 1){
                    rewind(file); 
                    printf ("Masukkan nomor yang ingin di edit \n");
                    scanf ("%d", &nomorTarget);

                    while (fscanf(file, "%d %s %s", &nomor, kurban.kategori, kurban.nama) == 3) { 
                        if(nomor == nomorTarget && strcmp(kurban.kategori, "sapi") == 0){ 
                            printf("Nama baru:"); 
                            scanf("%s",kurban.nama);
                        }
                            fprintf(new, "%d %s %s\n", nomor, kurban.kategori, kurban.nama); 
                
                    }
                        
                    printf("Data berhasil diubah.\n");
                } else if (pilih == 2){
                    rewind(file); 
                    printf ("Masukkan nomor yang ingin di edit \n");
                    scanf ("%d", &nomorTarget);

                    while (fscanf(file, "%d %s %s", &nomor, kurban.kategori, kurban.nama) == 3) { 
                        if(nomor != nomorTarget && strcmp(kurban.kategori, "sapi") == 0){ 
                            fprintf(new, "%d %s %s\n", nomor, kurban.kategori, kurban.nama); 
                        }
                    }
                    printf("Data berhasil dihapus.\n");
                }
                printf ("==================================================\n\n");
            
                fclose(file);
                fclose(new);
                remove("adha.txt");
                rename("new.txt", "adha.txt");

            } else if (pilih == 2) {
                rewind(file);
                printf("\n------------------ Data Pengkurban Sapi -----------------\n");
                printf("Nomor \tKategori Hewan \tNama Pengkurban\n");
                printf("----------------------------------------------------------\n");

                while (fscanf(file, "%d %s %s", &nomor, kurban.kategori, kurban.nama) == 3) {
                    if (strcmp(kurban.kategori, "kambing") == 0) {
                        printf("%d \t%s \t\t%s\n", nomor, kurban.kategori, kurban.nama);
                    }
                }
                printf("----------------------------------------------------------\n");

                printf ("------------- Edit Data Pengkurban Kambing --------------\n");
                printf ("1. Edit nama\n");
                printf ("2. Hapus data\n");

                printf ("Pilihan anda: \n");
                scanf ("%d", &pilih);

                if (pilih == 1){
                    rewind(file); 
                    printf ("Masukkan nomor yang ingin di edit \n");
                    scanf ("%d", &nomorTarget);

                    while (fscanf(file, "%d %s %s", &nomor, kurban.kategori, kurban.nama) == 3) { 
                        if(nomor == nomorTarget && strcmp(kurban.kategori, "kambing") == 0){ 
                            printf("Nama baru:"); 
                            scanf("%s",kurban.nama);
                        }
                            fprintf(new, "%d %s %s\n", nomor, kurban.kategori, kurban.nama); 
                
                    }
                        
                    printf("Data berhasil diubah.\n");
                } else if (pilih == 2){
                    rewind(file); 
                    printf ("Masukkan nomor yang ingin di edit \n");
                    scanf ("%d", &nomorTarget);

                    while (fscanf(file, "%d %s %s", &nomor, kurban.kategori, kurban.nama) == 3) { 
                        if(nomor != nomorTarget && strcmp(kurban.kategori, "kambing") == 0){ 
                            fprintf(new, "%d %s %s\n", nomor, kurban.kategori, kurban.nama); 
                        }
                    }
                    printf("Data berhasil dihapus.\n");
                }
                printf ("==================================================\n\n");
            
                fclose(file);
                fclose(new);
                remove("adha.txt");
                rename("new.txt", "adha.txt");
            }
        }
    } while (pilih != 3);
    printf ("==================================================\n\n");
    printf ("------------------ Terimakasih -------------------\n");
    printf ("==================================================\n\n");

}

int main () {
    pengkurban ();
    return 0;
    
}
//
