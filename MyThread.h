#pragma once

#include <QObject>
#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(QString name, int timeOut = 0, QObject* parent = nullptr);

    void run() override;

    QString getName() const;

signals:
    void resultReady(const QString&);

private:
    QString name;
    int timeOut;
};

