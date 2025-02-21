#include "plurality.h"
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
        // Check for invalid usage
        if (argc < 2)
        {
                printf("Usage: plurality [candidate ...]\n");
                return 1;
        }

        // Populate array of candidates
        candidate_count = argc - 1;
        if (candidate_count > MAX)
        {
                printf("Maximum number of candidates is %i\n", MAX);
                return 2;
        }
        for (int i = 0; i < candidate_count; i++)
        {
                candidates[i].name = argv[i + 1];
                candidates[i].votes = 0;
        }

        int voter_count = get_int("Number of voters: ");

        // Loop over all voters
        for (int i = 0; i < voter_count; i++)
        {
                string name = get_string("Vote: ");

                // Check for invalid vote
                if (!vote(name))
                {
                        printf("Invalid vote.\n");
                }
        }

        // Display winner of election
        print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
        // TODO
        return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
        // TODO
        return;
}
