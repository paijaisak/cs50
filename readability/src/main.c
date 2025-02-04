#include "main.h"
#include "cs50.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
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

int test_score(string text)
{
    int number_of_letters = count_letters(text);
    int number_of_words = count_words(text);
    int number_of_sentences = count_sentences(text);

    const float L = ((float)number_of_letters / number_of_words) * 100.0;
    const float S = ((float)number_of_sentences / number_of_words) * 100.0;

    int index = roundf((0.0588 * L) - (0.296 * S) - 15.8);

    if (index < 1)
        return 0;

    if (index > 16)
        return 16;

    return index;
}

int count_letters(string text)
{
    int res = 0;
    char c = ' ';
    int i = 0;

    while (c != '\0')
    {
        c = text[i];
        if (isalpha(c))
        {
            res++;
        }

        i++;
    }

    return res;
}

int count_words(string text)
{
    int spaces = 0;
    char c = ' ';
    int i = 0;

    while (c != '\0')
    {
        c = text[i];
        if (isspace(c))
        {
            spaces++;
        }

        i++;
    }

    return spaces + 1;
}

int count_sentences(string text)
{
    int stops = 0;
    char c = ' ';
    int i = 0;

    while (c != '\0')
    {
        c = text[i];

        if (ispunct(c))
        {
            if (c == '!' || c == '?' || c == '.')
            {
                stops++;
            }
        }

        i++;
    }

    return stops;
}
