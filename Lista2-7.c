#include <stdio.h>

int main(){

    int numero = 0, numero_aceito = -1, limite = 0, fatores = 0, n_fatores = 0, contador = 0,contador_Q = 0,checagem_primo;

    scanf("%d %d %d",&numero,&limite,&n_fatores);

    while(numero < limite){

        contador = 0;
        fatores = 0;
        for(short int i = 2; i <= numero; i++){

            if(numero % i == 0){

                checagem_primo = 1;
                for(short int j = 2; j <= i / 2; j++){

                    if(i % j == 0){

                        checagem_primo = 0;
                        break;

                    }
                }

                if(checagem_primo == 1){
                    if(i != 2){
                        if((numero / i) % i == 0){
                            contador = 0;
                            break;
                        }else{
                                contador++;
                        }
                    }
                }
            }
        }

        if(contador == n_fatores && numero_aceito < 0){
            numero_aceito = numero;
        }else if(contador == n_fatores)
            contador_Q++;

        numero++;
    }
    if(numero_aceito < 0)
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.");
    else
        printf("%d %d",numero_aceito,contador_Q);


}
