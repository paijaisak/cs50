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
        for (int i = 0; i < candidate_count; i++)
        {
                if (strcmp(name, candidates[i].name) == 0)
                {
                        candidates[i].votes++;
                        return true;
                }
        }

        return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
        int hi_score = 0;
        int winner_index = 0;

        int winners = 0;
        int winner_indexes[candidate_count];

        for (int i = 0; i < candidate_count; i++)
        {
                if (candidates[i].votes > hi_score)
                {
                        hi_score = candidates[i].votes;
                        winner_index = i;
                }

                // also initialize array
                winner_indexes[i] = 0;
        }

        for (int i = 0; i < candidate_count; i++)
        {
                if (candidates[i].votes == hi_score)
                {
                        winner_indexes[i] = 1;
                        winners++;
                }
        }

        if (winners > 1)
        {
                printf("Winners are %s with ", "Paija");

                for (int i = 0; i < winners; i++)
                {
                        printf("%d points", 3);
                }
        }
        else
        {
                printf("Winner is %s with %d points!\n", candidates[winner_index].name, candidates[winner_index].votes);
        }

        // TODO
        return;
}

