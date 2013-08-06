#include <decoder.hpp>
#include <iostream>

using namespace diff_manchester;

/**
 * @param threshold Пороговое значение
 */
Decoder::Decoder(int threshold) : _threshold(threshold)
{
    _output = 0x0;
    _syncronized = false;
    _received = 0;
}

/**
 * @return Полученное значение
 */
uint16_t Decoder::output()
{
    if (_received >= 16) {
        const uint16_t out = _output >> (_received - 16);
        _received--;
        return out;
    } else {
        return 0x0000;
    }
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
void Decoder::on_edge_detecting(uint16_t edge_time)
{
    if (edge_time > 2*_threshold) {
        _syncronized = true;
    } else if (edge_time > _threshold) {
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

