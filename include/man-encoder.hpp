#ifndef MANENCODER_HPP
#define MANENCODER_HPP

#include <stdint.h>

namespace manchester
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
    enum State {STOP, SENDING, PAUSED, SYNC};

    const static int BITS_IN_PACK = 16;
    const static int PAUSE = 3;

    State _state;
    bool _output;
    uint16_t _data;
    uint16_t _bit_send;
    int _pause_clock;
};

}

#endif // MANENCODER_HPP
