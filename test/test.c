/**
 * @file test.c
 *
 * Unit tests for the lwrb library
 *
 * @author Tofik Sonono (tofik@sonono.me)
 *
 */

/*======= Includes ==========================================================*/

#include "events.h"
#include "unity.h"
#include "fcfs.h"
#include "Mockevents.h"

/*======= Local Macro Definitions ===========================================*/
/*======= Local function prototypes =========================================*/
/*======= Local variable declarations =======================================*/
/*======= Global function implementations ===================================*/

/* Requires a definition for Unity to compile */

void setUp(void)
{
    Mockevents_Init();
}

void tearDown(void)
{
    Mockevents_Verify();
}

/*======= Tests ==============================================================*/

void simpleInitTest(void)
{
    fcfs_ret_code ret;

    ret = fcfs_init();
    TEST_ASSERT_EQUAL(FCFS_SUCCESS, ret);

    ret = fcfs_init();
    TEST_ASSERT_EQUAL(FCFS_BAD_STATE, ret);
}

void simpleAddAndExecuteTest_shouldSucceed(void)
{
    fcfs_ret_code ret;

    ret = fcfs_add_event(event_1, NULL, 0);
    TEST_ASSERT_EQUAL(FCFS_SUCCESS, ret);

    event_1_ExpectWithArray(NULL, 0, 0);
    ret = fcfs_execute();
    TEST_ASSERT_EQUAL(FCFS_SUCCESS, ret);
}

/*======= Main ===============================================================*/

int main (void)
{
    UNITY_BEGIN();
    RUN_TEST(simpleInitTest);
    RUN_TEST(simpleAddAndExecuteTest_shouldSucceed);
    return UNITY_END();
}
