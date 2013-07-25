#include <encoder.hpp>
#include <iostream>

using namespace diff_manchester;

Encoder::Encoder()
{
    _bit_pos = 15;
    _data = 0x0;
    _state = STOP;
    _output = 1;
}
    
bool Encoder::output() const
{
    return _output;
}
    
void Encoder::set_data(uint16_t data)
{
    _data = data;
    _state = SENDING;
}
    
void Encoder::tick()
{
    switch (_state) {
        case STOP: _output = true; _bit_pos = 15; break;
        
        case SENDING: {
            const bool m_s_bit = (_data >> _bit_pos) & 0x1;

            if (m_s_bit == 0)
                _output = !_output;

            _bit_pos -= 1;
            _state = TRANSITION;
            break;
        }

        case TRANSITION: {
            _output = !_output;
            _state = _bit_pos > 0 ? SENDING : STOP;
            break;
        }
    }
}
    
