#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamanho_nome 50

int get_num_aleatorio(int min, int max){
    int num = (rand() % (max - min + 1)) + min;
    return num;
}
int generateMenu(void){
    int choice;
    printf("=================MENU==================");
    printf("1.New Game");
    printf("2.Load Game");
    printf("======================================");
    scanf("%d",&choice);
    switch (choice){
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    }
}
void saveGame(int **mapa, int tamanho){
    FILE *saveState = fopen("savestate.txt","wt");
    fwrite(mapa, sizeof(int), tamanho, saveState);
}

void gerar_mapa(int **mapa, int tamanho, int qtd_bombas, int qtd_obstaculos) {
    srand(time(0));
    for (int i=0; i<tamanho; i++){
        mapa[i] = malloc(sizeof(int) * tamanho);
        for (int j=0; j<tamanho; j++) {
            if (i == 0 || j == 0 || i == tamanho-1 || j == tamanho -1){
                mapa[i][j] = 3;
            } else {
                mapa[i][j] = 0;
            }
        }
    }
    int obstaculos[qtd_obstaculos][2];
    int bombas[qtd_bombas][2];
    for (int i = 0; i<qtd_bombas; i++){
        bombas[i][0] = get_num_aleatorio(2, tamanho-2);
        bombas[i][1] = get_num_aleatorio(2, tamanho-2);
    }
    for (int i = 0; i<qtd_obstaculos; i++){
        obstaculos[i][0] = get_num_aleatorio(2, tamanho-2);
        obstaculos[i][1] = get_num_aleatorio(2, tamanho-2);
    }
    int pos_ouro[2];
    pos_ouro[0] = get_num_aleatorio(tamanho/2, tamanho-2);
    pos_ouro[1] = get_num_aleatorio(tamanho/2, tamanho-2);
    int pos_atual[2] = {1,1};
    // 1 = PERSONAGEM
    // 2 = BOMBA
    // 3 = OBSTACULO
    mapa[pos_atual[0]][pos_atual[1]] = 1;
    for (int i=0; i<qtd_bombas; i++){
        mapa[bombas[i][0]][bombas[i][1]] = 2;
    }
    for (int i=0; i<qtd_obstaculos; i++){
        mapa[obstaculos[i][0]][obstaculos[i][1]] = 3;
    }
    mapa[pos_ouro[0]][pos_ouro[1]] = 4;
}

int main()
{
    int escolhaUsuario = generateMenu();
    int tamanho = 21;
    int qtd_bombas = 21;
    int qtd_obstaculos = 80;
    int **mapa = malloc(sizeof(int *) * tamanho);
    
        if(escolhaUsuario == 1){

        gerar_mapa(mapa, tamanho, qtd_bombas, qtd_obstaculos);
        int pos_atual[2] = {1,1};
        int jogo_rodando = 1, debug = 0;
        char direcao = ' ';
        while(jogo_rodando) {
            system("cls");
            if (direcao == 'd'){
                int nova_pos_x = pos_atual[0];
                int nova_pos_y = pos_atual[1];
                nova_pos_y+=1;
                if (mapa[nova_pos_x][nova_pos_y] != 3) {
                    mapa[pos_atual[0]][pos_atual[1]] = 0;
                    pos_atual[0] = nova_pos_x;
                    pos_atual[1] = nova_pos_y;
                }
            }
            else if (direcao == 'a'){
                int nova_pos_x = pos_atual[0];
                int nova_pos_y = pos_atual[1];
                nova_pos_y-=1;
                if (mapa[nova_pos_x][nova_pos_y] != 3) {
                    mapa[pos_atual[0]][pos_atual[1]] = 0;
                    pos_atual[0] = nova_pos_x;
                    pos_atual[1] = nova_pos_y;
                }
            }
            else if (direcao == 'w'){
                int nova_pos_x = pos_atual[0];
                int nova_pos_y = pos_atual[1];
                nova_pos_x-=1;
                if (mapa[nova_pos_x][nova_pos_y] != 3) {
                    mapa[pos_atual[0]][pos_atual[1]] = 0;
                    pos_atual[0] = nova_pos_x;
                    pos_atual[1] = nova_pos_y;
                }
            }
            else if (direcao == 's'){
                int nova_pos_x = pos_atual[0];
                int nova_pos_y = pos_atual[1];
                nova_pos_x+=1;
                if (mapa[nova_pos_x][nova_pos_y] != 3) {
                    mapa[pos_atual[0]][pos_atual[1]] = 0;
                    pos_atual[0] = nova_pos_x;
                    pos_atual[1] = nova_pos_y;
                }
            }
            if (mapa[pos_atual[0]][pos_atual[1]] != 2 && mapa[pos_atual[0]][pos_atual[1]] != 4) {
                mapa[pos_atual[0]][pos_atual[1]] = 1;
            } else {jogo_rodando = 0;}
            for (int i=0; i<tamanho; i++){
                for (int j=0; j<tamanho; j++) {
                    if (debug){
                        printf("%d ", mapa[i][j]);
                    } else {
                        if (mapa[i][j] == 3) {
                            printf("# ");
                        }
                        else if (mapa[i][j] == 4) {
                            printf("g ");
                        }
                        else if (mapa[i][j] == 2 && !jogo_rodando) {
                            printf("* ");
                        }
                        else if (mapa[i][j] == 1){
                            printf("p ");
                        } else {
                            printf("- ");
                        }
                    }
                }
                printf("\n");
            }
            if (jogo_rodando){
                printf("\n[%d, %d] - Digite a direcao: ", pos_atual[0], pos_atual[1]);
                direcao = getchar();
            } else {
                if (mapa[pos_atual[0]][pos_atual[1]] == 2) {
                    printf("\nVoce pisou na bomba!\n");
                    printf("Pressione qualquer tecla para continuar..");
                    getchar();
                } else if (mapa[pos_atual[0]][pos_atual[1]] == 4) {
                    printf("\nVoce recuperou o tesouro!\n");
                    printf("Pressione qualquer tecla para continuar..");
                    getchar();
                }

            }
        }
        
    }else if(escolhaUsuario == 2){
        
        FILE *saveState = fopen("savestate.txt","rt");
        fread(mapa,sizeof(int*),tamanho,saveState);

        int pos_atual[2] = {1,1};
        int jogo_rodando = 1, debug = 0;
        char direcao = ' ';

        while(jogo_rodando){
            system("cls");
            if (direcao == 'd'){
                int nova_pos_x = pos_atual[0];
                int nova_pos_y = pos_atual[1];
                nova_pos_y+=1;
                if (mapa[nova_pos_x][nova_pos_y] != 3) {
                    mapa[pos_atual[0]][pos_atual[1]] = 0;
                    pos_atual[0] = nova_pos_x;
                    pos_atual[1] = nova_pos_y;
                }
            }
            else if (direcao == 'a'){
                int nova_pos_x = pos_atual[0];
                int nova_pos_y = pos_atual[1];
                nova_pos_y-=1;
                if (mapa[nova_pos_x][nova_pos_y] != 3) {
                    mapa[pos_atual[0]][pos_atual[1]] = 0;
                    pos_atual[0] = nova_pos_x;
                    pos_atual[1] = nova_pos_y;
                }
            }
            else if (direcao == 'w'){
                int nova_pos_x = pos_atual[0];
                int nova_pos_y = pos_atual[1];
                nova_pos_x-=1;
                if (mapa[nova_pos_x][nova_pos_y] != 3) {
                    mapa[pos_atual[0]][pos_atual[1]] = 0;
                    pos_atual[0] = nova_pos_x;
                    pos_atual[1] = nova_pos_y;
                }
            }
            else if (direcao == 's'){
                int nova_pos_x = pos_atual[0];
                int nova_pos_y = pos_atual[1];
                nova_pos_x+=1;
                if (mapa[nova_pos_x][nova_pos_y] != 3) {
                    mapa[pos_atual[0]][pos_atual[1]] = 0;
                    pos_atual[0] = nova_pos_x;
                    pos_atual[1] = nova_pos_y;
                }
            }
            if (mapa[pos_atual[0]][pos_atual[1]] != 2 && mapa[pos_atual[0]][pos_atual[1]] != 4) {
                mapa[pos_atual[0]][pos_atual[1]] = 1;
            } else {jogo_rodando = 0;}
            for (int i=0; i<tamanho; i++){
                for (int j=0; j<tamanho; j++) {
                    if (debug){
                        printf("%d ", mapa[i][j]);
                    } else {
                        if (mapa[i][j] == 3) {
                            printf("# ");
                        }
                        else if (mapa[i][j] == 4) {
                            printf("g ");
                        }
                        else if (mapa[i][j] == 2 && !jogo_rodando) {
                            printf("* ");
                        }
                        else if (mapa[i][j] == 1){
                            printf("p ");
                        } else {
                            printf("- ");
                        }
                    }
                }
                printf("\n");
            }
            if (jogo_rodando){
                printf("\n[%d, %d] - Digite a direcao: ", pos_atual[0], pos_atual[1]);
                direcao = getchar();
            } else {
                if (mapa[pos_atual[0]][pos_atual[1]] == 2) {
                    printf("\nVoce pisou na bomba!\n");
                    printf("Pressione qualquer tecla para continuar..");
                    getchar();
                } else if (mapa[pos_atual[0]][pos_atual[1]] == 4) {
                    printf("\nVoce recuperou o tesouro!\n");
                    printf("Pressione qualquer tecla para continuar..");
                    getchar();
                }

            }
        }
        
    }

    return 0;
}
