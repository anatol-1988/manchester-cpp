#include <man-encoder.hpp>

using namespace manchester;

Encoder::Encoder()
{
    _output = true;
    _state = STOP;
    _pause_clock = 0;
}

/**
 * @param data Значение для передачи
 */
void Encoder::set_data(uint16_t data)
{
    _data = data;
    _state = SENDING;
    _bit_send = BITS_IN_PACK;
}

/**
 * @return bool Дискретное значение выхода
 */
bool Encoder::tick()
{
    switch (_state) {
    case STOP: {
        _output = true;
        _bit_send = 0;
        break;
    } case SENDING: {
        if (_bit_send > 0) {
            const bool m_s_bit = (_data >> (_bit_send - 1)) & 0x1;

            if (m_s_bit == 1)
                _output = 0;
            else
                _output = 1;

            _state = SYNC;
            _bit_send -= 1;
        } else
            _state = PAUSED;

        break;
    } case SYNC: {
        _output = !_output;

        if (_bit_send == 0) {
            _state = PAUSED;
            _pause_clock = PAUSE;
        } else {
            _state = SENDING;
        }

        break;
    } case PAUSED: {
        _output = true;
        _pause_clock -= 1;

        if (_pause_clock == 0) {
            _state = SENDING;
            _bit_send = BITS_IN_PACK;
        }

        break;
    }
    }

    return _output;
}
