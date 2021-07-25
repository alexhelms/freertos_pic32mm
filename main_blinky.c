/* Standard includes. */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

/* The period of the blinky software timer.  The period is specified in ms and
converted to ticks using the portTICK_PERIOD_MS constant. */
#define mainBLINKY_TIMER_PERIOD             ( 10 / portTICK_PERIOD_MS )

/*
 * The callback function for the blinky software timer, as described at the top
 * of this file.
 */
static void prvBlinkyTimerCallback(TimerHandle_t xTimer);

void main_blinky(void)
{
    TimerHandle_t xTimer;

    /* Create the blinky software timer as described at the top of this
		file. */
    xTimer = xTimerCreate("Blinky",					/* A text name, purely to help debugging. */
                          mainBLINKY_TIMER_PERIOD,  /* The timer period. */
                          pdTRUE,					/* This is an auto-reload timer, so xAutoReload is set to pdTRUE. */
                          NULL,				        /* The ID is not used, so can be set to anything. */
                          prvBlinkyTimerCallback    /* The callback function that inspects the status of all the other tasks. */
                          );

    if(xTimer)
    {
        xTimerStart(xTimer, 0);
    }

    /* Start the tasks and timer running. */
    vTaskStartScheduler();

    /* If all is well, the scheduler will now be running, and the following
	line will never be reached.  If the following line does execute, then
	there was insufficient FreeRTOS heap memory available for the idle and/or
	timer tasks	to be created.  See the memory management section on the
	FreeRTOS web site for more details. */
	for( ;; );
}

static void prvBlinkyTimerCallback(TimerHandle_t xTimer)
{
    // Enable LED1 as output
    TRISDbits.TRISD3 = 0;

    // Toggle LED1
	LATDbits.LATD3 ^= 1;
}