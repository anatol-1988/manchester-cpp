#ifndef TESTENCODER_H
#define TESTENCODER_H

#include <QtTest/QtTest>

class TestEncoder: public QObject
{
    Q_OBJECT

private slots:
    void tick();
};

#endif // TESTENCODER_H
