#include <stdint.h>

namespace diff_manchester
{

class Decoder
{
public:
    Decoder();
    uint16_t output() const;
    void shift_output();
    void on_edge_detecting();

private:
    void _reset_counter();
    int _counter() const;

    void _append(uint32_t bit);

    static const int CLOCK_PERIOD;
    uint32_t _output;
    bool _syncronized;
    uint32_t _received;
};

}
