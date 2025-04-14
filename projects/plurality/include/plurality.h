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
extern int candidate_count;

// Function prototypes
void init_candidate(int index, string name);
bool vote(string name);
void print_winner(void);

#endif // PLURALITY_H
