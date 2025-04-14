#include "readability.h"
#include "cs50.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int
test_score(string text)
{
	if (text == NULL) {
		return 0;
	}

	int number_of_letters = count_letters(text);
	int number_of_words = count_words(text);
	int number_of_sentences = count_sentences(text);

	// Prevent division by zero
	if (number_of_words <= 0) {
		return 0;
	}

	const float letters
	    = ((float) number_of_letters / (float) number_of_words) * 100.0F;
	const float sentences
	    = ((float) number_of_sentences / (float) number_of_words) * 100.0F;

	int index
	    = (int) roundf((0.0588F * letters) - (0.296F * sentences) - 15.8F);

	if (index < 1)
	{
		return 0;
	}

	if (index > 16)
	{
		return 16;
	}

	return index;
}

int
count_letters(const string text)
{
	if (text == NULL) {
		return 0;
	}

	int res = 0;
	int i = 0;

	// Safer loop that doesn't read past the null terminator
	while (text[i] != '\0')
	{
		if (isalpha(text[i]))
		{
			res++;
		}
		i++;
	}

	return res;
}

int
count_words(string text)
{
	if (text == NULL) {
		return 0;
	}

	int word_count = 0;
	int i = 0;
	bool in_word = false;

	// Count words more accurately by tracking transitions from non-space to space
	while (text[i] != '\0')
	{
		if (!isspace(text[i]) && !in_word)
		{
			// Transition into a word
			in_word = true;
			word_count++;
		}
		else if (isspace(text[i]) && in_word)
		{
			// Transition out of a word
			in_word = false;
		}
		i++;
	}

	return word_count;
}

int
count_sentences(string text)
{
	if (text == NULL) {
		return 0;
	}

	int sentence_count = 0;
	int i = 0;

	// Safer loop that doesn't read past the null terminator
	while (text[i] != '\0')
	{
		// Count sentence-ending punctuation
		if (text[i] == '!' || text[i] == '?' || text[i] == '.')
		{
			sentence_count++;
		}
		i++;
	}

	return sentence_count;
}
