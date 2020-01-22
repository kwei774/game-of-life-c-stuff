#include "life.h"
#include <stdlib.h>
#include "Arduino.h"
#include "ledmatrix.h"

void life_setup(void *matrix)
{
    int seed = analogRead(A7);
    if (seed < 0)
    {
        seed = -1 * seed;
    }
    srand(seed);

    led_begin(matrix);

    bool v;
    uint16_t livecolor = led_color(127, 127, 127);
    uint16_t deadcolor = led_color(0, 0, 0);

}

void life_loop(void *matrix)
{
}