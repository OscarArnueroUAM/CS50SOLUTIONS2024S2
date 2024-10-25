#include <stdio.h>
#include <cs50.h>
//Ejercicio 1 de Mario: Version debil de Mario, hacer piramide solamente a la derech.
int main() {
    int height;
    do {
        height = get_int("Dame una altura: ");
    } while (height < 1);


    for (int row = 0; row < height; row++) {
        for (int space = 0; space < height - row - 1; space++) {
            printf(" ");
        }

        for (int hash = 0; hash <= row; hash++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}

