#include <stdio.h>

int main(){

    float raiz,x;
    int n, c;

    printf("De input no numero que queres tirar a raiz, e no contador para a serie: ");
    scanf("%d %d", &c, &n);

    x = c / 2.0;

    for(int cnt = 1; cnt <= n + 1; cnt++){

        x = x - ((x * x) - c) / (2.0 * x);
        printf("%f\n",x);

    }

    return 0;
}
