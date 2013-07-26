#include <iostream>
#include <manchester/encoder.hpp>
#include <manchester/decoder.hpp>
#include <manchester/timer.h>
#include <bitset>
#include <vector>

using namespace std;
using namespace diff_manchester;

int main()
{
    Encoder encoder;
    const uint16_t input_data = 0b10100111001;
    encoder.set_data(input_data);
    vector<int> output_data;

    cout << bitset<16>(input_data) << endl;

    for (int i = 0; i < 16*2; ++i) {
        encoder.tick();
        output_data.push_back(encoder.output());
    }

    for (const int &bit: output_data)
        cout << bit;

    cout << endl;

    Decoder decoder;
    int previos_bit = 1;

    for (const int &bit: output_data) {
        timer_tick();

        if (previos_bit != bit)
            decoder.on_edge_detecting();

        previos_bit = bit;
    }

    cout << bitset<16>(decoder.output()) << endl;

    return 0;
}

