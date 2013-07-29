#include <iostream>
#include <encoder.hpp>
#include <decoder.hpp>
#include <timer.h>
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

    for (int i = 0; i < 10; ++i) {
        const uint16_t input = rand() % numeric_limits<uint16_t>::max();
        encoder.set_data(input);
        vector<int> output_data;

        for (int i = 0; i < numeric_limits<uint16_t>::digits*2 + 2; ++i) {
            encoder.tick();
            output_data.push_back(encoder.output());
        }

        encoder.tick();

        int previos_bit = 1;

        for (int i = 0; i < 10; ++i)
            timer_tick();

        for (const int &bit: output_data) {
            timer_tick();

            if (previos_bit != bit)
                decoder.on_edge_detecting();

            previos_bit = bit;
        }

        cout << std::hex << input << " " << endl;

        for (const int &bit: output_data)
            cout << bit;

        cout << endl;
        cout << std::hex << decoder.output() << endl;

        for (int i = 0; i < numeric_limits<uint16_t>::digits; ++i)
            decoder.shift_output();
    }

    cout << "Success" << endl;

    return 0;
}

