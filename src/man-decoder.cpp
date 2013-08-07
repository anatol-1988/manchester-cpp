#include <man-decoder.hpp>

using namespace manchester;

/**
 * @param threshold Пороговое значение
 */
Decoder::Decoder(int half_period) : _half_period(half_period)
{
    _output = 0x0;
    _received = 0;
    _syncronized = false;
}

/**
 * @return Полученное значение
 */
uint16_t Decoder::output()
{
    const uint32_t shift = _received > 16 ? _received - 16 : 0;
    const uint16_t out = _output >> shift;

    if (_received > 0)
        _received--;

    return out;
}

void Decoder::clear()
{
    _received = 0;
}

void Decoder::_append(uint32_t bit)
{
    _output <<= 1;

    if (bit == 1)
        _output |= 0x1;
    else
        _output &= ~0x1;

    if (_received < 32)
        _received++;
    else
        _received = 32;
}

/**
 * @return Количество принятых битов
 */
uint32_t Decoder::received() const
{
    return _received;
}

/**
 * @param edge_time Период между двумя фронтами
 */
void Decoder::on_edge_detecting(Front front, uint16_t edge_time)
{
    if (edge_time >= 3*_half_period) {
        _syncronized = true;
    } else if (edge_time >= 2*_half_period) {
        if (front == RISING)
            _append(1);
        else
            _append(0);

        _syncronized = false;
    } else {
        if (_syncronized == true) {
            if (front == RISING)
                _append(1);
            else
                _append(0);

            _syncronized = false;
        } else {
            _syncronized = true;
        }
    }
}

