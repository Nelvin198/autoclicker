#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <Windows.h>

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
    void on_btnStart_clicked();
    void on_btnStop_clicked();
    void on_spinInterval_valueChanged(int arg1);

protected:
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result) override;
private:
    const int HOTKEY_ID = 1;  // Unique identifier for our hotkey
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    bool clickingActive = false;
    int clickInterval = 100;
    bool doubleClick = false;

    void performClick();
    void updateStatus();

};
#endif // MAINWINDOW_H
