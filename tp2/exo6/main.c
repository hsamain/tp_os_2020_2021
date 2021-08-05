#include <stdio.h>
#include <stdlib.h>


int fibonacci(int n){

    if(n == 0){return 0;}

    if(n == 1){return 1;}

    return fibonacci(n-1) + fibonacci(n-2);
}



int main(int argc, char* argv[])
{
    int n;
    printf("Veuillez entrer un entier : ");
    scanf(" %d", &n);

    int temp = n;
    n = 1;

    while(temp > 0){

        printf("%d\n", fibonacci(n));
        n++;
        temp--;
    }

    return 0;
}
