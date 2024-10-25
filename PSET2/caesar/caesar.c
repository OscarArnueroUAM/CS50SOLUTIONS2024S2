#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int string_to_int(string s) {
    int result = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
        } else {
            return -1;
        }
    }
    return result;
}



int main(int argc, string argv[])
{
  if (argc != 2)
    {
        printf("./caesar key\n");
        return 1;
    }
    int key = string_to_int(argv[1]);

    if (key == -1)
    {
        printf("./caesar key\n");
        return 1;
    }

    string input = get_string("Insert plain text: ");
    int n = strlen(input);

    printf("ciphertext: ");
    for (int i = 0 ; i < n ; i++)
    {
        if (isalpha(input[i]))
        {
            if (isupper(input[i]))
            {
                printf("%c", ((input[i] - 'A' + key) % 26) + 'A');
            }
            else if (islower(input[i]))
            {
                printf("%c", ((input[i] - 'a' + key) % 26) + 'a');
            }
        }
        else
        {
            printf("%c", input[i]) ;
        }
    }
    printf("\n");
    return 0;
}
