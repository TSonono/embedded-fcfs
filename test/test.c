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

void useApiBeforeInit_should_fail(void)
{
    fcfs_ret_code ret = fcfs_add_event(event_1, NULL, 0);
    TEST_ASSERT_EQUAL(FCFS_NOT_INITIALIZED, ret);

    ret = fcfs_execute();
    TEST_ASSERT_EQUAL(FCFS_NOT_INITIALIZED, ret);
}

void simpleInitTest_should_success_fail(void)
{
    fcfs_ret_code ret;

    ret = fcfs_init();
    TEST_ASSERT_EQUAL(FCFS_SUCCESS, ret);

    ret = fcfs_init();
    TEST_ASSERT_EQUAL(FCFS_BAD_STATE, ret);
}

void badAddToEventQueue_shouldSucceed(void)
{
    fcfs_ret_code ret;
    uint8_t data = 5;

    ret = fcfs_add_event(NULL, &data, sizeof(data));
    TEST_ASSERT_EQUAL(FCFS_BAD_PARAM, ret);

    ret = fcfs_add_event(event_1, &data, 0);
    TEST_ASSERT_EQUAL(FCFS_BAD_PARAM, ret);

    ret = fcfs_add_event(event_1, NULL, 5);
    TEST_ASSERT_EQUAL(FCFS_BAD_PARAM, ret);
}

void simpleAddAndExecuteTest_shouldSucceed(void)
{
    fcfs_ret_code ret;

    ret = fcfs_add_event(event_1, NULL, 0);
    TEST_ASSERT_EQUAL(FCFS_SUCCESS, ret);

    uint8_t data_to_pass = 100;
    ret = fcfs_add_event(event_2, &data_to_pass, sizeof(data_to_pass));
    TEST_ASSERT_EQUAL(FCFS_SUCCESS, ret);

    event_1_ExpectWithArray(NULL, 0, 0);
    event_2_ExpectWithArray(&data_to_pass, sizeof(data_to_pass), sizeof(data_to_pass));
    ret = fcfs_execute();
    TEST_ASSERT_EQUAL(FCFS_SUCCESS, ret);
}

void eventQueueOutOfMemory(void)
{
    fcfs_ret_code ret;
    for (size_t i = 0; i < FCFS_EVENT_QUEUE_LENGTH; i++) {
        ret = fcfs_add_event(event_1, NULL, 0);
        TEST_ASSERT_EQUAL(FCFS_SUCCESS, ret);
    }
    ret = fcfs_add_event(event_1, NULL, 0);
    TEST_ASSERT_EQUAL(FCFS_OUT_OF_MEMORY, ret);
}

/*======= Main ===============================================================*/

int main (void)
{
    UNITY_BEGIN();
    RUN_TEST(useApiBeforeInit_should_fail);
    RUN_TEST(simpleInitTest_should_success_fail);
    // Don't change the order of the above two tests

    RUN_TEST(badAddToEventQueue_shouldSucceed);
    RUN_TEST(simpleAddAndExecuteTest_shouldSucceed);
    RUN_TEST(eventQueueOutOfMemory);
    return UNITY_END();
}
