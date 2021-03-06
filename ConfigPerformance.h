#pragma once

/*
 * Configures the hardware for maximum performance by setting the speed of the
 * peripheral bus and enabling the cache.
 */
void vHardwareConfigurePerformance( void );

/* 
 * Configure the interrupt controller to use a separate vector for each
 * interrupt.
 */
void vHardwareUseMultiVectoredInterrupts( void );
