#include <atmel_start.h>

#if defined(__GNUC__)
#include <avr/sleep.h>
#elif defined(__ICCAVR__)
#include <intrinsics.h>
#define sleep_cpu() __sleep()
#endif

extern volatile uint8_t measurement_done_touch;
int main(void)
{
    uint8_t sensor_state = 0, new_state;
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

    cpu_irq_enable(); /* Global Interrupt Enable */

    touch_start();

	/* Replace with your application code */
	while (1) {
	    touch_process();
	    if (measurement_done_touch == 1) {
		    measurement_done_touch = 0;
            new_state = get_sensor_state(0);
            if (new_state != sensor_state) {
    		    if (new_state & 0x80) {
        		    CHG_set_level(false);
    		    }
    		    else{
        		    CHG_set_level(true);
    		    }

                sensor_state = new_state;
            }
	    }

        if (touch_sleep() == 0) {
            sleep_cpu();
        }

#ifdef USE_WDT
        CLR_WDT();
#endif
	}
}
