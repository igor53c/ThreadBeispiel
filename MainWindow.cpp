#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleThreadResults(const QString &value)
{
    ui->listWidget->addItem(value);
    ui->listWidget->scrollToBottom();
}

void MainWindow::handleFinishedThreads()
{
    numberOfThreadsRunning--;

    if(numberOfThreadsRunning <= 0)
    {
        ui->listWidget->addItem("");
        ui->listWidget->addItem("*** Alle Prozesse sind beendet ***");
        ui->listWidget->scrollToBottom();

        enableButtons(true);
    }
}

void MainWindow::startThreads()
{
    ui->listWidget->clear();

    enableButtons(false);

    numberOfThreadsRunning = 0;

    ui->listWidget->addItem("Methode zum Starten der Prozesse wird ausgeführt");

    thread1 = new MyThread("Thread A", 3, this);

    connect(thread1, &MyThread::resultReady, this, &MainWindow::handleThreadResults);
    connect(thread1, &MyThread::finished, this, &MainWindow::handleFinishedThreads);

    thread1->start();

    numberOfThreadsRunning++;

    thread2 = new MyThread("Thread B", 1, this);

    connect(thread2, &MyThread::resultReady, this, &MainWindow::handleThreadResults);
    connect(thread2, &MyThread::finished, this, &MainWindow::handleFinishedThreads);

    thread2->start();

    numberOfThreadsRunning++;

    thread3 = new MyThread("Thread C", 2, this);

    connect(thread3, &MyThread::resultReady, this, &MainWindow::handleThreadResults);
    connect(thread3, &MyThread::finished, this, &MainWindow::handleFinishedThreads);

    thread3->start();

    numberOfThreadsRunning++;

    ui->listWidget->addItem("Methode zum Starten der Prozesse wird verlassen.\n");
}

void MainWindow::enableButtons(bool bEnable)
{
    ui->btnStart->setEnabled(bEnable);
    ui->btnBeenden->setEnabled(bEnable);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(ui->btnBeenden->isEnabled())
        event->accept();
    else
        event->ignore();
}

void MainWindow::on_btnStart_clicked()
{
    startThreads();
}

void MainWindow::on_btnBeenden_clicked()
{
    close();
}

