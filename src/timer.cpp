#include <decoder.hpp>
#include <timer.h>

int _counter = 0;

void timer_tick()
{
    _counter++;
}

void reset_counter()
{
    _counter = 0;
}

int counter()
{
    return _counter;
}
