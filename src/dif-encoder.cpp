#include <dif-encoder.hpp>

using namespace diff_manchester;

Encoder::Encoder()
{
    _state = STOP;
    _output = 1;
}

/**
 * @param data Значение для передачи
 */
void Encoder::set_data(uint16_t data)
{
    _data = data;
    _bit_pos = BITS_IN_PACK;
}

/**
 * @return bool Дискретное значение выхода
 */
bool Encoder::tick()
{
    switch (_state) {
        case STOP: {
            if (_bit_pos > 0) {
                _output = 0;
                _state = SYNC;
            } else {
                _output = 1;
            }

            break;
        }
        
        case SENDING: {
            _bit_pos--;
            const bool m_s_bit = (_data >> _bit_pos) & 0x1;

            if (m_s_bit == 0)
                _output = !_output;
            
            if (_bit_pos == 0)
                _bit_pos = BITS_IN_PACK;
            
            _state = SYNC;
            
            break;
        }

        case SYNC: {
            _output = !_output;
            _state = SENDING;
            break;
        }
    }

    return _output;
}
    
