#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct {
    char nama[100], kode[20], ISBN[50], genre[50], penulis[100], lokasi_rak[20], status[20];
} Buku;

void klasifikasi();
void laporan();

void klasifikasi() {
    FILE *fp = fopen("permata.txt", "r");
    if (fp == NULL) {
        printf("Gagal membuka file permata.txt!\n");
        return;
    }

    Buku buku;
    int i = 1;

    printf("                                                DAFTAR BUKU PERMATA                                                               \n\n");
    printf("        -------------------------------------------------------------------------------------------------------------\n");
    printf("        | No | Kode Buku |    ISBN     |      Nama Buku         |    Penulis    | Genre   | Lokasi Rak |  Status  |\n");
    printf("        -------------------------------------------------------------------------------------------------------------\n");

    while (fscanf(fp, " %[^,], %[^,], %[^,], %[^,],%[^,], %[^,], %[^\n]\n",
                  buku.kode, buku.ISBN, buku.nama, buku.penulis,
                  buku.genre, buku.lokasi_rak, buku.status) == 7) {

        printf("        | %-2d | %-9s | %-11s | %-22s | %-13s | %-7s | %-10s | %-8s |\n",
               i++, buku.kode, buku.ISBN, buku.nama, buku.penulis,
               buku.genre, buku.lokasi_rak, buku.status);
    }
    printf("        -------------------------------------------------------------------------------------------------------------\n");

    fclose(fp);
}

#include <stdio.h>
#include <string.h>

typedef struct {
    char judul[100];
    int jumlah;
} LogPinjam;

void laporan() {
    FILE *fp = fopen("log_pinjam.txt", "r");
    if (fp == NULL) {
        printf("Gagal membuka file log_pinjam.txt!\n");
        return;
    }

    LogPinjam buku[100];
    int total = 0;
    char temp[100];

    while (fscanf(fp, " %[^\n]", temp) != EOF) {
        int found = 0;
        for (int i = 0; i < total; i++) {
            if (strcmp(buku[i].judul, temp) == 0) {
                buku[i].jumlah++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(buku[total].judul, temp);
            buku[total].jumlah = 1;
            total++;
        }
    }

    fclose(fp);

    printf("                                                LAPORAN PERMATA                                                                 \n\n");
    printf("Bulan: Juni\n\n");
    printf("Stok seluruh buku: 158\n");
    printf("Jumlah buku yang ditambahkan bulan ini: 15\n\n");

    printf("Buku yang pernah dipinjam:\n");
    for (int i = 0; i < total; i++) {
        printf("%d. %s\n", i + 1, buku[i].judul);
    }

    printf("\nBuku yang sering dipinjam:\n");

    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (buku[i].jumlah < buku[j].jumlah) {
                LogPinjam temp = buku[i];
                buku[i] = buku[j];
                buku[j] = temp;
            }
        }
    }

    int top = total < 3 ? total : 3;
    for (int i = 0; i < top; i++) {
        printf("%d. %s\n", i + 1, buku[i].judul);
    }

    printf("\n");
}

