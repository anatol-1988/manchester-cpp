#include <man-encoder.hpp>
#include <cstdlib>
#include <test-man-encoder.h>

using namespace std;
using namespace manchester;

void TestManEncoder::tick()
{
    const uint16_t input_data = 0xF0F0;
    Encoder encoder;
    encoder.set_data(input_data);
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1

    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 0
    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 0
    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 0
    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 0

    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1

    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 0
    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 0
    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 0
    QCOMPARE(encoder.tick(), true);     // 0
    QCOMPARE(encoder.tick(), false);    // 0

    QCOMPARE(encoder.tick(), true);     // PAUSE
    QCOMPARE(encoder.tick(), true);     // PAUSE
    QCOMPARE(encoder.tick(), true);     // PAUSE

    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1
    QCOMPARE(encoder.tick(), false);    // 1
    QCOMPARE(encoder.tick(), true);     // 1
}

QTEST_MAIN(TestManEncoder)
#include "test-man-encoder.moc"
