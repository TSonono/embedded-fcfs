/**
 * @file fcfs.c
 *
 * Description
 *
 */

/*======= Includes ==========================================================*/

#include "fcfs.h"
#include "lwrb/lwrb.h"

#ifdef FCFS_DEBUG
#include <assert.h>
#endif

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/*======= Local Macro Definitions ===========================================*/
/*======= Type Definitions ==================================================*/

struct fcfs_event {
    fcfs_event_callback event;
    uint8_t event_data[FCFS_MAX_EVENT_DATA_LENGTH];
    size_t event_data_len;
};

/*======= Local function prototypes =========================================*/
/*======= Local variable declarations =======================================*/

static bool lib_is_initalized = false;
static lwrb_t queue;
static uint8_t
    buff_data[sizeof(struct fcfs_event) * (FCFS_EVENT_QUEUE_LENGTH + 1)];

/*======= Global function implementations ===================================*/

fcfs_ret_code fcfs_init(void) {
    if (!lib_is_initalized) {
        lib_is_initalized = true;
    } else {
        return FCFS_BAD_STATE;
    }

    lwrb_init(&queue, buff_data, sizeof(buff_data));
    return FCFS_SUCCESS;
}

fcfs_ret_code fcfs_execute(void) {
    if (!lwrb_is_ready(&queue)) {
        return FCFS_NOT_INITIALIZED;
    }

    struct fcfs_event current_event = {0};

    while (1) {
        size_t n_read =
            lwrb_read(&queue, &current_event, sizeof(struct fcfs_event));

        if ((n_read > 0) && (n_read != sizeof(struct fcfs_event))) {
            return FCFS_BAD_QUEUE_DATA;
        } else if (0 == n_read) {
            // No events left in queue
            return FCFS_SUCCESS;
        } else {
            size_t event_data_len = current_event.event_data_len;
            if (event_data_len > 0) {
                current_event.event(current_event.event_data, event_data_len);
            } else {
                current_event.event(NULL, 0);
            }
        }
    }

#ifdef FCFS_DEBUG
    assert(0);
#endif
    return FCFS_BAD_STATE;
}

// TODO: Include critical region abstraction here?
fcfs_ret_code fcfs_add_event(fcfs_event_callback event, void *event_data,
                             size_t data_size) {
    if (!lwrb_is_ready(&queue)) {
        return FCFS_NOT_INITIALIZED;
    }

    if (data_size > FCFS_MAX_EVENT_DATA_LENGTH) {
        return FCFS_EVENT_DATA_TOO_LONG;
    }

    struct fcfs_event event_to_add = {0};
    event_to_add.event = event;
    if ((event != NULL) && (data_size > 0)) {
        event_to_add.event_data_len = data_size;
        memcpy(event_to_add.event_data, event_data, data_size);
    } else {
        event_to_add.event_data_len = 0;
    }

    size_t n_written =
        lwrb_write(&queue, &event_to_add, sizeof(struct fcfs_event));

    if (n_written != sizeof(struct fcfs_event)) {
        return FCFS_OUT_OF_MEMORY;
    }

    return FCFS_SUCCESS;
}

/*======= Local function implementations ====================================*/
