#include <stdio.h>
#include <cs50.h>

int main (void){
    string nombre = get_string("Porfavor ingrese su nombre: ");
    printf("hello, %s\n", nombre);
    return 0;
}
