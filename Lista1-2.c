#include <stdio.h>

int main(){

    int n,x,y,z;

    scanf("%d",&n);
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);


    if(x + y + z <= n){

        printf("3");

    }else if(x + y <= n || x + z <= n || y + z <= n){

        printf("2");

    }else if(x <= n || y <= n || z <= n){

        printf("1");

    }else{

        printf("0");

    }

}
