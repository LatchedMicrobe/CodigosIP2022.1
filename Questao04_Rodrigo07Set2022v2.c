/**==========================================
//    Separa palavra por palavra de um stream de entrada
//terminado por \n ignorando os espaços em branco entre
//as palavras e colocando-as em um array de strings
//------------------------------------------------------------------------
//@Author Rodrigo Pontes
//@Date   07/09/2022
//=========================================*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxStrLen 100
#define TRUE 1
int main(int argc, char* argv[]){
    //--------------Declarando as variáveis------------------------
    int contador = 0;                  //

    char c;                                //Caracter que será lido
    int iniStrFlag=1;                   //Sinalização que os espaços em branco serão lidos e ignorados em sequência
    int tamstr = 1;                     //Variável para o tamanho da string

    char* str=0;                        //String (palavra)
    char* strRealloc=0;             //Evitar problemas com o realloc

    char** arrayStr = 0;            //Cria um array de strings
    char** arrayStrRealloc = 0; //Evitar problemas com o realloc
    int numStrings = 0;             //Número de Strings

    do{
        c = getchar();
        if(c=='\n'){
            //printf("\n%s",str);
            ++numStrings;
            arrayStrRealloc = arrayStr;
            arrayStr = (char**) realloc(arrayStr,numStrings*sizeof(char*));
            if(arrayStr==0){
                free(arrayStrRealloc); arrayStrRealloc = 0;
                printf("\n=====ERRO DE REALOCACAO DE MEMORIA======");
                exit(-3);
            }
            arrayStr[numStrings-1] = (char*) malloc((1+tamstr)*sizeof(char));
            strcpy(arrayStr[numStrings-1],str);
            break;
        }
        if(c==' '){
            iniStrFlag=1;
            tamstr = 1;
            continue;
        }
        if(iniStrFlag==1){
            iniStrFlag=0;
            //printf("\n%c",c);
            //inicia uma nova string
            if(str!=0) {
                ++numStrings;
                arrayStrRealloc = arrayStr;
                arrayStr = (char**) realloc(arrayStr,numStrings*sizeof(char*));
                if(arrayStr==0){
                    free(arrayStrRealloc); arrayStrRealloc = 0;
                    printf("\n=====ERRO DE REALOCACAO DE MEMORIA======");
                    exit(-4);
                }
                arrayStr[numStrings-1] = (char*) malloc((1+tamstr)*sizeof(char));
                strcpy(arrayStr[numStrings-1],str);
                //printf("\n%s",str); //imprime a antiga que foi finalizada
            }
            free(str); str = 0; //desaloca o endereço antigo
            str = (char*)malloc((1+tamstr)*sizeof(char)); //Cria uma string unitária
            if(str==0){
                printf("\n=====ERRO DE ALOCACAO DE MEMORIA======");
                exit(-1);
            }
            str[0]=c; str[1]='\0';
        }else{
            ++tamstr;
            strRealloc = str;
            str = (char*)realloc(str,(1+tamstr)*sizeof(char));
            if(str==0){
                printf("\n=====ERRO DE REALOCACAO DE MEMORIA======");
                free(strRealloc); strRealloc = 0;
                exit(-2);
            }
            str[tamstr-1]=c; str[tamstr]='\0';
            //printf("%c ",c);
        }
    }while(TRUE);

    for(contador = 0; contador<numStrings;++contador){
        printf("Palavra %i = %s\n",contador,arrayStr[contador]);
    }
    //=========USE AQUI PARA DESALOCAR ARRAYSTR================
    //VTNC E TE VIRA
    //==========================================================
    free(str); str=0;
    return(1);
}
