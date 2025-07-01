#include <stdio.h>
#include <string.h>
#define MAKS_CUACA 100

typedef struct {
    char tanggal[20];
    float suhu;
    int kelembapan;
    char kecepatanAngin[50];
} cuaca;

cuaca dataCuaca[MAKS_CUACA];
int totalHari = 0;

void catatCuaca() {
    if (totalHari >= MAKS_CUACA) {
        printf("\nKapasitas data cuaca penuh!\n");
        return;
    }

    cuaca hari;
    printf("\nMasukkan tanggal (DD-MM-YYYY): ");
    scanf("%c", hari.tanggal);
    printf("Masukkan suhu (°C): ");
    scanf("%f", &hari.suhu);
    printf("Masukkan kelembapan (%%): ");
    scanf("%d", &hari.kelembapan);  // corrected %f to %d for int
    printf("Masukkan kecepatan angin (km/jam): ");
    scanf("%c", hari.kecepatanAngin);  // corrected %f to %s for string

    dataCuaca[totalHari++] = hari;
}

void tampilCuaca() {
    if (totalHari == 0) {
        printf("\nTidak ada data cuaca yang dapat ditampilkan.\n");
        return;
    }

    printf("\nTanggal       Suhu (°C)  Kelembapan (%%)  Kecepatan Angin\n");
    for (int i = 0; i < totalHari; i++) {
        printf("%c      %.2f         %d%%           %c\n",
               dataCuaca[i].tanggal, dataCuaca[i].suhu, dataCuaca[i].kelembapan, dataCuaca[i].kecepatanAngin);
    }
}

void hapusDataCuaca() {
    int index;
    printf("\nMasukkan nomor data cuaca yang akan dihapus: ");
    scanf("%d", &index);
    if (index < 1 || index > totalHari) {
        printf("\nData cuaca tidak ditemukan.\n");
        return;
    }

    for (int i = index - 1; i < totalHari - 1; i++) {  // fixed loop range
        dataCuaca[i] = dataCuaca[i + 1];
    }
    totalHari--;
    printf("\nData cuaca berhasil dihapus.\n");
}

int main() {
    int pilihan;
    do {
        printf("\nMenu Cuaca\n");
        printf("[1] Catat data cuaca\n");
        printf("[2] Lihat data cuaca\n");
        printf("[3] Hapus data cuaca\n");
        printf("[9] Keluar\n");
        printf("Pilihan anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                catatCuaca();
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

    return 0;
}
