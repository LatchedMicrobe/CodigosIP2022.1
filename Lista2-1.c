#include <stdio.h>

int main(){

    //1 Declarar variaveis
    char maximo_linha, input, linhas;
    short int elementos, aux;

    //2 Pegar input
    scanf("%c",&input);

    //3 Fazer a operação que contem o numero de linhas(começando de 0) e a operação do numero de elementos total
    linhas = (input - 65);
    elementos = 2 * (linhas + 1) - 1;
    aux = linhas;
    //4 Fazer um loop que imprima as linhas na tela
    for(char i = 0; i <= linhas; i++){

        maximo_linha = 65 + i;
        //4.1 Fazer um loop que imprima pontos até chegarmos no momento de imprimir a letra(s) desejada(s)
        for(char j = 0; j < aux; j++){
            printf(".");
        }

        //4.2 Fazer um loop que imprima de A até o maximo na linha
        for(char letra = 65; letra <= maximo_linha; letra++){
            printf("%c",letra);
        }

        //4.3 Fazer um loop que imprima do maximo da linha até A
        while(maximo_linha > 65){
            printf("%c",maximo_linha - 1);
            maximo_linha--;
        }

        //4.4 Fazer um loop que imprima pontos da letra desejada até o final da linha
        for(char u = aux; u > 0; u--){
            printf(".");
        }

        aux--;
        printf("\n");
    }

}
