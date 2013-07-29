#include <encoder.hpp>

using namespace diff_manchester;

Encoder::Encoder()
{
    _state = STOP;
    _output = 1;
}
    
/**
 * @return Дискретное значение выхода
 */
bool Encoder::output() const
{
    return _output;
}
    
/**
 * @param data Значение для передачи
 */
void Encoder::set_data(uint16_t data)
{
    _data = data;
    _bit_pos = BITS_IN_PACK;
}
    
void Encoder::tick()
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
            if (_bit_pos > 0) {
                _bit_pos--;
                const bool m_s_bit = (_data >> _bit_pos) & 0x1;

                if (m_s_bit == 0)
                    _output = !_output;

                _state = SYNC;
            } else {
                _bit_pos = BITS_IN_PACK;
                _state = SYNC;
            }

            break;
        }

        case SYNC: {
            _output = !_output;
            _state = SENDING;
            break;
        }
    }
}
    
