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
                char c = plaintext[i];

                // if isn't a letter, just store it
                if (!isalpha(c))
                {
                        res[i] = c;
                }

                else if (isupper(c))
                {
                        // subtract ascii index to count from zero
                        int cipher_index = (int)(c - 65);
                        res[i] = toupper(cipher[cipher_index]);
                }

                else
                {
                        // subtract ascii index to count from zero
                        int cipher_index = (int)(c - 97);
                        res[i] = cipher[cipher_index];
                }
        }

        return res;
}
