#include "cs50.h"
#include <ctype.h>
#include <stdio.h>

string alphabet = "abcdefghijklmnopqrstuvwxyz";

int values[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                  1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int strlength(string s);
int sum_points(string s, int l);
int get_point(char c);
void lower(string s, int l);

int main(void) {
  string player01 = get_string("Player 1: ");
  string player02 = get_string("Player 2: ");

  int length01 = strlength(player01);
  int length02 = strlength(player02);

  // printf("length 01 = %d", length01);
  // printf("length 02 = %d", length02);

  lower(player01, length01);
  lower(player02, length02);

  int points01 = sum_points(player01, length01);
  int points02 = sum_points(player02, length02);

  if (points01 < points02) {
    printf("Player 2 wins!\n");
  }

  else if (points01 > points02) {
    printf("Player 1 wins!\n");
  }

  else {
    printf("Tie!\n");
  }

  // printf("%s\n", player_one);
  // printf("length: %d\n", length01);
  // printf("points = %d\n", sum_points(player_one, length01));

  return 0;
}

void lower(string s, int l) {
  for (int i = 0; i < l; i++) {
    if (isupper(s[i])) {
      s[i] = tolower(s[i]);
    }
  }
}

int strlength(string s) {
  int i = 0;
  char c = s[i];

  while (c != '\0') {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
      c = s[i];
      i++;
    } else {
      break;
    }
  }

  return i - 1;
}

int sum_points(string s, int l) {
  int points = 0;

  for (int i = 0; i < l; i++) {
    points += get_point(s[i]);
  }

  return points;
}

int get_point(char c) {
  int found = 0;
  int index = 0;

  if ((c < 'A') || (c > 'Z' && c < 'a') || c > 'z') {
    return 0;
  }

  while (found == 0) {
    if (c == alphabet[index]) {
      found = 1;
    } else {
      index++;
    }
  }

  return values[index];
}
