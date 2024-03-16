#include <stdio.h>

int main(){

    float nota_1, nota_2, nota_3,media_maxima = 0, media_teste = 0, media_geral = 0, media_mulher = 0, media_homem = 0;
    int cnt_t = 0, cnt_p = 0, cnt_f = 0, cnt_r = 0,cnt_m = 0,cnt_h = 0;
    char sexo, sexo_max, eof_ver;

    while(1){

        scanf("%f %f %f %c",&nota_1,&nota_2,&nota_3,&sexo);
        cnt_t++;

        media_geral += nota_1 + nota_2 + nota_3;

        media_teste = (nota_1 + nota_2 + nota_3) / 3;

        if(media_teste >= 7.0)
            cnt_p++;
        else if(media_teste >= 3)
            cnt_f++;
        else
            cnt_r++;

        if(media_teste >= media_maxima){

            media_maxima = media_teste;
            sexo_max = sexo;
        }

        if(sexo == 'H'){
            media_homem += nota_1 + nota_2 + nota_3;
            cnt_h++;
        }
        else{
            media_mulher += nota_1 + nota_2 + nota_3;
            cnt_m++;
        }

        if(scanf("%c",&eof_ver) == EOF){

            if(cnt_t > 0)
                media_geral = media_geral / (cnt_t * 3);
            else
                media_geral = 0;
            if(cnt_h > 0)
                media_homem = media_homem / (cnt_h * 3);
            else
                media_homem = 0;

            if(cnt_m > 0)
                media_mulher = media_mulher / (cnt_m * 3);
            else
                media_mulher = 0;

            if(sexo_max == 'H')
                printf("A maior media da turma foi %.1f e pertence a um homem.",media_maxima);
            else
                printf("A maior media da turma foi %.1f e pertence a uma mulher.",media_maxima);

            printf("\nA media geral foi de %.1f.\n",media_geral);
            printf("%d alunos foram aprovados por media.\n",cnt_p);
            printf("%d alunos podem fazer o exame final.\n",cnt_f);
            printf("%d alunos foram reprovados.\n",cnt_r);
            printf("A media das mulheres foi de %.1f.\n",media_mulher);
            printf("A media dos homens foi de %.1f.",media_homem);

            break;
        }
    }


}
