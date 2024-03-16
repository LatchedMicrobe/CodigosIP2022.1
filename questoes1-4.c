/*
Autor Rodrigo Pontes de Oliveira Lima rpol 70406498458
*/
//Questão 1
#include <stdio.h>

int main() {

    char c = 'a';
    char *pc = &c;
    //Letra a)
    printf("O endereco de c e: %p e o valor de c e: %c",&c,c);
    //Letra b)
    printf("\nO valor de pc e: %p e o valor do endereco apontado por pc e: %c",pc,*(pc));
    //Letra c)
    printf("\nO endereco de pc e: %p",&pc);
    /*Letra d) A desreferenciação consiste em acessar o valor armaze
    nado em um endereço armazenado dentro de um ponteiro, ou seja,
    desreferenciar é usar um ponteiro ou um endereço de uma variavel
    para acessar os valores armazenados nessa variavel por meio do
    operador '*'
    */
    printf("\nO endereco do valor guardado no endereco apontado por pc e: %p e o valor guardado no endereco de pc e: %p",&*(pc),*&pc);
    /*Letra e) O endereço do valor guardado no endereço apontado por
    pc é o próprio endereço apontado por pc, já que o valor no endere
    ço apontado por pc é o valor dentro de c, e o endereço que ele es
    tá armazenado é, por consequencia, c; E o valor guardado no ende
    reço de pc também é o endereço de c, pois o endereço de pc é o 
    endereço do ponteiro pc, e o valor dentro deste endereço é c; como
    os dois são os endereços de c, ambos são iguais.
    */
}
//Questão 2
#include <stdio.h>

int main(){

    int vet[5]={1,2,3,4,5}, i = 0;
    int *p;
    
    p = vet;
    
    printf("o endereço de vet e %p o endereço apontado por p e %p",vet,p);

    for(i = 0;i < 5; i++)
        printf("\nUtilizando p[i]:O elemento %d = %d",i+1,p[i]);
    

    for(i = 0; i < 5; i++)
        printf("\nUtilizando *(p+i):O elemento %d = %d",i+1,*(p+i));
    

    for(i = 0;i<5;i++)
        printf("\nUtilizando vet[i]:O elemento %d = %d",i+1,vet[i]);
    

    return 0;
}
//Questão 3
#include <stdio.h>
#include <string.h>

int main(){

    //Letra a)
    char str[50]; 
    char str_inv[50]; 
    char *ptr_str = str;
    char *ptr_inv = str_inv;
    int i=-1;
    
    scanf("%s", str);

    for(;-i <= strlen(ptr_str); i--){
        
        *(ptr_inv -1 -i) = *(ptr_str + strlen(ptr_str) +i);
        
    }
    printf(" O inverso da string : %s\n\n",str_inv);

    /*Letra b)
        Na string "str", assim como em qualquer matriz, o str[0] ou str funciona com um ponteiro para a matriz/string
        como um todo, a função scanf recebe como argumentos uma string de numero de caractere variavel contendo os ca
        racteres especiais que armazenam o valor do usuário, e os endereços de memoria para as variaveis para qual man
        daremos tais valores. Como str já tem como valor um endereço de memoria para a matriz/string, então não precisa
        mos o & para conseguir o endereço da memoria da matriz, já que str já é(tem como valor) esse endereço. 
    */
    return 0;
}
//Questão 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITSIZE 10
#define BUFFSIZE 100

int
main(void) {
    char **strings;
    size_t currsize = INITSIZE, str_count = 0, slen;

    char buffer[BUFFSIZE];
    char *word;
    const char *delim = " ";
    int i;

    /* Allocate initial space for array */
    strings = malloc(currsize * sizeof(*strings));
    if(!strings) {
        printf("Issue allocating memory for array of strings.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter some words(Press enter again to end): ");
    while (fgets(buffer, BUFFSIZE, stdin) != NULL && strlen(buffer) > 1) {

        /* grow array as needed */
        if (currsize == str_count) {
            currsize *= 2;
            strings = realloc(strings, currsize * sizeof(*strings));
            if(!strings) {
                printf("Issue reallocating memory for array of strings.\n");
                exit(EXIT_FAILURE);
            }
        }

        /* Remove newline from fgets(), and check for buffer overflow */
        slen = strlen(buffer);
        if (slen > 0) {
            if (buffer[slen-1] == '\n') {
                buffer[slen-1] = '\0';
            } else {
                printf("Exceeded buffer length of %d.\n", BUFFSIZE);
                exit(EXIT_FAILURE);
            }
        }

        /* Parsing of words from stdin */
        word = strtok(buffer, delim);
        while (word != NULL) {

            /* allocate space for one word, including nullbyte */
            strings[str_count] = malloc(strlen(word)+1);
            if (!strings[str_count]) {
                printf("Issue allocating space for word.\n");
                exit(EXIT_FAILURE);
            }

            /* copy strings into array */
            strcpy(strings[str_count], word);

            str_count++;
            word = strtok(NULL, delim);
        }
    }

    /* free strings */
    printf("Your array of strings:\n");
    for (i = 0; i < str_count; i++) {
        free(strings[i]);
        strings[i] = NULL;
    }

    free(strings);
    strings = NULL;

    return 0;
}
