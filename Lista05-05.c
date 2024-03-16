#include <stdio.h>
#include <string.h>
#include <math.h> 

typedef struct Estabelecimento{
    char nome[50];
    int posX;
    int posY;
    char tipoCoxinha[20];
    double distanciaOrigem;
    float precoCoxinha;
    int flagVisita;
}Estabelecimento;

typedef struct listaDesejos{
    char desejo[20];
    int flagDesejo;
}listaDesejos;


int main(){

    int posXGeraldo = 0, posYGeraldo = 0, numeroEstabelecimentos = 0, numeroListaDesejos = 0, i = 0, j = 0, contadorLoopWhile = 0, estabelecimentoVisitado = 0, contadorDesejos = 0;
    Estabelecimento destinoAtual;
    scanf("%d %d\n",&posXGeraldo,&posYGeraldo);
    scanf("%d",&numeroEstabelecimentos);

    Estabelecimento estabelecimentos[numeroEstabelecimentos];

    for(i = 0; i < numeroEstabelecimentos; i++){
        scanf("%s %d %d %s %f\n",estabelecimentos[i].nome,&estabelecimentos[i].posX,&estabelecimentos[i].posY,
        estabelecimentos[i].tipoCoxinha,&estabelecimentos[i].precoCoxinha);
        estabelecimentos[i].flagVisita = 0;
    }

    scanf("%d",&numeroListaDesejos);

    listaDesejos listaDesejos[numeroListaDesejos][20];

    for(j = 0; j < numeroListaDesejos; j++)
        scanf("%s",listaDesejos[j]->desejo);
    
    destinoAtual.distanciaOrigem = 0;

    while (contadorLoopWhile < numeroEstabelecimentos){

        for(i = 0; i < numeroEstabelecimentos; i++){

            if(estabelecimentos[i].flagVisita == 0){
                estabelecimentos[i].distanciaOrigem = ((estabelecimentos[i].posX - posXGeraldo) * (estabelecimentos[i].posX - posXGeraldo)) + 
                ((estabelecimentos[i].posY - posYGeraldo) * (estabelecimentos[i].posY - posYGeraldo));

                estabelecimentos[i].distanciaOrigem = sqrt(estabelecimentos[i].distanciaOrigem);

                if(destinoAtual.distanciaOrigem > estabelecimentos[i].distanciaOrigem && destinoAtual.distanciaOrigem != 0){

                    destinoAtual = estabelecimentos[i];
                    estabelecimentoVisitado = i;

                }else if(destinoAtual.distanciaOrigem == estabelecimentos[i].distanciaOrigem){

                    if(destinoAtual.precoCoxinha > estabelecimentos[i].precoCoxinha){
                        destinoAtual = estabelecimentos[i];
                        estabelecimentoVisitado = i;
                    }

                }else if(destinoAtual.distanciaOrigem == 0){
                    destinoAtual = estabelecimentos[i];    
                    estabelecimentoVisitado = i;
                }
                
            }
        
        }
        posXGeraldo = destinoAtual.posX;
        posYGeraldo = destinoAtual.posY;
        destinoAtual.distanciaOrigem = 0;
        
        estabelecimentos[estabelecimentoVisitado].flagVisita = 1;
        estabelecimentoVisitado = 0;

        for(j = 0; j < numeroListaDesejos; j++){
            if(strcmp(listaDesejos[j]->desejo,destinoAtual.tipoCoxinha) == 0){
                listaDesejos[j]->flagDesejo = 1;
                contadorDesejos++;
            }
        }
        
        if(contadorLoopWhile == numeroEstabelecimentos - 1){
            printf("%s\n",destinoAtual.nome);
            if(contadorDesejos == numeroListaDesejos)
                printf("Completou a lista");
            else
                printf("Vou fazer as que faltaram quando chegar em casa");
        }else{
            printf("%s\n",destinoAtual.nome);
        }

        contadorLoopWhile++;
    }
}