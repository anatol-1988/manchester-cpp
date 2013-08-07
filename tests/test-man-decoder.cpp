#include "test-man-decoder.h"
#include <man-decoder.hpp>
#include <vector>
#include <QDebug>

using namespace manchester;
using namespace std;

struct Edge {
    Front f;
    int length;
};

const int HALF_PERIOD = 1;
const vector<Edge> INPUT_VECTOR = { {FALLING, 3}, {RISING, 1},  {FALLING, 2},
                                    {RISING, 2},  {FALLING, 2}, {RISING, 1},
                                    {FALLING, 1}, {RISING, 2},  {FALLING, 1},
                                    {RISING, 1},  {FALLING, 1}, {RISING, 1},
                                    {FALLING, 2}, {RISING, 1},  {FALLING, 1},
                                    {RISING, 2},  {FALLING, 2}, {RISING, 2},
                                    {FALLING, 2}, {RISING, 2},  {FALLING, 2},
                                    {RISING, 2}};

void TestManDecoder::output()
{
    Decoder decoder(HALF_PERIOD);

    for (auto &edge: INPUT_VECTOR)
        decoder.on_edge_detecting(edge.f, edge.length);

    QCOMPARE(decoder.received(), static_cast<uint32_t>(17));
    QCOMPARE(decoder.output(), static_cast<uint16_t>(0b1010011100101010));
    QCOMPARE(decoder.output(), static_cast<uint16_t>(0b0100111001010101));
}

void TestManDecoder::received()
{
    Decoder decoder(HALF_PERIOD);
    QCOMPARE(decoder.received(), static_cast<uint32_t>(0));

    for (auto &edge: INPUT_VECTOR)
        decoder.on_edge_detecting(edge.f, edge.length);

    QCOMPARE(decoder.received(), static_cast<uint32_t>(17));
}

QTEST_MAIN(TestManDecoder)
#include "test-man-decoder.moc"
