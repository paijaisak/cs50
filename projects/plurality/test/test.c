#include "plurality.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
setup(void)
{
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

START_TEST(test4)
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
// Create a suite and add the test case to it
Suite *
readability_suite(void)
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

	s = readability_suite();
	sr = srunner_create(s);

	srunner_set_xml(sr, "test_results.xml");
	srunner_set_fork_status(sr, CK_NOFORK);

	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);

	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
