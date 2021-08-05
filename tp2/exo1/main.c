#include <stdio.h>
#include <stdlib.h>

int pgcd(int a, int b)
{
    int pgcd_ok = 0;
    int i = b;

    while (pgcd_ok == 0){

        if(a % i == 0 && b % i == 0){

            pgcd_ok = 1;
        }
        else{i--;}

    }

    return i;
}

int main(int argc, char* argv[])
{
    int a, b;

    printf("Veulliez entrer deux entiers : \n");
    scanf("%d", &a);
    scanf("%d", &b);

    printf("Le PGCD de %d et %d est %d.\n", a, b, pgcd(a, b));

    return 0;
}
