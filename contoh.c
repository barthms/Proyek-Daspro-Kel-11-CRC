#include <stdio.h>

int main()
{
    int angka = 179, i, result[10];
    int polynominal, kondisi = 1;

    for (i = 0; angka > 0; i++)
    {
        result[i] = angka % 2;
        angka = angka / 2;
        printf("%d", result[i]);
    }

    printf("\n");
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", result[i]);
    }

    printf("\n");

    for (i = 9; i >= 0; i--){
        
        if (result[i] == 1){
            if (!kondisi){
                printf("+");
            }
            printf("x^%d", i);
        }
            kondisi = 0;
    }

    return 0;
}
