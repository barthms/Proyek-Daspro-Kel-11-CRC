#include <stdio.h>

int main(){
    int angka = 179, i, result[10];

    for (i = 0; angka > 0; i++){
        result[i] = angka % 2;
        angka = angka / 2;
    }

    for (i = i-1; i >= 0; i--){
        printf("%d", result[i]);
    }
    

    return 0;
}
