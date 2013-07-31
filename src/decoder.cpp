#include <decoder.hpp>

using namespace diff_manchester;

Decoder::Decoder()
{
    _output = 0x0;
    _syncronized = false;
    _received = 0;
}

/**
 * @return Полученное значение
 */
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

/**
 * @param edge_time Период между двумя фронтами
 */
void Decoder::on_edge_detecting(uint16_t edge_time)
{
    if (edge_time >= 2*THRESHOLD) {
        _syncronized = true;
    } else  if (edge_time >= THRESHOLD) {
        _syncronized = true;
        _append(1);
    } else {
        if (_syncronized == false) {
            _syncronized = true;
        } else {
            _append(0);
            _syncronized = false;
        }
    }
}

