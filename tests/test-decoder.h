#ifndef TESTDECODER_H
#define TESTDECODER_H

#include <QtTest/QtTest>

class TestDecoder : public QObject
{
    Q_OBJECT
    
private slots:
    void output();
    void received();
};

#endif // TESTDECODER_H
