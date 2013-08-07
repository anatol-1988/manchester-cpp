#include <stdint.h>

namespace manchester
{

/// Тип фронта, пришедшего на вход захвата
enum Front { RISING, FALLING };


/// Класс декодировщика
class Decoder
{
public:
    /// Конструктор
    Decoder(int half_period);
    /// Принятое значение
    uint16_t output();
    /// Количество принятых байтов
    uint32_t received() const;
    /// Вызывается при обнаружении фронта
    void on_edge_detecting(Front front, uint16_t edge_time);
    /// Очистить приемный буфер
    void clear();

private:
    void _append(uint32_t bit);

    const int _half_period;
    uint32_t _output;
    bool _syncronized;
    uint32_t _received;
};

}
