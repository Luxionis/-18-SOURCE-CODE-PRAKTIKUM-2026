#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "segitiga.h"
#include "persegiPanjang.h"
#include "lingkaran.h"
#include "trapesium.h"

/* Prosedur Tampilan Identitas */
void menuPerkenalan(void) {
    system("cls");
    printf("====================================================\n");
    printf("|                  SELAMAT DATANG                  |\n");
    printf("====================================================\n");
    printf("|        PRAKTIKUM ALGORITMA DAN PEMROGRAMAN       |\n");
    printf("|                    TAHUN 2026                    |\n");
    printf("====================================================\n");
}

void menuKelompok(void) {
    printf("=========================================================================\n");
    printf("|                              KELOMPOK 18                              |\n");
    printf("=========================================================================\n");
    printf("| 1. Kadek Tabitha Musume Kireina Wanadharma               260530911138 |\n");
    printf("| 2. I Wayan Damar Rejeki Putra                            260530911053 |\n");
    printf("| 3. I Dewa Ayu Kharisma Candra Kirana                     260530911064 |\n");
    printf("| 4. Kadek Andy Cahya Daniswara                            260530911072 |\n");
    printf("| 5. Thaddeus Marvell Harsono                              260530911108 |\n");
    printf("| 6. Pande Kadek Karlo Dwitiya Bhadrika Yuliartha          260530911125 |\n");
    printf("=========================================================================\n");
}

void tampilkanHeader(const char *judul) {
    menuPerkenalan();
    menuKelompok();
    printf("=========================================================================\n");
    printf("| %-69s |\n", judul);
    printf("=========================================================================\n");
}

/* Fungsi Foolproof: Input Rentang Integer */
int inputIntRentang(const char *prompt, int minVal, int maxVal, const char *judulMenu, void (*tampilkanMenu)(void)) {
    char buffer[256];
    int nilai;
    char ekstra;

    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            continue;
        }

        if (buffer[0] == '\n' || buffer[0] == '\0') {
            printf("\n[ERROR] Input tidak boleh kosong! Tekan sembarang tombol...");
            getch();
            tampilkanHeader(judulMenu);
            if (tampilkanMenu != NULL) tampilkanMenu();
            continue;
        }

        if (sscanf(buffer, "%d %c", &nilai, &ekstra) == 1) {
            if (nilai >= minVal && nilai <= maxVal) {
                return nilai;
            } else {
                printf("\n[ERROR] Pilihan harus antara %d dan %d!\n", minVal, maxVal);
                printf("Tekan sembarang tombol untuk coba lagi...");
                getch();
                tampilkanHeader(judulMenu);
                if (tampilkanMenu != NULL) tampilkanMenu();
            }
        } else {
            printf("\n[ERROR] Masukan harus berupa angka bulat (integer)!\n");
            printf("Tekan sembarang tombol untuk coba lagi...");
            getch();
            tampilkanHeader(judulMenu);
            if (tampilkanMenu != NULL) tampilkanMenu();
        }
    }
}

/* Fungsi Foolproof: Input Double Positif */
double inputDoublePositif(const char *prompt, const char *judulMenu) {
    char buffer[256];
    double nilai;
    char ekstra;

    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            continue;
        }

        if (buffer[0] == '\n' || buffer[0] == '\0') {
            printf("\n[ERROR] Input tidak boleh kosong! Tekan sembarang tombol...");
            getch();
            tampilkanHeader(judulMenu);
            continue;
        }

        if (sscanf(buffer, "%lf %c", &nilai, &ekstra) == 1) {
            if (nilai > 0.0) {
                return nilai;
            } else {
                printf("\n[ERROR] Nilai harus bernilai positif (> 0)!\n");
                printf("Tekan sembarang tombol untuk coba lagi...");
                getch();
                tampilkanHeader(judulMenu);
            }
        } else {
            printf("\n[ERROR] Masukan harus berupa angka numerik valid!\n");
            printf("Tekan sembarang tombol untuk coba lagi...");
            getch();
            tampilkanHeader(judulMenu);
        }
    }
}

void menuPilihanBangunDatar(void) {
    printf("| PILIHAN BANGUN DATAR:                                                 |\n");
    printf("| 1. Segitiga                                                           |\n");
    printf("| 2. Persegi Panjang                                                    |\n");
    printf("| 3. Lingkaran                                                          |\n");
    printf("| 4. Trapesium                                                          |\n");
    printf("| 0. Keluar                                                             |\n");
    printf("=========================================================================\n");
}

int main(void) {
    const char *judul = "PROGRAM PENGHITUNG LUAS & KELILING BANGUN DATAR (MODULAR)";
    int pilihan;

    do {
        tampilkanHeader(judul);
        menuPilihanBangunDatar();
        pilihan = inputIntRentang("Pilih menu [0-4]: ", 0, 4, judul, menuPilihanBangunDatar);

        switch (pilihan) {
            case 1:
                prosesSegitiga();
                break;
            case 2:
                prosesPersegiPanjang();
                break;
            case 3:
                prosesLingkaran();
                break;
            case 4:
                prosesTrapesium();
                break;
            case 0:
                tampilkanHeader("TERIMA KASIH");
                printf("\nProgram selesai. Sampai jumpa!\n");
                printf("Tekan sembarang tombol untuk keluar...");
                getch();
                break;
        }
    } while (pilihan != 0);

    return 0;
}

