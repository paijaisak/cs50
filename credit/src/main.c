#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>

int number_of_digits(const long number)
{
    long res = number;

    if (res == 0)
        return 0;

    if (res / 10 == 0)
        return 1;

    return number_of_digits(res / 10) + 1;
}

// start and end parameters for recursion purposes. start = 0 & end = length -1
int* card_into_array(const long card, const int length)
{
    long number = card;

    // dynamic initialization, since length is unknown at compile time
    int* res = (int*)malloc(length * sizeof(int));

    if (res == NULL)
    {
        printf("Not allocated");
        return 0;
    }

    for (int i = length - 1; i >= 0; i--)
    {
        res[i] = number % 10;
        number /= 10;
    }

    return res;
}

int at_index(const int* card_array, const int length, int index)
{
    if (index > length || index < 0)
    {
        return 0;
    }
    else
    {
        return card_array[index];
    }
}

bool is_valid(const int* card_array, const int length)
{
    int sum_a = 0;
    int sum_b = 0;
    int sum = 0;

    for (int i = length - 2; i >= 0; i -= 2)
    {
        if (i > length || i < 0)
        {
            break;
        }

        if ((card_array[i] * 2) >= 10)
        {
            // 1 for the 10-digit place
            sum_a += 1;
            // the single digit place (minus 10)
            sum_a += (card_array[i] * 2 - 10);
        }
        else
        {
            sum_a += card_array[i] * 2;
        }
    }

    for (int i = length - 1; i >= 0; i -= 2)
    {
        sum_b += card_array[i];
    }

    sum = sum_a + sum_b;

    if (sum % 10 != 0)
        return false;

    return true;
}

int main()
{
    const long card = get_long("Number: ");

    const int length = number_of_digits(card);

    int* card_array = card_into_array(card, length);

    // validity, possible endpoint
    if (length < 13 || length == 14 || length > 16)
    {
        printf("INVALID\n");
        free(card_array);
        return 0;
    }

    int index_0 = at_index(card_array, length, 0);
    int index_1 = at_index(card_array, length, 1);
    int index_01 = index_0 * 10 + index_1;

    // visa
    if (index_0 == 4)
    {
        if (length == 13 || length == 16)
        {
            if (is_valid(card_array, length))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }

        else
        {
            printf("INVALID\n");
            return 0;
        }
    }

    // amex
    else if (index_01 == 34 || index_01 == 37)
    {
        if (length != 15)
        {
            printf("INVALID\n");
            return 0;
        }

        if (!is_valid(card_array, length))
        {
            printf("INVALID\n");
            return 0;
        }

        printf("AMEX\n");
    }

    // mastercard
    else if (index_01 > 50 && index_01 < 56)
    {
        if (length != 16)
        {
            printf("INVALID\n");
            return 0;
        }

        if (!is_valid(card_array, length))
        {
            printf("INVALID\n");
            return 0;
        }

        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

    free(card_array);
}
