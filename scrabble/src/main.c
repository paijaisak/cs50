#include <ctype.h>
#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* init_alphabet()
{
    char* alphabet = malloc(sizeof(char) * 26);
    
    alphabet = "abcdefghijklmnopqrstuvxyz";

    return alphabet;
}

// arguments are mutable!!
void init_ones(int* points, char* alphabet)
{
    for (int i = 0; i < 27; i++)
    {
        char letter = alphabet[i];
        
        int points_found = 0;
        
        if (points_found >= 10)
        {
            break;
        }

        if (letter == 'a')
        {
            points[i] = 1;
            points_found++;
        }

        if (letter == 'e')
        {
            points[i] = 1;
            points_found++;
        }

        if (letter == 'i')
        {
            points[i] = 1;
            points_found++;
        }

        if (letter == 'l')
        {
            points[i] = 1;
            points_found++;
        }

        if (letter == 'n')
        {
            points[i] = 1;
            points_found++;
        }

        if (letter == 'o')
        {
            points[i] = 1;
            points_found++;
        }

        if (letter == 'r')
        {
            points[i] = 1;
            points_found++;
        }

        if (letter == 's')
        {
            points[i] = 1;
            points_found++;
        }

        if (letter == 't')
        {
            points[i] = 1;
            points_found++;
        }

        if (letter == 'u')
        {
            points[i] = 1;
            points_found++;
        }
    }
}

void init_twos(int* points, char* alphabet)
{
    for (int i = 0; i < 27; i++)
    {
        char letter = alphabet[i];
        
        int points_found = 2;
        
        if (points_found >= 2)
        {
            break;
        }

        if (letter == 'd' || letter == 'g')
        {
            points[i] = 2;
            points_found++;
        }
    }
}

void init_threes(int* points, char* alphabet)
{
    for (int i = 0; i < 27; i++)
    {
        char letter = alphabet[i];
        
        int points_found = 0;
        
        if (points_found >= 4)
        {
            break;
        }

        if (letter == 'b' || letter == 'c' || letter == 'm' || letter == 'p')
        {
            points[i] = 3;
            points_found++;
        }
    }
}

void init_fours(int* points, char* alphabet)
{
    for (int i = 0; i < 27; i++)
    {
        char letter = alphabet[i];
        
        int points_found = 0;
        
        if (points_found >= 5)
        {
            break;
        }

        if (letter == 'f' || letter == 'h' || letter == 'v' || letter == 'w' || letter == 'y')
        {
            points[i] = 4;
            points_found++;
        }
    }
}

void init_fives(int* points, char* alphabet)
{
    points[10] = 5;
}

void init_eights(int* points, char* alphabet)
{
    for (int i = 0; i < 27; i++)
    {
        char letter = alphabet[i];
        
        int points_found = 0;
        
        if (points_found >= 2)
        {
            break;
        }

        if (letter == 'j' || letter == 'x')
        {
            points[i] = 8;
            points_found++;
        }
    }
}

void init_tens(int* points, char* alphabet)
{
    for (int i = 0; i < 27; i++)
    {
        char letter = alphabet[i];
        
        int points_found = 0;
        
        if (points_found >= 2)
        {
            break;
        }

        if (letter == 'q' || letter == 'z')
        {
            points[i] = 10;
            points_found++;
        }
    }
}


int* init_points(char* alphabet)
{
    int* points = (int*) malloc(sizeof(int) * 26);

    // int* ones[10] = {0, 4, 8, 11, 13, 14, 17, 18, 19, 20};

    // ONES: A, E, I, L, N, O, R, S, T, U
    
    init_ones(points, alphabet);

    printf("index 0-a = %d, index 4-e = %d", points[0], points[4]);

    return points;
}

int main()
{
    string input_01 = get_string("Player 1: ");
    string input_02 = get_string("Player 2: ");
    
    char* alphabet = init_alphabet();
    int* points = init_points(alphabet);

    printf("%s and %s\n", input_01, input_02);

    for (int i = 0; i < 27; i++)
    {
        printf("letter: %c\npoints: %d\n\n", alphabet[i], points[i]);
    }

    //free(alphabet);
    //free(points);
}
