#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "segitiga.h"

/* Eksternal helper dari main.c */
void tampilkanHeader(const char *judul);
double inputDoublePositif(const char *prompt, const char *judulMenu);

double hitungLuasSegitiga(double alas, double tinggi) {
    return 0.5 * alas * tinggi;
}

double hitungKelilingSegitiga(double sisiA, double sisiB, double sisiC) {
    return sisiA + sisiB + sisiC;
}

void prosesSegitiga(void) {
    const char *judul = "MENGHITUNG LUAS & KELILING SEGITIGA";
    tampilkanHeader(judul);

    printf("Masukkan parameter segitiga:\n");
    double alas = inputDoublePositif("  >> Panjang Alas   : ", judul);
    double tinggi = inputDoublePositif("  >> Tinggi         : ", judul);
    printf("\nMasukkan ketiga panjang sisi segitiga untuk menghitung keliling:\n");
    double sisiA = inputDoublePositif("  >> Sisi A         : ", judul);
    double sisiB = inputDoublePositif("  >> Sisi B         : ", judul);
    double sisiC = inputDoublePositif("  >> Sisi C         : ", judul);

    double luas = hitungLuasSegitiga(alas, tinggi);
    double keliling = hitungKelilingSegitiga(sisiA, sisiB, sisiC);

    printf("\n-------------------------------------------------------------------------\n");
    printf("HASIL PERHITUNGAN SEGITIGA:\n");
    printf("  - Alas Segitiga      : %.2f\n", alas);
    printf("  - Tinggi Segitiga    : %.2f\n", tinggi);
    printf("  - Sisi A, B, C       : %.2f, %.2f, %.2f\n", sisiA, sisiB, sisiC);
    printf("  - Luas Segitiga      : %.4f\n", luas);
    printf("  - Keliling Segitiga  : %.4f\n", keliling);
    printf("-------------------------------------------------------------------------\n");
    printf("Tekan sembarang tombol untuk kembali ke menu utama...");
    getch();
}

