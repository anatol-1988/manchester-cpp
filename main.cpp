#include <iostream>
#include <manchester/encoder.hpp>
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

    return 0;
}

