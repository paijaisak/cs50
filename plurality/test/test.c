#include <check.h>
#include <stdlib.h>
#include <string.h>

START_TEST(test1)
{
    printf("Test1");
}
END_TEST


// Create a suite and add the test case to it
Suite*
readability_suite(void)
{
        Suite* s;
        TCase* tc_core;

        s = suite_create("Plurality");

        tc_core = tcase_create("Core");

        tcase_add_test(tc_core, test1);

        suite_add_tcase(s, tc_core);

        return s;
}

// Main function to run the tests
int main(void)
{
        int number_failed;
        Suite* s;
        SRunner* sr;

        s = readability_suite();
        sr = srunner_create(s);

        srunner_set_xml(sr, "test_results.xml");
        srunner_set_fork_status(sr, CK_NOFORK);

        srunner_run_all(sr, CK_VERBOSE);
        number_failed = srunner_ntests_failed(sr);

        srunner_free(sr);

        return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
