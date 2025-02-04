#include "encrypt.h"
#include <check.h>
#include <stdlib.h>
#include <string.h>

// Test case for substitution cipher with key 1
START_TEST(test_substitution_cipher_key1)
{
    char plaintext[] = "hello";
    char expected[] = "ifmmp"; // Example expected output with key
                               // "bcdefghijklmnopqrstuvwxyza"
    string ciphertext;
    char cipher[] = "bcdefghijklmnopqrstuvwxyza";

    ciphertext = encrypt(plaintext, cipher);

    ck_assert_str_eq(ciphertext, expected);
}
END_TEST

// Test case for substitution cipher with key 2
START_TEST(test_substitution_cipher_key2)
{
    char plaintext[] = "hello";
    char expected[] = "khoor"; // Example expected output with key
                               // "defghijklmnopqrstuvwxyzabc"
    string ciphertext;
    char key[] = "defghijklmnopqrstuvwxyzabc";

    ciphertext = encrypt(plaintext, key);

    ck_assert_str_eq(ciphertext, expected);
}
END_TEST

START_TEST(test_substitution_cipher_key3)
{
    char plaintext[] = "flee at once. we are discovered!";
    char expected[]
        = "siaa zq lkba. va zoa rfpbluaoar!"; // Example expected output with key
                                              // "defghijklmnopqrstuvwxyzabc"
    string ciphertext;
    char key[] = "zebrascdfghijklmnopqtuvwxy";

    ciphertext = encrypt(plaintext, key);

    ck_assert_str_eq(ciphertext, expected);
}
END_TEST

// Create a suite and add the test case to it
Suite*
readability_suite(void)
{
    Suite* s;
    TCase* tc_core;

    s = suite_create("Substitution");

    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_substitution_cipher_key1);
    tcase_add_test(tc_core, test_substitution_cipher_key2);
    tcase_add_test(tc_core, test_substitution_cipher_key3);

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
