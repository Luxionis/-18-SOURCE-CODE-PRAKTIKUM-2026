#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "persegiPanjang.h"

/* Eksternal helper dari main.c */
void tampilkanHeader(const char *judul);
double inputDoublePositif(const char *prompt, const char *judulMenu);

double hitungLuasPersegiPanjang(double panjang, double lebar) {
    return panjang * lebar;
}

double hitungKelilingPersegiPanjang(double panjang, double lebar) {
    return 2.0 * (panjang + lebar);
}

void prosesPersegiPanjang(void) {
    const char *judul = "MENGHITUNG LUAS & KELILING PERSEGI PANJANG";
    tampilkanHeader(judul);

    printf("Masukkan dimensi persegi panjang:\n");
    double panjang = inputDoublePositif("  >> Panjang : ", judul);
    double lebar   = inputDoublePositif("  >> Lebar   : ", judul);

    double luas = hitungLuasPersegiPanjang(panjang, lebar);
    double keliling = hitungKelilingPersegiPanjang(panjang, lebar);

    printf("\n-------------------------------------------------------------------------\n");
    printf("HASIL PERHITUNGAN PERSEGI PANJANG:\n");
    printf("  - Panjang                   : %.2f\n", panjang);
    printf("  - Lebar                     : %.2f\n", lebar);
    printf("  - Luas Persegi Panjang      : %.4f\n", luas);
    printf("  - Keliling Persegi Panjang  : %.4f\n", keliling);
    printf("-------------------------------------------------------------------------\n");
    printf("Tekan sembarang tombol untuk kembali ke menu utama...");
    getch();
}

