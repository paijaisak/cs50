#include "cs50.h"
#include "encipher.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
        if (argc != 2)
        {
                printf("Usage: ./substitution key");
                return 1;
        }

        if (strlen(argv[1]) != 26)
        {
                printf("Key must contain 26 characters.");
                return 1;
        }

        string cipher = argv[1];

        if (validate_cipher(cipher) == 0)
                return 1;

        string plaintext = get_string("\nplaintext: ");

        string res = encipher(plaintext, cipher);

        if (res != NULL)
        {
                printf("ciphertext: %s\n", res);
                free(res);
        }

        return 0;
}
