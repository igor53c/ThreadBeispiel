#pragma once

#include <QMainWindow>
#include <QCloseEvent>

#include "MyThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleThreadResults(const QString&);
    void handleFinishedThreads();

    void on_btnStart_clicked();

    void on_btnBeenden_clicked();

private:
    Ui::MainWindow *ui;

    int numberOfThreadsRunning;

    MyThread* thread1;
    MyThread* thread2;
    MyThread* thread3;

    void startThreads();
    void enableButtons(bool bEnable);

    void closeEvent(QCloseEvent* event) override;
};
