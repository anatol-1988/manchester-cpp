#include <decoder.hpp>

using namespace diff_manchester;

int counter = 0;

void timer_tick()
{
    counter++;
}


const int Decoder::CLOCK_PERIOD = 2;

void Decoder::_reset_counter()
{
    counter = 0;
}

int Decoder::_counter() const
{
    return counter;
}
