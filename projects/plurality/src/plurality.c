#include "plurality.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the candidate_count variable (declared as extern in the header)
int candidate_count = 0;

void
init_candidate(int index, string name)
{
	candidates[index].name = name;
	candidates[index].votes = 0;
}

// Update vote totals given a new vote
bool
vote(string name)
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

candidate *
get_winner(candidate *candidates, int *out_winners)
{
	int hi_score = 0;
	int winner_index = 0;

	int winner_count = 0;
	int winner_indexes[candidate_count];

	// find highest score
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

	// how many candidates have the highscore
	for (int i = 0; i < candidate_count; i++)
	{
		if (candidates[i].votes == hi_score)
		{
			winner_indexes[i] = 1;
			winner_count++;
		}
	}

	*out_winners = winner_count;

	if (winner_count > 1)
	{
		candidate *winners = malloc(sizeof(candidate) * winner_count);

		if (winners == NULL)
			return NULL;

		int winner_index = 0;

		for (int i = 0; i < candidate_count; i++)
		{
			if (winner_indexes[i] == 1)
			{
				winners[winner_index].name
				    = candidates[winner_indexes[i]].name;
				winners[winner_index].votes
				    = candidates[winner_indexes[i]].votes;

				winner_index++;

				printf("name = %s", winners[winner_index].name);
			}
		}

		return winners;
	}

	else
	{
		candidate *winner = malloc(sizeof(candidate));

		winner->name = candidates[winner_index].name;
		winner->votes = candidates[winner_index].votes;

		return winner;
	}
}

// Print the winner (or winners) of the election
void
print_winner(void)
{
	// int number_of_winners = 0;
	// int *out_winners = &number_of_winners;

	// candidate *winner = get_winner(candidates, out_winners);

	// {
	// 	printf("Winner is %s with %d points!\n",
	// 	    candidates[winner_index].name,
	// 	    candidates[winner_index].votes);
	// }
}
