#ifndef TESTMANDECODER_H
#define TESTMANDECODER_H

#include <QtTest/QtTest>

class TestManDecoder : public QObject
{
    Q_OBJECT
    
private slots:
    void output();
    void received();
};

#endif // TESTMANDECODER_H
