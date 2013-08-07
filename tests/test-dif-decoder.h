#ifndef TESTDIFDECODER_H
#define TESTDIFDECODER_H

#include <QtTest/QtTest>

class TestDifDecoder : public QObject
{
    Q_OBJECT
    
private slots:
    void output();
    void received();
};

#endif // TESTDIFDECODER_H
