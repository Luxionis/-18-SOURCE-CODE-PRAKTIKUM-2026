#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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

/* Fungsi Input Foolproof Integer dalam rentang tertentu */
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
            printf("\n[ERROR] Input tidak boleh kosong! Tekan sembarang tombol untuk coba lagi...");
            getch();
            tampilkanHeader(judulMenu);
            if (tampilkanMenu != NULL) tampilkanMenu();
            continue;
        }

        if (sscanf(buffer, "%d %c", &nilai, &ekstra) == 1) {
            if (nilai >= minVal && nilai <= maxVal) {
                return nilai;
            } else {
                printf("\n[ERROR] Masukan harus berada di antara %d sampai %d!\n", minVal, maxVal);
                printf("Tekan sembarang tombol untuk coba lagi...");
                getch();
                tampilkanHeader(judulMenu);
                if (tampilkanMenu != NULL) tampilkanMenu();
            }
        } else {
            printf("\n[ERROR] Input harus berupa angka bulat (integer) yang valid!\n");
            printf("Tekan sembarang tombol untuk coba lagi...");
            getch();
            tampilkanHeader(judulMenu);
            if (tampilkanMenu != NULL) tampilkanMenu();
        }
    }
}

/* Fungsi Input Foolproof Double Sembarang (Bisa negatif, misal suhu di bawah nol) */
double inputDoubleSuhu(const char *prompt, const char *judulMenu) {
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
            // Suhu celsius terendah secara teoritis adalah nol mutlak: -273.15 C
            if (nilai >= -273.15) {
                return nilai;
            } else {
                printf("\n[ERROR] Suhu Celsius tidak boleh lebih rendah dari nol mutlak (-273.15 C)!\n");
                printf("Tekan sembarang tombol untuk coba lagi...");
                getch();
                tampilkanHeader(judulMenu);
            }
        } else {
            printf("\n[ERROR] Input harus berupa angka desimal/numerik yang valid!\n");
            printf("Tekan sembarang tombol untuk coba lagi...");
            getch();
            tampilkanHeader(judulMenu);
        }
    }
}

void menuKonversi(void) {
    printf("| MENU PROGRAM KONVERSI SUHU:                                           |\n");
    printf("| 1. Masukkan Suhu Celsius dan Konversi                                 |\n");
    printf("| 0. Keluar                                                             |\n");
    printf("=========================================================================\n");
}

void prosesKonversiSuhu(void) {
    const char *judul = "PROSES KONVERSI SUHU CELSIUS";
    tampilkanHeader(judul);

    double c = inputDoubleSuhu("Masukkan nilai suhu dalam Celsius (C) [>= -273.15]: ", judul);

    // Rumus konversi:
    // Fahrenheit = (9.0 / 5.0) * C + 32.0
    // Kelvin     = C + 273.15
    // Reamur     = (4.0 / 5.0) * C (tambahan bonus pelengkap)
    double fahrenheit = (9.0 / 5.0) * c + 32.0;
    double kelvin     = c + 273.15;
    double reamur     = (4.0 / 5.0) * c;

    printf("\n-------------------------------------------------------------------------\n");
    printf("HASIL KONVERSI SUHU:\n");
    printf("  - Suhu Asal (Celsius)    : %.2f degC\n", c);
    printf("  - Konversi ke Fahrenheit : %.2f degF\n", fahrenheit);
    printf("  - Konversi ke Kelvin     : %.2f K\n", kelvin);
    printf("  - Konversi ke Reamur     : %.2f degR\n", reamur);
    printf("-------------------------------------------------------------------------\n");
    printf("Tekan sembarang tombol untuk kembali ke menu utama...");
    getch();
}

int main(void) {
    const char *judul = "PROGRAM KONVERSI SUHU CELSIUS KE FAHRENHEIT & KELVIN";
    int pilihan;

    do {
        tampilkanHeader(judul);
        menuKonversi();
        pilihan = inputIntRentang("Pilih menu [0-1]: ", 0, 1, judul, menuKonversi);

        switch (pilihan) {
            case 1:
                prosesKonversiSuhu();
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

