#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Pessoa{
    char nome[50];
    char idade[3];
    char gostos[50];
}Pessoa;

int main(int argc, char *argv[]){

    char nomeArquivo[MAX_SIZE] = "C:\\Users\\Pichau\\Documents\\EuPosso.txt";
    char **dadosArquivos = NULL, **dadosArquivosAUX;
    char *str, *strAux, *ponteirosAux;
    int contadorPonteiros = 0, tamanhoString = 1, numeroPessoas = 0;
    int flagPessoas = 0;
    char caractere = 0;
    FILE *file;
    Pessoa *pessoas = NULL;

    file = fopen(nomeArquivo,"rt");
    
    while(1){

        pessoas = (Pessoa *) realloc(pessoas, (numeroPessoas + 1) * sizeof(Pessoa));

        caractere = 0;
        tamanhoString = 1;

        dadosArquivosAUX = (char**) realloc(dadosArquivos, (contadorPonteiros + 1) * sizeof(char*));

        if(dadosArquivosAUX != NULL)
            dadosArquivos = dadosArquivosAUX;
        
    
        strAux = (char*) malloc((tamanhoString + 1) * sizeof(char));

        if(strAux != NULL){
            str = strAux;
            str[0] = caractere;
            str[1] = '\0';
        }

        while(caractere != '\n'){

            fscanf(file,"%c",&caractere);

            if(feof(file)){

                ponteirosAux = (char*) malloc(tamanhoString * sizeof(char));
                if(ponteirosAux != NULL){
                    dadosArquivos[contadorPonteiros] = ponteirosAux;
                    strcpy(dadosArquivos[contadorPonteiros],str);
                    printf("%s",dadosArquivos[contadorPonteiros]);
                    free(str);               
                }
                fclose(file);
                free(pessoas);
                for(int i = 0; i < contadorPonteiros; i++){
                    free(dadosArquivos[i]);
                }
                free(dadosArquivos);                 
                exit(1);

            }

            strAux = (char*) realloc(str,(tamanhoString + 1) * sizeof(char));
            if(strAux != NULL){
                str = strAux;
                str[tamanhoString - 1] = caractere;
                str[tamanhoString] = '\0';
            }
            tamanhoString++;

        }

        ponteirosAux = (char*) malloc(tamanhoString * sizeof(char));
        if(ponteirosAux != NULL){
            dadosArquivos[contadorPonteiros] = ponteirosAux;
            strcpy(dadosArquivos[contadorPonteiros],str);

            for(int contadorSeparador = 0, contadorElementos = 0; contadorSeparador < tamanhoString;contadorSeparador++){
                if(flagPessoas == 0){
                    if(str[contadorSeparador] == '-'){
                        flagPessoas = 1;
                        contadorElementos = 0;
                    }else{
                        pessoas[numeroPessoas].nome[contadorElementos] = str[contadorSeparador];
                        contadorElementos++;
                    }
                    printf("LETRA: %c\n",str[contadorSeparador]);
                }else if(flagPessoas == 1){
                    if(str[contadorSeparador] == '-'){
                        flagPessoas = 2;
                        contadorElementos = 0;
                    }else{
                        pessoas[numeroPessoas].idade[contadorElementos] = str[contadorSeparador];
                        contadorElementos++;
                    }
                    printf("LETRA: %c\n",pessoas[numeroPessoas].idade[contadorElementos]);
                }else if(flagPessoas == 2){
                    pessoas[numeroPessoas].gostos[contadorElementos] = str[contadorSeparador];
                    printf("LETRA: %c\n",pessoas[numeroPessoas].gostos[contadorElementos]);
                }
            }

            printf("%s",dadosArquivos[contadorPonteiros]);
            printf("\nA pessoa agora e: %s\n",pessoas[numeroPessoas].nome);
            printf("\nA idade agora e: %s\n",pessoas[numeroPessoas].idade);
            printf("\nOs gostos em questao sao: %s\n",pessoas[numeroPessoas].gostos);

            free(str);                
            str = NULL;
            numeroPessoas++;
            contadorPonteiros++;
        }

    }
    
}