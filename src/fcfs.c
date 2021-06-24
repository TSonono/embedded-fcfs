/**
 * @file fcfs.c
 *
 * Description
 *
 */

/*======= Includes ==========================================================*/

#include <stdint.h>
#include "fcfs.h"
#include "lwrb/lwrb.h"

/*======= Local Macro Definitions ===========================================*/
/*======= Type Definitions ==================================================*/
/*======= Local function prototypes =========================================*/
/*======= Local variable declarations =======================================*/

static lwrb_t queue;
static uint8_t buff_data[1024];

/*======= Global function implementations ===================================*/

bool fcfs_init(void)
{
    return lwrb_init(&queue, buff_data, sizeof(buff_data));
}

/*======= Local function implementations ====================================*/
