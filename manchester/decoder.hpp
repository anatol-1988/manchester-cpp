#include <stdint.h>

namespace diff_manchester
{

/// Класс декодировщика
class Decoder
{
public:
    Decoder();
    /// Принятое значение
    uint16_t output() const;
    /// Сдвинуть принятое значение
    void shift_output();
    /// Вызывается при обнаружении фронта
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
