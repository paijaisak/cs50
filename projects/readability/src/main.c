#include "readability.h"
#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int res = 0;

        string text = get_string("Text: ");

        res = test_score(text);

        if (res == 0)
        {
                printf("Before Grade 1");
        }
        else if (res == 16)
        {
                printf("Grade 16+");
        }
        else
        {
                printf("Grade %d", res);
        }

        printf("\n");

        return 0;
}

