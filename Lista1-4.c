#include <stdio.h>

int main(){

    //declarar os soldados, tanques, avioes e lan�a misseis de ambos os lados + refor�os
    int soldados_aliados,tanques_aliados,avioes_aliados,lanca_misseis_aliados;
    int soldados_inimigos,tanques_inimigos,avioes_inimigos,lanca_misseis_inimigos;
    int soldados_reforcos,tanques_reforcos,avioes_reforcos,lanca_misseis_reforcos;
    int soldados_inimigos_total,tanques_inimigos_total,avioes_inimigos_total,lanca_misseis_inimigos_total;
    int vitorias = 0;
    int derrotas = 0;

    scanf("%d %d %d %d",&soldados_aliados,&tanques_aliados,&avioes_aliados,&lanca_misseis_aliados);
    scanf("%d %d %d %d",&soldados_inimigos,&tanques_inimigos,&avioes_inimigos,&lanca_misseis_inimigos);
    scanf("%d %d %d %d",&soldados_reforcos,&tanques_reforcos,&avioes_reforcos,&lanca_misseis_reforcos);

    soldados_inimigos_total = soldados_inimigos + soldados_reforcos;
    tanques_inimigos_total = tanques_inimigos + tanques_reforcos;
    avioes_inimigos_total = avioes_inimigos + avioes_reforcos;
    lanca_misseis_inimigos_total = lanca_misseis_inimigos + lanca_misseis_reforcos;

    if(soldados_aliados > soldados_inimigos_total){
        vitorias++;
    }else if(soldados_aliados < soldados_inimigos_total){
        derrotas++;
    }
    if(tanques_aliados > tanques_inimigos_total){
        vitorias++;
    }else if(tanques_aliados < tanques_inimigos_total){
        derrotas++;
    }
    if(avioes_aliados > avioes_inimigos_total){
        vitorias++;
    }else if(avioes_aliados < avioes_inimigos_total){
        derrotas++;
    }
    if(lanca_misseis_aliados > lanca_misseis_inimigos_total){
        vitorias++;
    }else if(lanca_misseis_aliados < lanca_misseis_inimigos_total){
        derrotas++;
    }


    printf("%d",vitorias);
    if(vitorias > 2){
        printf("Avancar");
    }else if(vitorias < 2 && derrotas > 2){
        printf("Recuar");
    }else{
        printf("Permanecer");
    }
}
