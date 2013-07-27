#include <decoder.hpp>
#include <iostream>

using namespace diff_manchester;

Decoder::Decoder()
{
    _output = 0x0;
    _syncronized = false;
    _received = 0;
}
    
uint16_t Decoder::output() const
{
    return _output;
}

void Decoder::shift_output()
{
    _output <<= 1;
    _received--;
}

void Decoder::_append(uint32_t bit)
{
    _output <<= 1;

    if (bit == 1)
        _output |= 0x1;
    else
        _output &= ~0x1;

    _received++;
}

void Decoder::on_edge_detecting()
{
    if (_counter() >= CLOCK_PERIOD*2) {
        std::cout << "SYNCRONIZED" << std::endl;
        _syncronized = true;
    } else if (_counter() >= CLOCK_PERIOD) {
        if (_syncronized == true)
            _append(1);
    } else {
        if (_syncronized == false) {
            _syncronized = true;
        } else {
            _append(0);
            _syncronized = false;
        }
    }

    _reset_counter();
}

void Decoder::clear()
{
    _output = 0x0;
    _received = 0;
    _syncronized = false;
}
