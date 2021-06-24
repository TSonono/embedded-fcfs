/**
 * @file test.c
 *
 * Unit tests for the lwrb library
 *
 * @author Tofik Sonono (tofik@sonono.me)
 *
 */

/*======= Includes ==========================================================*/

#include "unity.h"
#include "fcfs.h"

/*======= Local Macro Definitions ===========================================*/
/*======= Local function prototypes =========================================*/
/*======= Local variable declarations =======================================*/
/*======= Global function implementations ===================================*/

/* Requires a definition for Unity to compile */

void setUp(void) { }

void tearDown(void) { }

/*======= Tests ==============================================================*/

void init_test(void) {
    bool ret = fcfs_init();
    TEST_ASSERT_EQUAL(true, ret);
}

/*======= Main ===============================================================*/

int main (void) {
    UNITY_BEGIN();
    RUN_TEST(init_test);
    return UNITY_END();
}