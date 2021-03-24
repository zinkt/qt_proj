#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "elevator.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setLED(QLabel* label,int color, int size);

    ~MainWindow();
private slots:
    void onTimeOut();

private:
    Ui::MainWindow *ui;
    Elevator ele;

};
#endif // MAINWINDOW_H
