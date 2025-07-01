#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char tanggal[20];
    float suhu;
    float kelembapan;
    float kecepatanAngin;
} cuaca;

cuaca *dataCuaca = NULL;
int totalHari = 0;

void catatcuaca() {
    char lagi;
    do {
        cuaca hari;
        printf("\nMasukkan tanggal (DD-MM-YYYY): ");
        scanf("%s", hari.tanggal);
        printf("Masukkan suhu (°C): ");
        scanf("%f", &hari.suhu);
        printf("Masukkan kelembapan (%%): ");
        scanf("%f", &hari.kelembapan);
        printf("Masukkan kecepatan angin (km/jam): ");
        scanf("%f", &hari.kecepatanAngin);

        dataCuaca = realloc(dataCuaca, (totalHari + 1) * sizeof(cuaca));
        if (dataCuaca == NULL) {
            printf("Error allocating memory!\n");
            exit(1);
        }
        dataCuaca[totalHari++] = hari;

        printf("\nApakah ingin menambah data lagi? [y/t]: ");
        getchar(); // Consume newline character
        scanf("%c", &lagi);
    } while (lagi == 'Y' || lagi == 'y');
}

void tampilCuaca() {
    if (totalHari == 0) {
        printf("\nTidak ada data cuaca yang dapat ditampilkan.\n");
        return;
    }
    printf("\nTanggal       Suhu (°C)  Kelembapan (%%)  Kecepatan Angin (km/jam)\n");
    for (int i = 0; i < totalHari; i++) {
        printf("%s      %.2f         %.2f%%           %.2f\n",
               dataCuaca[i].tanggal, dataCuaca[i].suhu, dataCuaca[i].kelembapan, dataCuaca[i].kecepatanAngin);
    }
}

void hapusDataCuaca() {
    free(dataCuaca);
    dataCuaca = NULL;
    totalHari = 0;
    printf("\nData cuaca berhasil dihapus.\n");
}

int main() {
    int pilihan;
    do {
        printf("\nMenu Cuaca\n");
        printf("[1] Catat data cuaca\n");
        printf("[2] Lihat data cuaca\n");
        printf("[3] Hapus semua data cuaca\n");
        printf("[9] Keluar\n");
        printf("Pilihan anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                catatcuaca();
                break;
            case 2:
                tampilCuaca();
                break;
            case 3:
                hapusDataCuaca();
                break;
            case 9:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 9);

    free(dataCuaca);
    return 0;
}
