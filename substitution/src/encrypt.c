#include "encrypt.h"
#include "cs50.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

string encrypt(string plaintext, string cipher)
{
        int length = strlen(plaintext);

        string res = malloc(sizeof(char) * length);

        for (int i = 0; i < length; i++)
        {
                // if isn't a letter, just store it
                if (!isalpha(plaintext[i]))
                {
                        res[i] = plaintext[i];
                }

                else
                {
                        // assuming uppercase, ascii index minus 65 counts letter distance from
                        // zero.
                        char upper = toupper(plaintext[i]);
                        int cipher_index = (int)(upper - 65);

                        res[i] = cipher[cipher_index];
                }
        }

        return res;
}
