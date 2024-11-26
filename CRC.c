#include <stdio.h>
#include<string.h>

int binner(int angka, int result[]){
    int i;
    for (i = 0; angka > 0; i++){
        result[i] = angka % 2;
        angka = angka / 2;
    }
    
    return i;
}

void polynominal (int result[], int panjang){
    int kondisi = 1;
    for (int i = panjang - 1; i >= 0; i--){
        if (result[i] == 1){
            if (!kondisi){
                printf("+");
            }
            if (i == 0){
                printf("1");
            }else if(i == 1){
                printf("x");
            }else{
                printf("x^%d", i);
            }
            kondisi = 0;
        }
        
    }
}

int main(){
    int angka, result[32];
    int panjang;

    printf("Masukan angka Anda :");
    scanf("%d", &angka);

    panjang = binner(angka, result);

    printf("Biner dari %d adalah :", angka);
    for (int i = panjang - 1; i >= 0; i--){
        printf("%d", result[i]);
    }
    printf("\n");

    printf("Polynominal dari %d adalah :", angka);
    polynominal(result, panjang);

    return 0;
}
