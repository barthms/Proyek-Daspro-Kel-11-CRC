#include <stdio.h>
#include <string.h>

int binner(int nim, int result[]) {
    int i;
    for (i = 0; nim > 0; i++) {
        result[i] = nim % 2;
        nim = nim / 2;
    }
    return i;
}

int polynominal(int result[], int panjang, FILE *keluaran) {
    int kondisi = 1;
    for (int i = panjang - 1; i >= 0; i--) {
        if (result[i] == 1) {
            if (!kondisi) {
                fprintf(keluaran, "+");
            }
            if (i == 0) {
                fprintf(keluaran, "1");
            } else if (i == 1) {
                fprintf(keluaran, "x");
            } else {
                fprintf(keluaran, "x^%d", i);
            }
            kondisi = 0;
        }
    }
    return kondisi;
}

int generatePrimitivePolynomial(int result[], int panjang, int resultPrimitif[]) {
    int i, n = 0;

    // Cari derajat tertinggi (bit 1 paling kiri)
    for (i = panjang - 1; i >= 0; i--) {
        if (result[i] == 1) {
            n = i;
            break;
        }
    }

    // Buat primitive polynomial dengan mengurangi "1 dari depan"
    for (i = 0; i < panjang; i++) {
        resultPrimitif[i] = (i == n) ? 0 : result[i];
    }

    return panjang;
}

void crcTransmission(int data[], int panjang, int divisor[], int divisorLength, int crc[]) {
    int temp[64] = {0};
    memcpy(temp, data, panjang * sizeof(int));

    for (int i = 0; i < divisorLength - 1; i++) {
        temp[panjang + i] = 0;  // Tambahkan 0 untuk CRC.
    }

    for (int i = 0; i < panjang; i++) {
        if (temp[i] == 1) {  // XOR hanya jika bit saat ini adalah 1.
            for (int j = 0; j < divisorLength; j++) {
                temp[i + j] ^= divisor[j];
            }
        }
    }

    for (int i = 0; i < divisorLength - 1; i++) {
        crc[i] = temp[panjang + i];
    }
}

void printBinary(FILE *output, int data[], int length) {
    for (int i = length - 1; i >= 0; i--) {
        fprintf(output, "%d", data[i]);
    }
}

int main() {
    int nim, result[32];
    int panjang, panjangPrimitif;
    int resultPrimitif[32], crc[32];
    FILE *inputan, *outputan;

    inputan = fopen("input.txt", "r");
    if (inputan == NULL) {
        printf("Gagal membuka file input.txt\n");
        return 1;
    }

    outputan = fopen("output.txt", "w");
    if (outputan == NULL) {
        printf("Gagal membuka file output.txt\n");
        fclose(inputan);
        return 1;
    }

    fprintf(outputan, "*********PROGRAM CRC*********\n");
    fprintf(outputan, "-------------------------------------\n");

    while (fscanf(inputan, "%d", &nim) != EOF) {
        fprintf(outputan, "NIM: %d\n", nim);

        // Mengkonversi NIM ke biner
        panjang = binner(nim, result);
        fprintf(outputan, "Binary: ");
        printBinary(outputan, result, panjang);
        fprintf(outputan, "\n");

        // Mengkonversi biner ke polynomial
        fprintf(outputan, "Polynomial: ");
        polynominal(result, panjang, outputan);
        fprintf(outputan, "\n");

        // Generate primitive polynomial
        panjangPrimitif = generatePrimitivePolynomial(result, panjang, resultPrimitif);
        fprintf(outputan, "Primitive Polynomial: ");
        polynominal(resultPrimitif, panjangPrimitif, outputan);
        fprintf(outputan, "\n");

        // Konversi primitive polynomial ke biner
        fprintf(outputan, "Primitive Polynomial Binary: ");
        printBinary(outputan, resultPrimitif, panjangPrimitif);
        fprintf(outputan, "\n");

        // Operasi CRC
        crcTransmission(result, panjang, resultPrimitif, panjangPrimitif, crc);
        fprintf(outputan, "CRC Result: ");
        printBinary(outputan, crc, panjangPrimitif - 1);
        fprintf(outputan, "\n");

        fprintf(outputan, "-------------------------------\n");
    }

    fclose(inputan);
    fclose(outputan);

    printf("Program selesai. Hasil tersimpan di output.txt\n");
    return 0;
}
