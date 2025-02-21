#ifndef PLURALITY_H
#define PLURALITY_H

#include "cs50.h"

typedef struct
{
        string name;
        int votes;
} candidate;

// Max number of candidates
#define MAX 9

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

#endif // PLURALITY_H
