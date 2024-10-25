#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>

int main(void)
{


    long long cc;

    // Obtener el número de tarjeta de crédito del usuario
    do
    {
        cc = get_long_long("Inserta el número de tu tarjeta de crédito: ");
    }
    while (cc <= 0);

    int contador_longitud_cc = 0;
    long long chequeo_longitud_cc = cc;

    do
    {
        chequeo_longitud_cc /= 10;
        contador_longitud_cc++;
    } while (chequeo_longitud_cc > 0);

    // Verificar si la longitud de la entrada es válida
    if (contador_longitud_cc < 13 || contador_longitud_cc > 17)
    {
        printf("INVALID\n");
        return 0;
    }

    // Calcular checksum para cada segundo dígito empezando desde el penúltimo
    int suma1 = 0;
    long long i = 10;
    do
    {
        long long cc_1 = ((cc % (i * 10)) / i) * 2;
        if (cc_1 < 10)
        {
            suma1 += cc_1;
        }
        else
        {
            suma1 += (cc_1 % 10 + (cc_1 % 100 / 10));
        }
        i *= 100;
    } while (i < 10000000000000000);

    // Calcular checksum para cada dígito empezando desde el último
    int suma2 = 0;
    long long j = 1;
    do
    {
        long long cc_2 = ((cc % (j * 10)) / j);
        suma2 += cc_2;
        j *= 100;
    } while (j < 1000000000000000);

    int suma_final = suma1 + suma2;
    int ultimo_digito_suma = suma_final % 10;

    // Obtener los dos primeros dígitos para identificar el tipo de tarjeta
    while (cc >= 100)
    {
        cc /= 10;
    }

    // Determinar el tipo de tarjeta de crédito según los dos primeros dígitos
    if ((cc == 34 || cc == 37) && ultimo_digito_suma == 0) 
    {
        printf("AMEX\n");
    }
    else if ((cc == 41 || cc == 40) && ultimo_digito_suma == 0)
    {
        printf("VISA\n");
    }
    else if ((cc == 51 || cc == 52 || cc == 53 || cc == 54 || cc == 55) && ultimo_digito_suma == 0)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
