#include "encipher.h"
#include <check.h>
#include <stdlib.h>
#include <string.h>

START_TEST(encrypt1)
{
        char plaintext[] = "A";
        char expected[] = "Z";

        char cipher[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

        ck_assert(validate_cipher(cipher));

        string ciphertext = encipher(plaintext, cipher);

        ck_assert_str_eq(ciphertext, expected);
}
END_TEST

START_TEST(encrypt2)
{
        char plaintext[] = "a";
        char expected[] = "z";

        char cipher[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

        ck_assert(validate_cipher(cipher));

        string ciphertext = encipher(plaintext, cipher);

        ck_assert_str_eq(ciphertext, expected);
}

START_TEST(encrypt3)
{
        char plaintext[] = "ABC";
        char expected[] = "NJQ";

        char cipher[] = "NJQSUYBRXMOPFTHZVAWCGILKED";

        ck_assert(validate_cipher(cipher));

        string ciphertext = encipher(plaintext, cipher);

        ck_assert_str_eq(ciphertext, expected);
}

START_TEST(encrypt4)
{
        char plaintext[] = "XyZ";
        char expected[] = "KeD";

        char cipher[] = "NJQSUYBRXMOPFTHZVAWCGILKED";

        ck_assert(validate_cipher(cipher));

        string ciphertext = encipher(plaintext, cipher);

        ck_assert_str_eq(ciphertext, expected);
}

START_TEST(encrypt5)
{
        char plaintext[] = "This is CS50";
        char expected[] = "Cbah ah KH50";

        char cipher[] = "YUKFRNLBAVMWZTEOGXHCIPJSQD";

        ck_assert(validate_cipher(cipher));

        string ciphertext = encipher(plaintext, cipher);

        ck_assert_str_eq(ciphertext, expected);
}

START_TEST(encrypt6)
{
        char plaintext[] = "This is CS50";
        char expected[] = "Cbah ah KH50";

        char cipher[] = "yukfrnlbavmwzteogxhcipjsqd";

        ck_assert(validate_cipher(cipher));

        string ciphertext = encipher(plaintext, cipher);

        ck_assert_str_eq(ciphertext, expected);
}

START_TEST(encrypt7)
{
        char plaintext[] = "This is CS50";
        char expected[] = "Cbah ah KH50";

        char cipher[] = "YUKFRNLBAVMWZteogxhcipjsqd";

        ck_assert(validate_cipher(cipher));

        string ciphertext = encipher(plaintext, cipher);

        ck_assert_str_eq(ciphertext, expected);
}

START_TEST(encrypt8)
{
        char plaintext[] = "The quick brown fox jumps over the lazy dog";
        char expected[] = "Rqx tokug wljif nja eozby jhxl rqx cdmv sjp";

        char cipher[] = "DWUSXNPQKEGCZFJBTLYROHIAVM";

        ck_assert(validate_cipher(cipher));

        string ciphertext = encipher(plaintext, cipher);

        ck_assert_str_eq(ciphertext, expected);
}

START_TEST(encrypt9)
{
        char plaintext[] = "Shh... Don't tell!";
        char expected[] = "Yqq... Sjf'r rxcc!";

        char cipher[] = "DWUSXNPQKEGCZFJBTLYROHIAVM";

        ck_assert(validate_cipher(cipher));

        string ciphertext = encipher(plaintext, cipher);

        ck_assert_str_eq(ciphertext, expected);
}

// Create a suite and add the test case to it
Suite*
readability_suite(void)
{
        Suite* s;
        TCase* tc_core;

        s = suite_create("Substitution");

        tc_core = tcase_create("Core");

        tcase_add_test(tc_core, encrypt1);
        tcase_add_test(tc_core, encrypt2);
        tcase_add_test(tc_core, encrypt3);
        tcase_add_test(tc_core, encrypt4);
        tcase_add_test(tc_core, encrypt5);
        tcase_add_test(tc_core, encrypt6);
        tcase_add_test(tc_core, encrypt7);
        tcase_add_test(tc_core, encrypt8);
        tcase_add_test(tc_core, encrypt9);

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
