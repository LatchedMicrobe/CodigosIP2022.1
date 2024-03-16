#include <stdio.h>
#include <math.h>
#define E 2.7182818285

int main(){

    int exp, numero_termos,fat = 1;
    float e_n, aproximacao;

    e_n = 1;
    aproximacao = 1;

    scanf("%d %d",&exp,&numero_termos);

    e_n = pow(E,exp);

    for(char i = 1; i < numero_termos; i++){

        fat *= i;
        aproximacao += pow(exp, i) / fat;
        printf("%d\n",fat);
        printf("%f\n",aproximacao);

    }
    if(e_n - aproximacao > e_n / 10)
        printf("%.3f\nA aproximacao foi pouco precisa",aproximacao);
    else if(e_n - aproximacao > e_n / 100)
        printf("%.3f\nA aproximacao foi muito precisa",aproximacao);
    else
        printf("%.3f\nOs valores sao praticamente iguais",aproximacao);
}
