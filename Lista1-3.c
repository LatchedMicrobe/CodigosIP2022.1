#include <stdio.h>

int main(){

    int n, centena, dezena, unidade;

    scanf("%d",&n);


    centena = (n / 100) % 7;
    dezena = (n / 10) % 7;
    unidade = n % 7;

    switch(centena){
        case 0:
            if(dezena == 2 && unidade == 4){
                printf("Acorde do satisfaz.");
            }else{
                printf("Combinacao nao satisfaz.");
            }
            break;
        case 1:
            if(dezena == 3 && unidade == 5){
                printf("Acorde re satisfaz.");
            }else{
                printf("Combinacao nao satisfaz.");
            }
            break;
        case 2:
            if(dezena == 4 && unidade == 6){
                printf("Acorde mi satisfaz.");
            }else{
                printf("Combinacao nao satisfaz.");
            }
            break;
        case 3:
            if(dezena == 5 && unidade == 0){
                printf("Acorde fa satisfaz.");
            }else{
                printf("Combinacao nao satisfaz.");
            }
            break;
        case 4:
            if(dezena == 6 && unidade == 1){
                printf("Acorde sol satisfaz.");
            }else{
                printf("Combinacao nao satisfaz.");
            }
            break;
        case 5:
            if(dezena == 0 && unidade == 2){
                printf("Acorde la satisfaz.");
            }else{
                printf("Combinacao nao satisfaz.");
            }
            break;
        case 6:
            if(dezena == 1 && unidade == 3){
                printf("Acorde si satisfaz.");
            }else{
                printf("Combinacao nao satisfaz.");
            }
            break;

        }

    /*
    do = 0 / mi = 2/ sol = 4
    re = 1 / fa = 3/ la = 5
    mi = 2 / sol = 4/ si = 6
    fa = 3 / la = 5/ do = 0
    sol = 4 / si = 6/ re = 1
    la = 5 / do = 0/ mi = 2
    si = 6 / re = 1/ fa = 3
    */
    return 0;
}
