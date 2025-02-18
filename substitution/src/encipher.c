#include "cs50.h"
#include "encipher.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int validate_cipher(string cipher)
{
        bool found_alphabet[26] = { false };

        for (int i = 0; i < 26; i++)
        {
                if (!isalpha(cipher[i]))
                {
                        printf("Key must contain 26 characters.");
                        return 0;
                }

                char letter = cipher[i] = tolower(cipher[i]);

                // Check if the letter has already been found
                if (found_alphabet[letter - 'a'])
                {
                        printf("Key must contain 26 unique letters.\n");
                        return 0;
                }

                // Mark the letter as found
                found_alphabet[letter - 'a'] = true;
        }

        return 1;
}

string encipher(string plaintext, string cipher)
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
