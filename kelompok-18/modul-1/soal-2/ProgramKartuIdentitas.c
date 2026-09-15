#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

/* Fungsi Helper Input String Tanpa Kosong dan Membersihkan Trailing Newline */
void inputStringWajib(const char *prompt, char *dest, int maxLen, const char *judul) {
    char buffer[256];
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            continue;
        }

        // Hapus trailing newline / carriage return
        buffer[strcspn(buffer, "\r\n")] = '\0';

        // Cek apakah string hanya berisi spasi kosong
        int semuaSpasi = 1;
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (!isspace((unsigned char)buffer[i])) {
                semuaSpasi = 0;
                break;
            }
        }

        if (strlen(buffer) == 0 || semuaSpasi) {
            printf("\n[ERROR] Input teks tidak boleh kosong! Tekan sembarang tombol...");
            getch();
            tampilkanHeader(judul);
            continue;
        }

        strncpy(dest, buffer, maxLen - 1);
        dest[maxLen - 1] = '\0';
        break;
    }
}

/* Fungsi Input Foolproof Nilai Akademik (0.00 - 100.00) */
double inputNilaiAkademik(const char *prompt, const char *judul) {
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
            tampilkanHeader(judul);
            continue;
        }

        if (sscanf(buffer, "%lf %c", &nilai, &ekstra) == 1) {
            if (nilai >= 0.0 && nilai <= 100.0) {
                return nilai;
            } else {
                printf("\n[ERROR] Nilai harus berada dalam rentang 0.00 sampai 100.00!\n");
                printf("Tekan sembarang tombol untuk coba lagi...");
                getch();
                tampilkanHeader(judul);
            }
        } else {
            printf("\n[ERROR] Masukan nilai harus berupa angka yang valid!\n");
            printf("Tekan sembarang tombol untuk coba lagi...");
            getch();
            tampilkanHeader(judul);
        }
    }
}

/* Fungsi Input Integer Menu Pilihan */
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

/* Fungsi Konversi Nilai Angka ke Huruf dan Status Kelulusan */
void konversiGrade(double nilaiAkhir, char *grade, char *status) {
    if (nilaiAkhir >= 85.0) {
        strcpy(grade, "A");
        strcpy(status, "LULUS DENGAN SANGAT BAIK");
    } else if (nilaiAkhir >= 75.0) {
        strcpy(grade, "B+");
        strcpy(status, "LULUS DENGAN BAIK");
    } else if (nilaiAkhir >= 65.0) {
        strcpy(grade, "B");
        strcpy(status, "LULUS");
    } else if (nilaiAkhir >= 55.0) {
        strcpy(grade, "C+");
        strcpy(status, "LULUS CUKUP");
    } else if (nilaiAkhir >= 50.0) {
        strcpy(grade, "C");
        strcpy(status, "LULUS KURANG");
    } else if (nilaiAkhir >= 40.0) {
        strcpy(grade, "D");
        strcpy(status, "TIDAK LULUS");
    } else {
        strcpy(grade, "E");
        strcpy(status, "TIDAK LULUS");
    }
}

void inputDanCetakKartu(void) {
    const char *judul = "INPUT DATA PRAKTIKAN & CETAK KARTU IDENTITAS";
    tampilkanHeader(judul);

    char nama[100];
    char nim[30];
    char kelas[20];
    char kelompok[20];
    double nilaiTugas, nilaiUTS, nilaiUAS;

    printf("Silakan masukkan identitas dan komponen nilai praktikan:\n\n");
    inputStringWajib("  >> Nama Lengkap Praktikan : ", nama, sizeof(nama), judul);
    inputStringWajib("  >> NIM                    : ", nim, sizeof(nim), judul);
    inputStringWajib("  >> Kelas Praktikum        : ", kelas, sizeof(kelas), judul);
    inputStringWajib("  >> Kelompok               : ", kelompok, sizeof(kelompok), judul);
    printf("\n  [Komponen Penilaian Berbobot: Tugas 20%%, UTS 35%%, UAS 45%%]\n");
    nilaiTugas = inputNilaiAkademik("  >> Masukkan Nilai Tugas (0-100) : ", judul);
    nilaiUTS   = inputNilaiAkademik("  >> Masukkan Nilai UTS   (0-100) : ", judul);
    nilaiUAS   = inputNilaiAkademik("  >> Masukkan Nilai UAS   (0-100) : ", judul);

    // Perhitungan Nilai Akhir
    double bobotTugas = 0.20 * nilaiTugas;
    double bobotUTS   = 0.35 * nilaiUTS;
    double bobotUAS   = 0.45 * nilaiUAS;
    double nilaiAkhir = bobotTugas + bobotUTS + bobotUAS;

    char grade[5];
    char status[50];
    konversiGrade(nilaiAkhir, grade, status);

    // Tampilan Kartu Identitas & Statistik Akademik Terformat Rapi
    system("cls");
    tampilkanHeader("KARTU IDENTITAS PRAKTIKAN & STATISTIK AKADEMIK");
    printf("\n");
    printf("  +---------------------------------------------------------------------+\n");
    printf("  |                     KARTU HASIL STUDI PRAKTIKUM                     |\n");
    printf("  +---------------------------------------------------------------------+\n");
    printf("  | Nama Lengkap    : %-49s |\n", nama);
    printf("  | Nomor Induk Mhs : %-49s |\n", nim);
    printf("  | Kelas           : %-49s |\n", kelas);
    printf("  | Kelompok        : %-49s |\n", kelompok);
    printf("  +---------------------------------------------------------------------+\n");
    printf("  |                   RINCIAN STATISTIK PENILAIAN                       |\n");
    printf("  +--------------------------+--------+-------------+-------------------+\n");
    printf("  | Komponen Evaluasi        | Bobot  | Nilai Mentah| Nilai Terbobot    |\n");
    printf("  +--------------------------+--------+-------------+-------------------+\n");
    printf("  | 1. Tugas & Kuis          |  20%%   |   %6.2f    |       %6.2f      |\n", nilaiTugas, bobotTugas);
    printf("  | 2. Ujian Tengah Semester |  35%%   |   %6.2f    |       %6.2f      |\n", nilaiUTS, bobotUTS);
    printf("  | 3. Ujian Akhir Semester  |  45%%   |   %6.2f    |       %6.2f      |\n", nilaiUAS, bobotUAS);
    printf("  +--------------------------+--------+-------------+-------------------+\n");
    printf("  | NILAI AKHIR KUMULATIF    : %6.2f / 100.00                             |\n", nilaiAkhir);
    printf("  | INDEKS PRESTASI / GRADE  : %-48s |\n", grade);
    printf("  | STATUS KELULUSAN         : %-48s |\n", status);
    printf("  +---------------------------------------------------------------------+\n");
    printf("\nTekan sembarang tombol untuk kembali ke menu utama...");
    getch();
}

void menuPilihan(void) {
    printf("| MENU PROGRAM KARTU IDENTITAS:                                         |\n");
    printf("| 1. Masukkan Data Praktikan & Cetak Kartu                              |\n");
    printf("| 0. Keluar                                                             |\n");
    printf("=========================================================================\n");
}

int main(void) {
    const char *judul = "PROGRAM KARTU IDENTITAS & STATISTIK AKADEMIK PRAKTIKAN";
    int pilihan;

    do {
        tampilkanHeader(judul);
        menuPilihan();
        pilihan = inputIntRentang("Pilih menu [0-1]: ", 0, 1, judul, menuPilihan);

        switch (pilihan) {
            case 1:
                inputDanCetakKartu();
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

