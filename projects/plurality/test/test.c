#include "plurality.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

void
setup(void)
{
	candidate_count = 3; // Set the number of candidates
	init_candidate(0, "Alice");
	init_candidate(1, "Bob");
	init_candidate(2, "Paya");
}

void
teardown(void)
{
	for (int i = 0; i < MAX; i++)
	{
		candidates[i].name = NULL;
		candidates[i].votes = 0;
	}
}

START_TEST(test1)
{
	ck_assert(vote("Alice"));
	ck_assert(vote("Bob"));
	ck_assert(vote("Paya"));
}
END_TEST

START_TEST(test2)
{
	ck_assert(!vote("bing"));
	ck_assert(!vote("flippi"));
}
END_TEST

START_TEST(test3)
{
	vote("Alice");
	ck_assert(candidates[0].votes == 1);
}
END_TEST

START_TEST(test4)
{
	vote("Bob");
	ck_assert(candidates[1].votes == 1);
}
END_TEST

START_TEST(test5)
{
	vote("Alice");
	ck_assert(candidates[2].votes == 0);
}
END_TEST

START_TEST(test6)
{
	vote("Alice");
	vote("Bob");
	vote("Bob");
	vote("Bob");
	vote("Paya");
	vote("Paya");

	ck_assert_int_eq(1, candidates[0].votes);
	ck_assert_int_eq(3, candidates[1].votes);
	ck_assert_int_eq(2, candidates[2].votes);
}
END_TEST

START_TEST(test7)
{
	vote("Alice");
	vote("Bob");
	vote("Bob");
	vote("Bob");
	vote("Paya");
	vote("Paya");
	vote("False");
	vote("Name");

	ck_assert_int_eq(1, candidates[0].votes);
	ck_assert_int_eq(3, candidates[1].votes);
	ck_assert_int_eq(2, candidates[2].votes);
}
END_TEST

START_TEST(test8)
{
	vote("Alice");

	int number_of_winners = 0;

	candidate *winner = get_winner(candidates, &number_of_winners);
	ck_assert_int_eq(1, number_of_winners);
	ck_assert_str_eq("Alice", winner->name);

	printf("%s", candidates[0].name);

	free(winner);
}
END_TEST

START_TEST(test9)
{
	vote("Alice");
	vote("Alice");
	vote("Bob");
	vote("Paya");
	vote("Bing");
	vote("Paya");

	int number_of_winners = 0;
	candidate *winner = get_winner(candidates, &number_of_winners);
	ck_assert_int_eq(2, number_of_winners);

	ck_assert_str_eq("Alice", winner[0].name);

	free(winner);
}
END_TEST

START_TEST(test10)
{
	vote("Alice");
	vote("Alice");
	vote("Bob");
	vote("Paya");
	vote("Bing");
	vote("Paya");

	int number_of_winners = 0;
	candidate *winners = get_winner(candidates, &number_of_winners);
	ck_assert_int_eq(2, number_of_winners);

	ck_assert_str_eq("Paya", winners[1].name);

	free(winners);
}
END_TEST

// Create a suite and add the test case to it
Suite *
plurality_suite(void)
{
	Suite *suite;
	TCase *tc_core;

	suite = suite_create("Plurality");

	tc_core = tcase_create("Core");
	tcase_add_checked_fixture(tc_core, setup, teardown);

	tcase_add_test(tc_core, test1);
	tcase_add_test(tc_core, test2);
	tcase_add_test(tc_core, test3);
	tcase_add_test(tc_core, test4);
	tcase_add_test(tc_core, test5);
	tcase_add_test(tc_core, test6);
	tcase_add_test(tc_core, test7);
	tcase_add_test(tc_core, test8);
	tcase_add_test(tc_core, test9);
	tcase_add_test(tc_core, test10);

	suite_add_tcase(suite, tc_core);

	return suite;
}

// Main function to run the tests
int
main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = plurality_suite();
	sr = srunner_create(s);

	srunner_set_xml(sr, "test_results.xml");
	srunner_set_fork_status(sr, CK_NOFORK);

	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);

	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
