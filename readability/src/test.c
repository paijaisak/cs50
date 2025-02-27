
#include "cs50.h"
#include <check.h>
#include <main.h>
#include <stdlib.h>
#include <string.h>

string grade0 = "One fish. Two fish. Red fish. Blue fish.";
string grade2 = "Would you like them here or there? I would not like them "
                "here or there. I would not like them anywhere.";
string grade3 = "Congratulations! Today is your day. You're off to Great "
                "Places! You're off and away!";
string grade5 = "Harry Potter was a highly unusual boy in many ways. For one "
                "thing, he hated the summer holidays more than any other "
                "time of year. For another, he really wanted to do his "
                "homework, but was forced to do it in secret, in the dead of "
                "the night. And he also happened to be a wizard.";
string grade7
    = "In my younger and more vulnerable years my father gave me some advice "
      "that I've been turning over in my mind ever since.";
string grade8a
    = "Alice was beginning to get very tired of sitting by her sister on the "
      "bank, and of having nothing to do: once or twice she had peeped into "
      "the book her sister was reading, but it had no pictures or "
      "conversations in it, 'and what is the use of a book,' thought Alice "
      "'without pictures or conversation?";
string grade8b
    = "When he was nearly thirteen, my brother Jem got his arm badly broken "
      "at "
      "the elbow. When it healed, and Jem's fears of never being able to play "
      "football were assuaged, he was seldom self-conscious about his injury. "
      "His left arm was somewhat shorter than his right; when he stood or "
      "walked, the back of his hand was at right angles to his body, his "
      "thumb "
      "parallel to his thigh.";
string grade9 = "There are more things in Heaven and Earth, Horatio, than "
                "are dreamt of in your philosophy.";
string grade10
    = "It was a bright cold day in April, and the clocks were striking "
      "thirteen. Winston Smith, his chin nuzzled into his breast in an effort "
      "to escape the vile wind, slipped quickly through the glass doors of "
      "Victory Mansions, though not quickly enough to prevent a swirl of "
      "gritty dust from entering along with him.";
string grade16 = "A large class of computational problems involve the "
                 "determination of properties of graphs, digraphs, integers, "
                 "arrays of integers, finite families of finite sets, "
                 "boolean formulas and elements of other countable domains.";

// Define a test case
START_TEST(test_example) { ck_assert_str_eq("hello", "hello"); }
END_TEST

START_TEST(test01) { ck_assert_int_eq(test_score(grade0), 0); }
END_TEST

START_TEST(test02) { ck_assert_int_eq(test_score(grade2), 2); }
END_TEST

START_TEST(test03) { ck_assert_int_eq(test_score(grade3), 3); }
END_TEST

START_TEST(test04) { ck_assert_int_eq(test_score(grade5), 5); }
END_TEST

START_TEST(test05) { ck_assert_int_eq(test_score(grade7), 7); }
END_TEST

START_TEST(test06) { ck_assert_int_eq(test_score(grade8a), 8); }
END_TEST

START_TEST(test07) { ck_assert_int_eq(test_score(grade8b), 8); }
END_TEST

START_TEST(test08) { ck_assert_int_eq(test_score(grade9), 9); }
END_TEST

START_TEST(test09) { ck_assert_int_eq(test_score(grade10), 10); }
END_TEST

START_TEST(test10) { ck_assert_int_eq(test_score(grade16), 16); }
END_TEST

START_TEST(count_letters01)
{
        ck_assert_int_eq(count_letters("Abk, f asdk o23j."), 10);
}
END_TEST

START_TEST(count_words01) { ck_assert_int_eq(count_words(grade0), 8); }
END_TEST

START_TEST(count_sentences01)
{
        ck_assert_int_eq(count_sentences(grade0), 4);
}
END_TEST

// Create a suite and add the test case to it
Suite*
readability_suite(void)
{
        Suite* s;
        TCase* tc_core;

        s = suite_create("Readability");

        tc_core = tcase_create("Core");
        tcase_add_test(tc_core, test_example);
        tcase_add_test(tc_core, test01);
        tcase_add_test(tc_core, test02);
        tcase_add_test(tc_core, test03);
        tcase_add_test(tc_core, test04);
        tcase_add_test(tc_core, test05);
        tcase_add_test(tc_core, test06);
        tcase_add_test(tc_core, test07);
        tcase_add_test(tc_core, test08);
        tcase_add_test(tc_core, test09);
        tcase_add_test(tc_core, test10);
        tcase_add_test(tc_core, count_letters01);
        tcase_add_test(tc_core, count_words01);
        tcase_add_test(tc_core, count_sentences01);

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
