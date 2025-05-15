#include "plurality.h"
#include <stdio.h>
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

// Print the winner (or winners) of the election
void
print_winner(void)
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
		printf("Winner is %s with %d points!\n",
		    candidates[winner_index].name,
		    candidates[winner_index].votes);
	}
}
