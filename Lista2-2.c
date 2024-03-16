#include <stdio.h>

int main(){

    //1 Declaração de variaveis
    int data_i[3],data_f[3],cnt = 0,checks;

    //2 Receber input das datas com formatação correta
    scanf("%d/%d/%d",&data_i[0],&data_i[1],&data_i[2]);
    scanf("%d/%d/%d",&data_f[0],&data_f[1],&data_f[2]);

    while(1){

        checks = 0;

        for(char i = 0; i < 3; i++){

            if(data_i[i] == data_f[i]){

                checks++;

            }

        }

        if(checks == 3)

            break;

        if((data_i[1] <= 7 && data_i[1] % 2 != 0) || (data_i[1] >= 8 && data_i[1] % 2 == 0)){

            if(data_i[0] <= 31){

                data_i[0]++;
                cnt++;

            }else{

                data_i[0] = data_i[0] % 31;
                data_i[1]++;

                if(data_i[1] > 12){

                    data_i[1] = data_i[1] % 12;

                    data_i[2]++;

                }
            }
        }else{
            if(data_i[1] == 2){

                if(data_i[2] % 4 == 0 && ((data_i[2] % 100 != 0) || (data_i[2] % 400 == 0))){

                    if(data_i[0] <= 29){
                        data_i[0]++;
                        cnt++;

                    }else{

                       data_i[0] = data_i[0] % 29;
                       data_i[1]++;
                    }

                }else{

                    if(data_i[0] <= 28){
                        data_i[0]++;
                        cnt++;

                    }else{

                       data_i[0] = data_i[0] % 28;
                       data_i[1]++;

                    }

                }

            }else{

                if(data_i[0] <= 30){
                    data_i[0]++;
                    cnt++;
                }else{
                    data_i[0] = data_i[0] % 30;
                    data_i[1]++;

                }
            }

        }
        printf("%d\n",cnt);
    }
    printf("%d",cnt);
}
