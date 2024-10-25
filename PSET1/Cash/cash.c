#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int cambio;
    do
    {
        cambio = get_int("Cambio a devolver (en centavos): ");
    }
    while (cambio < 0);

    int Centavos25 = cambio / 25;
    cambio = cambio % 25;
    int Centavos10 = cambio / 10;
    cambio = cambio % 10;
    int Centavos5 = cambio / 5;
    cambio = cambio % 5;
    int Centavos1 = cambio;

    int totalMonedas = Centavos25 + Centavos10 + Centavos5 + Centavos1;

    printf("Total de monedas de centavos a devolver: %d\n", totalMonedas);
    printf("Detalle: %d monedas de 25c, %d monedas de 10c, %d monedas de 5c, %d monedas de 1c\n", Centavos25, Centavos10, Centavos5, Centavos1);

    return 0;
}
