#include <stdio.h>
#include<string.h>

int binner(int nim, int result[]){
    int i;
    for (i = 0; nim > 0; i++){
        result[i] = nim % 2;
        nim = nim / 2;
    }
    
    return i;
}

int polynominal (int result[], int panjang, FILE *keluaran){
    int kondisi = 1;
    for (int i = panjang - 1; i >= 0; i--){
        if (result[i] == 1){
            if (!kondisi){
                fprintf(keluaran, "+");
            }
            if (i == 0){
                fprintf(keluaran, "1");
            }else if(i == 1){
                fprintf(keluaran, "x");
            }else{
                fprintf(keluaran ,"x^%d", i);
            }
            kondisi = 0;
        }
        
    }
    return kondisi;
}

int primitif(int result[], int panjang, int resultPrimitif[]){
    int n = 0;
    for (int i = panjang - 1; i >= 0; i--){
        if (result[i] == 1){
            n = i;
            break;
        }
    }

    for (int i = 0; i < panjang; i++){
        if (i == n){
            resultPrimitif[i] = 0;
        }else{
            resultPrimitif[i] = result[i];
        }
        
    }
    return panjang;
}



int main(){
    int nim, result[32]; 
    int panjang, panjangPrimitif;
    int resultPrimitif[32];
    FILE *inputan, *outputan;

    inputan = fopen("input.txt", "r");
    if (inputan == NULL){
        printf("Gagal membuka file input.txt\n");
        return 1;
    }
    
    outputan = fopen("output.txt", "w");

    fprintf(outputan, "*********PROGRAM CRC*********\n");
    fprintf(outputan, "-------------------------------\n");

    while(fscanf(inputan, "%d", &nim) != EOF){
        fprintf(outputan, "NIM: %d\n", nim);

        // Mengkonversi nim ke biner
        panjang = binner(nim, result);
        fprintf(outputan, "Binary: ");
        for (int i = panjang - 1; i >= 0; i--){
            fprintf(outputan, "%d", result[i]);
        }
        fprintf(outputan, "\n");

        // Mengkonversi biner ke polynomial 
        fprintf(outputan, "Polynomial :");
        polynominal(result, panjang, outputan);
        fprintf(outputan, "\n-------------------------------\n");

    }
    

    return 0;
}
