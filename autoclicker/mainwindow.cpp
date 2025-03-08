#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize timer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::performClick);

    // Set initial state
    ui->btnStop->setEnabled(false);
    ui->spinInterval->setValue(100);
    updateStatus();

    // Register F6 hotkey
    RegisterHotKey(reinterpret_cast<HWND>(this->winId()),
                   HOTKEY_ID,
                   0,  // No modifiers
                   VK_F6);
}

MainWindow::~MainWindow()
{
    // Unregister hotkey
    UnregisterHotKey(reinterpret_cast<HWND>(this->winId()), HOTKEY_ID);
    delete ui;
}
bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result)
{
    MSG* msg = reinterpret_cast<MSG*>(message);
    if(msg->message == WM_HOTKEY)
    {
        if(msg->wParam == HOTKEY_ID)
        {
            // Toggle start/stop
            if(clickingActive) on_btnStop_clicked();
            else on_btnStart_clicked();
            return true;
        }
    }
    return QMainWindow::nativeEvent(eventType, message, result);
}
void MainWindow::on_btnStart_clicked()
{
    clickingActive = true;
    timer->start(clickInterval);
    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);
    ui->spinInterval->setEnabled(false);
    updateStatus();
}

void MainWindow::on_btnStop_clicked()
{
    clickingActive = false;
    timer->stop();
    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(false);
    ui->spinInterval->setEnabled(true);
    updateStatus();
}

void MainWindow::on_spinInterval_valueChanged(int arg1)
{
    clickInterval = arg1;
    if(timer->isActive()) {
        timer->start(clickInterval);
    }
}

void MainWindow::performClick()
{
    INPUT inputs[4] = {};
    ZeroMemory(inputs, sizeof(inputs));

    // Left down
    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    // Left up
    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    if(ui->chkDoubleClick->isChecked()) {
        // Second click
        inputs[2].type = INPUT_MOUSE;
        inputs[2].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

        inputs[3].type = INPUT_MOUSE;
        inputs[3].mi.dwFlags = MOUSEEVENTF_LEFTUP;

        SendInput(4, inputs, sizeof(INPUT));
    } else {
        SendInput(2, inputs, sizeof(INPUT));
    }
}


void MainWindow::updateStatus()
{
    ui->labelStatus->setText(clickingActive ?
                                 "Status: Running (" + QString::number(clickInterval) + "ms)" :
                                 "Status: Stopped");
}
