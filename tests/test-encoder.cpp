#include <encoder.hpp>
#include <cstdlib>
#include <test-encoder.h>

using namespace std;
using namespace diff_manchester;

void TestEncoder::tick()
{
    const uint16_t input_data = 0xF0F0;
    Encoder encoder;
    encoder.set_data(input_data);
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), false);    // 0
    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 0
    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 0
    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 0
    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), false);    // 0
    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 0
    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 0
    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 0
    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 0
}

QTEST_MAIN(TestEncoder)
#include "test-encoder.moc"
