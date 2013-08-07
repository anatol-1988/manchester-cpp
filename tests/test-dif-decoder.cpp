#include "test-dif-decoder.h"
#include <dif-decoder.hpp>
#include <vector>
#include <QDebug>

using namespace diff_manchester;
using namespace std;

const int THRESHOLD = 1;
const vector<uint16_t> INPUT_VECTOR = { 1,
                                        2, 2, 2, 2,
                                        1, 1, 1, 1, 1, 1, 1, 1,
                                        2, 2, 2, 2,
                                        1, 1, 1, 1, 1, 1, 1, 1};

void TestDifDecoder::output()
{

    Decoder decoder(THRESHOLD);
    QCOMPARE(decoder.output(), static_cast<uint16_t>(0x0000));

    for (auto &edge: INPUT_VECTOR)
        decoder.on_edge_detecting(edge);

    QCOMPARE(decoder.received(), static_cast<uint32_t>(16));
    QCOMPARE(decoder.output(), static_cast<uint16_t>(0xF0F0));
}

void TestDifDecoder::received()
{
    Decoder decoder(THRESHOLD);
    QCOMPARE(decoder.received(), static_cast<uint32_t>(0));

    for (auto &edge: INPUT_VECTOR)
        decoder.on_edge_detecting(edge);

    QCOMPARE(decoder.received(), static_cast<uint32_t>(16));
}

QTEST_MAIN(TestDifDecoder)
#include "test-dif-decoder.moc"
