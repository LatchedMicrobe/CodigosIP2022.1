#include <stdio.h>

int main(){

    int int_inicio, int_final, primo, primo_anterior, primo_posterior,checagem_primo,checagem_primo_ant,checagem_primo_post,aux,i,j,k,cnt = 0;

    scanf("%d %d",&int_inicio,&int_final);

    while(int_inicio <= int_final){

        checagem_primo = 1;

        for(i = 2; i <= int_inicio / 2; i++){

            if(int_inicio % i == 0){

                checagem_primo = 0;

                break;

            }
        }
        if(checagem_primo == 1 && int_inicio > 1){

            primo = int_inicio;
            aux = primo;
            printf("Primo: %d\n",primo);
            primo_anterior = 0;
            primo_posterior = 0;

            while(primo_anterior == 0){

                aux--;
                if(aux == 1)
                    break;
                else
                    checagem_primo_ant = 1;

                for(j = 2; j <= aux / 2; j++){

                    if(aux % j == 0){

                        checagem_primo_ant = 0;

                        break;

                    }
                }
                if(checagem_primo_ant == 1 && aux > 1){

                    primo_anterior = aux;

                    printf("Primo anterior: %d\n",primo_anterior);
                }
            }

            aux = primo;

            while(primo_posterior == 0){

                aux++;
                if(aux == 1)
                    break;
                else
                    checagem_primo_post = 1;

                for(k = 2; k <= aux / 2; k++){

                    if(aux % k == 0){

                        checagem_primo_post = 0;

                        break;

                    }
                }
                if(checagem_primo_post == 1 && aux > 1){

                    primo_posterior = aux;

                    printf("Primo posterior: %d\n",primo_posterior);
                }
            }
        if(primo == (primo_anterior + primo_posterior) / 2 && primo >= 5)
                cnt++;
        }

        int_inicio++;
    }

    printf("Primos de Zeca: %d",cnt);
}
