#include <stdio.h>
#include<string.h>

int main(){
    int angka = 179, i, result[10];
    int polynominal, kondisi = 1;

    for (i = 0; angka > 0; i++){
        result[i] = angka % 2;
        angka = angka / 2;
        printf("%d", result[i]);
    }
    polynominal = i;    //Mengetahui array terakhir pada result yang digunakan pada polynominal

    printf("\nMembalikkan array agar menjadi biner :\n");
    for (i = i - 1; i >= 0; i--){
        printf("%d", result[i]);
    }

    printf("\nMenghitung Polynominalnya :\n");

    for (i = polynominal ; i >= 0; i--){
        if (result[i] == 1){        // membaca dan membuat polygon jika array bernilai 1
            if (!kondisi){
                printf("+");
            }
            if (i == 0) {           // menentukan array terakhir bahwa x^0 = 1
                printf("1"); 
            } else if (i == 1) {    // menentukan array ke 2 dari belakang adalah x^1 = x
                printf("x"); 
            } else {                // membuat polygon sesuai dengan arraynya
                printf("x^%d", i); 
            }
            kondisi = 0;            // mereset ulang bahwa nilai dari kondisi = 0
        }
    }

    return 0;
}
