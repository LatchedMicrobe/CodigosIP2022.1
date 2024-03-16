#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int main(){

    char **matrizStrings = NULL; 
    char **pntAux1;
    char *pntAux2;
    char caractereRecebido, eof_ver;
    int cntLoop1 = 0, cntLoop2 = 0;

    do{
        pntAux1 = matrizStrings;
         
        matrizStrings = (char**) realloc(matrizStrings,(cntLoop1 + 1) * sizeof(char*));

        if(matrizStrings == NULL){
            free(pntAux1);
            exit(1);
        }else{
            do{
                getch();
                caractereRecebido = getch();

                pntAux2 = matrizStrings[cntLoop1];

                matrizStrings[cntLoop1] = (char*) realloc(matrizStrings[cntLoop1],(cntLoop2 + 1) * sizeof(char));

                if(matrizStrings[cntLoop1] == NULL){
                    free(pntAux2);
                    exit(1);
                }else{
                    matrizStrings[cntLoop1][cntLoop2] = caractereRecebido;
                    cntLoop2++;
                }
            } while(caractereRecebido != '\n');
            cntLoop1++;
        }
    } while(scanf("%c",&eof_ver) != EOF);
    
    for(int j = 0; j < cntLoop1; j++){
        printf("\nAQUI%s\n",matrizStrings[j]);
    }
    for(int i = cntLoop1; i  > 0 ; i--)
        free(matrizStrings[cntLoop1]);

    free(matrizStrings);
    return 0;
}