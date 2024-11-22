#include <stdio.h>
#include <string.h>

// Fungsi untuk mengonversi angka ke biner
void convertToBinary(int angka, char *binary) {
    int i = 0;
    char temp[50];
    while (angka > 0) {
        temp[i++] = (angka % 2) + '0';
        angka /= 2;
    }
    temp[i] = '\0';

    // Membalikkan urutan biner
    int len = strlen(temp);
    for (int j = 0; j < len; j++) {
        binary[j] = temp[len - j - 1];
    }
    binary[len] = '\0';
}

// Fungsi untuk membuat polinomial dari data biner
void binaryToPolynomial(const char *binary, char *polynomial) {
    int len = strlen(binary);
    polynomial[0] = '\0';
    int firstTerm = 1;

    for (int i = 0; i < len; i++) {
        if (binary[i] == '1') {
            if (!firstTerm) {
                strcat(polynomial, "+");
            }
            if (len - i - 1 == 0) {
                strcat(polynomial, "1");
            } else if (len - i - 1 == 1) {
                strcat(polynomial, "x");
            } else {
                char term[10];
                sprintf(term, "x^%d", len - i - 1);
                strcat(polynomial, term);
            }
            firstTerm = 0;
        }
    }
}

// Fungsi utama
int main() {
    int jumlahNIM, angka;
    char binary[50], polynomial[100];

    // Input jumlah data
    printf("Masukkan jumlah NIM: ");
    scanf("%d", &jumlahNIM);

    // Proses setiap NIM
    for (int i = 0; i < jumlahNIM; i++) {
        printf("\nMasukkan NIM ke-%d: ", i + 1);
        scanf("%d", &angka);

        // Konversi angka ke biner
        convertToBinary(angka, binary);

        // Konversi biner ke polinomial
        binaryToPolynomial(binary, polynomial);

        // Output hasil
        printf("\nHasil untuk NIM ke-%d:\n", i + 1);
        printf("Angka: %d\n", angka);
        printf("Biner: %s\n", binary);
        printf("Polinomial: %s\n", polynomial);
    }

    return 0;
}
