#include <stdio.h>
#include <stdlib.h>




int main(int argc, char* argv[])
{
    int a, result = 0;


    printf("Veulliez entrer un entiers : \n");
    scanf("%d", &a);
    int temp = a;

    if (a % 2 == 0){temp--;}

    while(temp > 0){

        result += temp;
        temp-=2;
    }

    printf("La somme des nombres impairs jusque %d est de %d", a, result);
    return 0;
}
