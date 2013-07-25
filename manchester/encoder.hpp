#include <stdint.h>

namespace diff_manchester
{

class Encoder
{
public:
    Encoder();
    bool output() const;
    void set_data(uint16_t data);
    void tick();

private:
    enum State {STOP, SENDING, TRANSITION};

    State _state;
    bool _output;
    uint16_t _data;
    uint16_t _bit_pos;
};

}
