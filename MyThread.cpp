#include "MyThread.h"

MyThread::MyThread(QString name, int timeOut, QObject* parent) : QThread(parent)
{
    this->name = name;

    this->timeOut = timeOut;
}

void MyThread::run()
{
    emit resultReady(getName() + " wird ausgeführt.");

    for(int i = 1; i <= 10; i++)
    {
        emit resultReady(getName() + ": " + QString::number(i));

        if(timeOut > 0)
            QThread::sleep(timeOut);
    }

    emit resultReady(getName() + " wird beendet.");
}

QString MyThread::getName() const
{
    return name;
}
