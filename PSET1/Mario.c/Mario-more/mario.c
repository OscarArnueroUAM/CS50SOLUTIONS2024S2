#include <stdio.h>
#include <cs50.h>
//Ejercicio 1 de Mario: Version more de Mario, hacer piramide a ambos lados y que tenga un maximo de 8 en tema de altura.
int main (){
    int height;
    do
    {
        height = get_int("Dame una Altura: \n");
    }while (height <1 || height > 8);

     for (int i = 0; i < height; i++) {

        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }


        for (int j = 0; j <= i; j++) {
            printf("#");
        }


        printf("  ");

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;

}
