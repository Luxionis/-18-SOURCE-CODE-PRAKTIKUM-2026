#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lingkaran.h"

/* Eksternal helper dari main.c */
void tampilkanHeader(const char *judul);
double inputDoublePositif(const char *prompt, const char *judulMenu);

double hitungLuasLingkaran(double r) {
    return PI * r * r;
}

double hitungKelilingLingkaran(double r) {
    return 2.0 * PI * r;
}

void prosesLingkaran(void) {
    const char *judul = "MENGHITUNG LUAS & KELILING LINGKARAN";
    tampilkanHeader(judul);

    printf("Masukkan dimensi lingkaran:\n");
    double r = inputDoublePositif("  >> Jari-jari lingkaran (r) : ", judul);

    double luas = hitungLuasLingkaran(r);
    double keliling = hitungKelilingLingkaran(r);

    printf("\n-------------------------------------------------------------------------\n");
    printf("HASIL PERHITUNGAN LINGKARAN:\n");
    printf("  - Jari-jari lingkaran (r) : %.2f\n", r);
    printf("  - Diameter (d)            : %.2f\n", 2.0 * r);
    printf("  - Luas Lingkaran          : %.4f\n", luas);
    printf("  - Keliling Lingkaran      : %.4f\n", keliling);
    printf("-------------------------------------------------------------------------\n");
    printf("Tekan sembarang tombol untuk kembali ke menu utama...");
    getch();
}

