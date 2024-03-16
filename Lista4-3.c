#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {

    char text[501],copyText[501], encodedPart[5][40],translatedPart[5][20], character = 0;
    int flagBracket = 0,flagSubstitution = 0, flagDash = 0, k = 0, sizeCharacter = 0;
    short int cntLower = 0, cntUpper = 0;

    scanf("%500[^\n]",text);

    for(int i = 0, j = 0;text[i] != '\0';){

        if(text[i] == '['){
            flagBracket = 1;
        }else if(text[i] == ']'){
            flagBracket = 0;
            k++;
            j = 0;
        }else if(flagBracket == 1){
            encodedPart[k][j] = text[i];
            j++;
        }
        i++;
    }
    for(int i = 0; i < k ; i++){
        for(int j = 0, n = 0; j <= strlen(encodedPart[i]); j++){

            if(j == strlen(encodedPart[i])){
               translatedPart[i][n] = '\0';
               break;
            }

            if(encodedPart[i][j] != '-'){
                sizeCharacter++;
            }else{
                if(sizeCharacter == 3){
                    character = (((int)encodedPart[i][j - 3] - 48) * 100) + (((int)encodedPart[i][j - 2] - 48) * 10) + ((int)encodedPart[i][j - 1] - 48);
                }else{
                    character = (((int)encodedPart[i][j - 2] - 48) * 10) + ((int)encodedPart[i][j - 1] - 48);
                }
                translatedPart[i][n] = character;
                n++;
                sizeCharacter = 0;
            }
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < strlen(translatedPart[i]); j++){
            if(islower(translatedPart[i][j]))
                cntLower++;
            else if(isupper(translatedPart[i][j]))
                cntUpper++;
        }
        if(cntLower > cntUpper){
            for(int n = 0; n < strlen(translatedPart[i]); n++){
                if(isupper(translatedPart[i][n])){
                    translatedPart[i][n] = tolower(translatedPart[i][n]);
                }
            }
            cntLower = 0;
            cntUpper = 0;
        }else{
           for(int n = 0; n < strlen(translatedPart[i]); n++){
                if(islower(translatedPart[i][n])){
                    translatedPart[i][n] = toupper(translatedPart[i][n]);
                }
            }
            cntLower = 0;
            cntUpper = 0;
        }
    }
    for(int i = 0, j = 0;text[i] != '\0';){
      if (text[i] == '[')
            {
                strcpy(copyText, text);
                text[i] = '\0';
                strcat(text, translatedPart[j]);
                for (int n = i; copyText[n] != '\0'; ++n)
                {
                    if (copyText[n] == ']')
                    {
                        strcat(text, copyText + n + 1);
                        break;
                    }
                }
                j++;
            }
            i++;
        }

    printf("%s",text);
}
