#include "unity.h"
#include "algorithm_benchmark.h"


#ifdef TEST
void setUp(void) {
    // Code to set up resources before each test
}

void tearDown(void) {
    // Code to tear down resources after each test
}

void test_check_arr_conditional(void) {
    TEST_ASSERT_EQUAL_INT(1, check_arr_conditional('y'));
    TEST_ASSERT_EQUAL_INT(-1, check_arr_conditional('n'));
    TEST_ASSERT_EQUAL_INT(-1, check_arr_conditional('g'));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_check_arr_conditional);
    return UNITY_END();
}
#endif