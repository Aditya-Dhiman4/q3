#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "libtempvolts.h"


/* Returns a random voltage with small noisy fluctuations 
** using the random number generator
*/
float get_voltage() {
    return 0.7f + (((float) rand() / (float)RAND_MAX) * 0.1f);
}

/* Reads the temperature by getting the voltage
** and converting it into temperature 
** based on the -40 to 150 range
**
** Returns the temperature in degrees C
*/
float io_read_temperature() {
    return (get_voltage() - 0.5f) * 100.0f;
}

/* Helper method that converts a voltage value into a temperature
** based on the -40 to 150 range
** purely for optimization purposes
**
** Param voltage The voltage to convert
**
** Returns the temperature in degrees C
*/
float convert_voltage_to_temp(float voltage) {
    return (voltage - 0.5f) * 100.0f;
}

/* Takes the average of NUM_VOLTAGE_READINGS voltage readings
** and turns it into a temperature based on the -40 to 150 range
**
** Returns the temperature in degrees C
*/
float avg_temperature() {
    float avg = 0.0f;

    for (int i = 0; i < NUM_VOLTAGE_READINGS; i++) {
        avg += get_voltage();
    }

    return convert_voltage_to_temp(avg / NUM_VOLTAGE_READINGS);
}

int main(void) {
    // Seed for random number generator
    srand(time(NULL));

    printf("%f\n", avg_temperature());    
}