#include "unity.h"
#include "algorithm_benchmark.h"


#ifdef TEST
void setUp(void) {
    // Code to set up resources before each test
}

void tearDown(void) {
    // Code to tear down resources after each test
}

// check_arr_conditional should return 1 for 'y' (yes) and -1 for any other char
void test_check_arr_conditional(void) {
    TEST_ASSERT_EQUAL_INT(1, check_arr_conditional('y'));
    TEST_ASSERT_EQUAL_INT(-1, check_arr_conditional('n'));
    TEST_ASSERT_EQUAL_INT(-1, check_arr_conditional('g'));
}

void test_swap_integer(void) {
    int num1 = 3;
    int num2 = 7;

    swap_integer(&num1, &num2);
    TEST_ASSERT_EQUAL_INT(7, num1);
    TEST_ASSERT_EQUAL_INT(3, num2);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_check_arr_conditional);
    RUN_TEST(test_swap_integer);
    return UNITY_END();
}
#endif