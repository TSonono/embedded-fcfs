#ifndef _fcfs_H_
#define _fcfs_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file fcfs.h
 *
 * Description
 *
 */

/*======= Includes ==========================================================*/

#include "lwrb/lwrb.h"
#include <stddef.h>

/*======= Public macro definitions ==========================================*/

#ifndef FCFS_EVENT_QUEUE_LENGTH
#define FCFS_EVENT_QUEUE_LENGTH 15
#endif

#ifndef FCFS_MAX_EVENT_DATA_LENGTH
#define FCFS_MAX_EVENT_DATA_LENGTH 1
#endif

#if FCFS_MAX_EVENT_DATA_LENGTH > UINT8_MAX
#error "FCFS_MAX_EVENT_DATA_LENGTH should be small, ideally only 1 byte. This library only supports values up to 255"
#endif

/*======= Type Definitions and declarations* =================================*/

typedef enum fcfs_ret_code_e {
    FCFS_SUCCESS = 0,
    FCFS_BAD_PARAM,
    FCFS_OUT_OF_MEMORY,
    FCFS_UNKNOWN_ERROR,
    FCFS_BAD_QUEUE_DATA,
    FCFS_BAD_STATE,
    FCFS_NOT_INITIALIZED,
} fcfs_ret_code;

typedef void (*fcfs_event_callback)(void *event_data, size_t data_size);

/*======= Public variable declarations ======================================*/
/*======= Public function declarations ======================================*/

/**
 * @brief Initializes the fcfs library
 *
 */
fcfs_ret_code fcfs_init(void);


fcfs_ret_code fcfs_execute(void);

fcfs_ret_code fcfs_add_event(fcfs_event_callback event, void *event_data,
                             size_t data_size);

#ifdef __cplusplus
}
#endif

#endif /* _fcfs_H_ */
