#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int contar_letras(string);
int contar_palabras(string);
int contar_oraciones(string);
float calcular_indiceColemanLaiu(int, int, int);

int main(void)
    {
        string entradaUsuario = get_string("Texto: ");
        int letras = contar_letras(entradaUsuario);
        int palabras = contar_palabras(entradaUsuario);
        int oraciones = contar_oraciones(entradaUsuario);
        int indiceColemanLaiu = calcular_indiceColemanLaiu(letras, palabras, oraciones);

        if (indiceColemanLaiu > 16)
        {
            printf("Grade 16+\n");
        }
        else if (indiceColemanLaiu < 1)
        {
            printf("Before Grade 1\n");
        }
        else
        {
            printf("Grade %d\n", indiceColemanLaiu);
        }
    }

    float calcular_indiceColemanLaiu(int l, int p, int o)
    {
        float indice = 0.0;
        float L = ((float) l / p * 100.0);
        float S = ((float) o / p * 100.0);
        indice = round((0.0588 * L) - (0.296 * S) - 15.8);

        return indice;
    }

    int contar_oraciones(string texto)
    {
        int contador = 0;
        for (int i = 0; texto[i] != '\0'; i++)
        {
            if (texto[i] == '.' || texto[i] == '?' || texto[i] == '!')
            {
                contador++;
            }
        }

        return contador;
    }

    // Cuenta el número de palabras en un string
    int contar_palabras(string texto)
    {
        int contador = 0;
        for (int i = 0; texto[i] != '\0'; i++)
        {
            if (texto[i] == ' ')
            {
                contador++;
            }
        }
        contador++; // asume que el último espacio tiene una palabra

        return contador;
    }

    // Cuenta el número de letras en un string
    int contar_letras(string texto)
    {
        int contador = 0;
        for (int i = 0; texto[i] != '\0'; i++)
        {
            if (isalnum(texto[i]))
            {
                contador++;
            }
        }

        return contador;
}

