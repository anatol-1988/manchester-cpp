#include <stdint.h>

namespace manchester
{

class Decoder
{
public:
    Decoder();
    uint16_t output() const;
    void on_edge_detecting(bool edge);
};

}
