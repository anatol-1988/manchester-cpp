#include <iostream>
#include <manchester/encoder.hpp>
#include <manchester/decoder.hpp>
#include <manchester/timer.h>
#include <bitset>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;
using namespace diff_manchester;

int main()
{
    srand(std::time(0));

    Encoder encoder;
    Decoder decoder;

    for (int i = 0; i < 10000; ++i) {
        const uint16_t input = rand() % numeric_limits<uint16_t>::max();
        encoder.set_data(input);
        vector<int> output_data;

        for (int i = 0; i < 16*2; ++i) {
            encoder.tick();
            output_data.push_back(encoder.output());
        }

        encoder.tick();

        int previos_bit = 1;

        for (const int &bit: output_data) {
            timer_tick();

            if (previos_bit != bit)
                decoder.on_edge_detecting();

            previos_bit = bit;
        }

        if (input != decoder.output())
            cout << std::hex << input << " " << output_data[0] <<
                  output_data[1] << " " << std::hex << decoder.output() << endl;

        decoder.clear();
    }

    return 0;
}

