#include <stdint.h>

namespace diff_manchester
{

/// Класс декодировщика
class Decoder
{
public:
    Decoder();
    /// Принятое значение
    uint16_t output();
    uint32_t received() const;
    /// Сдвинуть принятое значение
    void shift_output();
    /// Вызывается при обнаружении фронта
    void on_edge_detecting(uint16_t edge_time);

private:
    void _reset_counter();
    int _counter() const;

    void _append(uint32_t bit);

    static const int THRESHOLD;
    uint32_t _output;
    bool _syncronized;
    uint32_t _received;
};

}
