#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "trapesium.h"

/* Eksternal helper dari main.c */
void tampilkanHeader(const char *judul);
double inputDoublePositif(const char *prompt, const char *judulMenu);

double hitungLuasTrapesium(double a, double b, double t) {
    return 0.5 * (a + b) * t;
}

double hitungKelilingTrapesium(double a, double b, double c, double d) {
    return a + b + c + d;
}

void prosesTrapesium(void) {
    const char *judul = "MENGHITUNG LUAS & KELILING TRAPESIUM";
    tampilkanHeader(judul);

    printf("Masukkan parameter trapesium:\n");
    double a = inputDoublePositif("  >> Panjang sisi sejajar 1 (a) : ", judul);
    double b = inputDoublePositif("  >> Panjang sisi sejajar 2 (b) : ", judul);
    double t = inputDoublePositif("  >> Tinggi trapesium (t)       : ", judul);

    printf("\nMasukkan keempat sisi trapesium untuk menghitung keliling:\n");
    printf("  (Sisi sejajar 1 = %.2f, Sisi sejajar 2 = %.2f)\n", a, b);
    double c = inputDoublePositif("  >> Panjang sisi miring 1 (c)  : ", judul);
    double d = inputDoublePositif("  >> Panjang sisi miring 2 (d)  : ", judul);

    double luas = hitungLuasTrapesium(a, b, t);
    double keliling = hitungKelilingTrapesium(a, b, c, d);

    printf("\n-------------------------------------------------------------------------\n");
    printf("HASIL PERHITUNGAN TRAPESIUM:\n");
    printf("  - Sisi Sejajar (a, b) : %.2f dan %.2f\n", a, b);
    printf("  - Tinggi Trapesium    : %.2f\n", t);
    printf("  - Sisi Miring (c, d)  : %.2f dan %.2f\n", c, d);
    printf("  - Luas Trapesium      : %.4f\n", luas);
    printf("  - Keliling Trapesium  : %.4f\n", keliling);
    printf("-------------------------------------------------------------------------\n");
    printf("Tekan sembarang tombol untuk kembali ke menu utama...");
    getch();
}

