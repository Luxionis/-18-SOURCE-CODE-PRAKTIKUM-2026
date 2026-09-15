#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define PI 3.14159265358979323846

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

/* Fungsi Input Foolproof: Menerima integer murni dalam rentang [minVal, maxVal] */
int inputIntRentang(const char *prompt, int minVal, int maxVal, const char *judulMenu, void (*tampilkanMenu)(void)) {
    char buffer[256];
    int nilai;
    char ekstra;

    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            continue;
        }

        // Cek jika input newline saja
        if (buffer[0] == '\n' || buffer[0] == '\0') {
            printf("\n[ERROR] Input tidak boleh kosong! Tekan sembarang tombol untuk coba lagi...");
            getch();
            tampilkanHeader(judulMenu);
            if (tampilkanMenu != NULL) tampilkanMenu();
            continue;
        }

        // Validasi parse angka integer murni tanpa karakter ekstra
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

/* Fungsi Input Foolproof: Menerima floating-point positif (> 0) */
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
                printf("\n[ERROR] Nilai harus lebih besar dari 0 (positif)!\n");
                printf("Tekan sembarang tombol untuk coba lagi...");
                getch();
                tampilkanHeader(judulMenu);
            }
        } else {
            printf("\n[ERROR] Input harus berupa angka numerik yang valid!\n");
            printf("Tekan sembarang tombol untuk coba lagi...");
            getch();
            tampilkanHeader(judulMenu);
        }
    }
}

/* Perhitungan Geometri Tabung */
void hitungTabung(void) {
    const char *judul = "MENGHITUNG TABUNG (SILINDER)";
    tampilkanHeader(judul);

    printf("Masukkan dimensi tabung:\n");
    double r = inputDoublePositif("  >> Masukkan jari-jari alas (r) : ", judul);
    double t = inputDoublePositif("  >> Masukkan tinggi tabung (t)   : ", judul);

    double volume = PI * r * r * t;
    double luasSelimut = 2.0 * PI * r * t;
    double luasPermukaan = 2.0 * PI * r * (r + t);

    printf("\n-------------------------------------------------------------------------\n");
    printf("HASIL PERHITUNGAN TABUNG:\n");
    printf("  - Jari-jari alas (r)   : %.2f\n", r);
    printf("  - Tinggi tabung (t)    : %.2f\n", t);
    printf("  - Volume Tabung        : %.4f\n", volume);
    printf("  - Luas Selimut         : %.4f\n", luasSelimut);
    printf("  - Luas Permukaan Total : %.4f\n", luasPermukaan);
    printf("-------------------------------------------------------------------------\n");
    printf("Tekan sembarang tombol untuk kembali ke menu...");
    getch();
}

/* Perhitungan Geometri Bola */
void hitungBola(void) {
    const char *judul = "MENGHITUNG BOLA";
    tampilkanHeader(judul);

    printf("Masukkan dimensi bola:\n");
    double r = inputDoublePositif("  >> Masukkan jari-jari bola (r) : ", judul);

    double volume = (4.0 / 3.0) * PI * r * r * r;
    double luasPermukaan = 4.0 * PI * r * r;

    printf("\n-------------------------------------------------------------------------\n");
    printf("HASIL PERHITUNGAN BOLA:\n");
    printf("  - Jari-jari bola (r)   : %.2f\n", r);
    printf("  - Volume Bola          : %.4f\n", volume);
    printf("  - Luas Permukaan Bola  : %.4f\n", luasPermukaan);
    printf("-------------------------------------------------------------------------\n");
    printf("Tekan sembarang tombol untuk kembali ke menu...");
    getch();
}

/* Perhitungan Geometri Kerucut */
void hitungKerucut(void) {
    const char *judul = "MENGHITUNG KERUCUT";
    tampilkanHeader(judul);

    printf("Masukkan dimensi kerucut:\n");
    double r = inputDoublePositif("  >> Masukkan jari-jari alas (r) : ", judul);
    double t = inputDoublePositif("  >> Masukkan tinggi kerucut (t) : ", judul);

    // Garis pelukis s = sqrt(r^2 + t^2)
    double s = 0.0;
    // Menggunakan hampiran atau formula manual tanpa perlu dependensi math library tambahan
    double sKuadrat = (r * r) + (t * t);
    // Algoritma Newton-Raphson untuk akar kuadrat
    double x = sKuadrat;
    double y = 1.0;
    double e = 0.0000000001;
    while (x - y > e || y - x > e) {
        x = (x + y) / 2.0;
        y = sKuadrat / x;
    }
    s = x;

    double volume = (1.0 / 3.0) * PI * r * r * t;
    double luasSelimut = PI * r * s;
    double luasPermukaan = PI * r * (r + s);

    printf("\n-------------------------------------------------------------------------\n");
    printf("HASIL PERHITUNGAN KERUCUT:\n");
    printf("  - Jari-jari alas (r)   : %.2f\n", r);
    printf("  - Tinggi kerucut (t)   : %.2f\n", t);
    printf("  - Garis Pelukis (s)    : %.4f\n", s);
    printf("  - Volume Kerucut       : %.4f\n", volume);
    printf("  - Luas Selimut Kerucut : %.4f\n", luasSelimut);
    printf("  - Luas Permukaan Total : %.4f\n", luasPermukaan);
    printf("-------------------------------------------------------------------------\n");
    printf("Tekan sembarang tombol untuk kembali ke menu...");
    getch();
}

void menuPilihanBangunRuang(void) {
    printf("| PILIHAN BANGUN RUANG:                                                 |\n");
    printf("| 1. Tabung (Silinder)                                                  |\n");
    printf("| 2. Bola                                                               |\n");
    printf("| 3. Kerucut                                                            |\n");
    printf("| 0. Keluar                                                             |\n");
    printf("=========================================================================\n");
}

int main(void) {
    const char *judul = "PROGRAM PENGHITUNG VOLUME & LUAS PERMUKAAN BANGUN RUANG";
    int pilihan;

    do {
        tampilkanHeader(judul);
        menuPilihanBangunRuang();
        pilihan = inputIntRentang("Pilih opsi [0-3]: ", 0, 3, judul, menuPilihanBangunRuang);

        switch (pilihan) {
            case 1:
                hitungTabung();
                break;
            case 2:
                hitungBola();
                break;
            case 3:
                hitungKerucut();
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

