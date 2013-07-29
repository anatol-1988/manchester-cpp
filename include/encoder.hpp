#include <stdint.h>

namespace diff_manchester
{

/// Класс кодировщика
class Encoder
{
public:
    Encoder();
    /// Задать данные для кодирования
    void set_data(uint16_t data);
    /// Получить значение очередного дискрета
    bool tick();

private:
    enum State {STOP, SENDING, SYNC};

    const static int BITS_IN_PACK = 16;

    State _state;
    bool _output;
    uint16_t _data;
    uint16_t _bit_pos;
};

}
