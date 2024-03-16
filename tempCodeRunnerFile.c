  while(caractere != '\n'){

            fscanf(file,"%c",&caractere);

            if(caractere != '\n'){
                matrizTeste[contador] = caractere;
                contador++;
            }

        } 
        fseek(file, 1, SEEK_CUR);