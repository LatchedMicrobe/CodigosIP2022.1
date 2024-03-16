#include <stdio.h>

int main(){

    int dia,mes,ano;
    scanf("%d %d %d",&dia,&mes,&ano);


    if(ano>=1900 && ano <= 2100){
        if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){

            if(dia >= 1 && dia <= 31){
                printf("valida");
            }else{
                printf("invalida");
            }

        }else if(mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11){

            if(mes != 2){
                if(dia >= 1 && dia <= 30){
                    printf("valida");
                }else{
                    printf("invalida");
                }
            }else{
                if(ano % 4 == 0 && ((ano % 100 != 0) || (ano % 400 == 0))){
                    if(dia >= 1 && dia <= 29){
                        printf("valida");
                    }else{
                        printf("invalida");
                    }
                }else if(dia >= 1 && dia <= 28){
                    printf("valida");
                }else{
                    printf("invalida");
                }
            }
        }else{
            printf("invalida");
        }
    }else{
        printf("invalida");
    }
}
