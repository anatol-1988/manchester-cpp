#include <stdint.h>

namespace diff_manchester
{

/// Класс декодировщика
class Decoder
{
public:
    /// Конструктор
    Decoder(int threshold);
    /// Принятое значение
    uint16_t output();
    /// Количество принятых байтов
    uint32_t received() const;
    /// Вызывается при обнаружении фронта
    void on_edge_detecting(uint16_t edge_time);
    /// Очистить приемный буфер
    void clear();

private:
    void _append(uint32_t bit);

    const int _threshold;
    uint32_t _output;
    bool _syncronized;
    uint32_t _received;
};

}
