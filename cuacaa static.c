#include <stdio.h>

#define JUMLAH_HARI 7

int main() {
    float suhu[JUMLAH_HARI];
    float total = 0, rataRata, suhuTertinggi, suhuTerendah;

    // Memasukkan suhu harian
    printf("Masukkan suhu untuk %d hari:\n", JUMLAH_HARI);
    for (int i = 0; i < JUMLAH_HARI; i++) {
        printf("Hari %d: ", i + 1);
        scanf("%f", &suhu[i]);
        total += suhu[i];

        // Menentukan suhu tertinggi dan terendah
        if (i == 0) {
            suhuTertinggi = suhu[i];
            suhuTerendah = suhu[i];
        } else {
            if (suhu[i] > suhuTertinggi) {
                suhuTertinggi = suhu[i];
            }
            if (suhu[i] < suhuTerendah) {
                suhuTerendah = suhu[i];
            }
        }
    }

    // Menghitung rata-rata
    rataRata = total / JUMLAH_HARI;

    // Menampilkan hasil
    printf("\nRata-rata suhu: %.2f\n", rataRata);
    printf("Suhu tertinggi: %.2f\n", suhuTertinggi);
    printf("Suhu terendah: %.2f\n", suhuTerendah);

    return 0;
}