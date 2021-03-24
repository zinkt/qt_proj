#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ele = Elevator();
    ui->setupUi(this);
    //initalize
    setLED(ui->label_5,1,16);
    setLED(ui->label_6,0,16);
    setLED(ui->label_7,0,16);
    setLED(ui->label_8,0,16);
    setLED(ui->label_12,0,16);
    setLED(ui->label_13,0,16);
    setLED(ui->label_14,0,16);

    //connect
    connect(ui->pushButton, &QPushButton::pressed,[=]() {ele.externalRequest(1,2);});
    connect(ui->pushButton_2, &QPushButton::pressed,[=]() {ele.externalRequest(1,1);});
    connect(ui->pushButton_3, &QPushButton::pressed,[=]() {ele.externalRequest(2,2);});
    connect(ui->pushButton_4, &QPushButton::pressed,[=]() {ele.externalRequest(2,1);});
    connect(ui->pushButton_5, &QPushButton::pressed,[=]() {ele.externalRequest(3,2);});
    connect(ui->pushButton_6, &QPushButton::pressed,[=]() {ele.externalRequest(3,1);});
    connect(ui->pushButton_7, &QPushButton::pressed,[=]() {ele.externalRequest(4,2);});
    connect(ui->pushButton_8, &QPushButton::pressed,[=]() {ele.externalRequest(4,1);});
    connect(ui->pushButton_9, &QPushButton::pressed,[=]() {ele.internalRequest(1);});
    connect(ui->pushButton_10, &QPushButton::pressed,[=]() {ele.internalRequest(2);});
    connect(ui->pushButton_11, &QPushButton::pressed,[=]() {ele.internalRequest(3);});
    connect(ui->pushButton_12, &QPushButton::pressed,[=]() {ele.internalRequest(4);});

    connect(ui->Button_21, &QPushButton::pressed,[=]() {ele.internalRequest(5);});
    connect(ui->Button_19, &QPushButton::pressed,[=]() {ele.internalRequest(6);});
    connect(ui->Button_20, &QPushButton::pressed,[=]() {ele.internalRequest(7);});
    connect(ui->pushButton_13, &QPushButton::pressed,[=]() {ele.externalRequest(5,2);});
    connect(ui->pushButton_14, &QPushButton::pressed,[=]() {ele.externalRequest(5,1);});
    connect(ui->pushButton_15, &QPushButton::pressed,[=]() {ele.externalRequest(6,2);});
    connect(ui->pushButton_16, &QPushButton::pressed,[=]() {ele.externalRequest(6,1);});
    connect(ui->pushButton_17, &QPushButton::pressed,[=]() {ele.externalRequest(7,2);});
    connect(ui->pushButton_18, &QPushButton::pressed,[=]() {ele.externalRequest(7,1);});


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
    timer->start(1500);

}
void MainWindow::onTimeOut()
{
    if(ele.get_pause_stat())
    {
        //setColor

        ele.go_on();
        switch (ele.getFloor()) {
        case 1:
            setLED(ui->label_5,2,16);
            setLED(ui->label_6,0,16);
            setLED(ui->label_7,0,16);
            setLED(ui->label_8,0,16);
            setLED(ui->label_12,0,16);
            setLED(ui->label_13,0,16);
            setLED(ui->label_14,0,16);
            break;
        case 2:
            setLED(ui->label_5,0,16);
            setLED(ui->label_6,2,16);
            setLED(ui->label_7,0,16);
            setLED(ui->label_8,0,16);
            setLED(ui->label_12,0,16);
            setLED(ui->label_13,0,16);
            setLED(ui->label_14,0,16);
            break;
        case 3:
            setLED(ui->label_5,0,16);
            setLED(ui->label_6,0,16);
            setLED(ui->label_7,2,16);
            setLED(ui->label_8,0,16);
            setLED(ui->label_12,0,16);
            setLED(ui->label_13,0,16);
            setLED(ui->label_14,0,16);
            break;
        case 4:
            setLED(ui->label_5,0,16);
            setLED(ui->label_6,0,16);
            setLED(ui->label_7,0,16);
            setLED(ui->label_8,2,16);
            setLED(ui->label_12,0,16);
            setLED(ui->label_13,0,16);
            setLED(ui->label_14,0,16);
            break;
        case 5:
            setLED(ui->label_5,0,16);
            setLED(ui->label_6,0,16);
            setLED(ui->label_7,0,16);
            setLED(ui->label_8,0,16);
            setLED(ui->label_12,2,16);
            setLED(ui->label_13,0,16);
            setLED(ui->label_14,0,16);
            break;
        case 6:
            setLED(ui->label_5,0,16);
            setLED(ui->label_6,0,16);
            setLED(ui->label_7,0,16);
            setLED(ui->label_8,0,16);
            setLED(ui->label_12,0,16);
            setLED(ui->label_13,2,16);
            setLED(ui->label_14,0,16);
            break;
        case 7:
            setLED(ui->label_5,0,16);
            setLED(ui->label_6,0,16);
            setLED(ui->label_7,0,16);
            setLED(ui->label_8,0,16);
            setLED(ui->label_12,0,16);
            setLED(ui->label_13,0,16);
            setLED(ui->label_14,2,16);
            break;
        }
    }
    else
    {
        switch (ele.getFloor()) {
        case 1:
            setLED(ui->label_5,1,16);
            setLED(ui->label_6,0,16);
            setLED(ui->label_7,0,16);
            setLED(ui->label_8,0,16);
            setLED(ui->label_12,0,16);
            setLED(ui->label_13,0,16);
            setLED(ui->label_14,0,16);
            break;
        case 2:
            setLED(ui->label_5,0,16);
            setLED(ui->label_6,1,16);
            setLED(ui->label_7,0,16);
            setLED(ui->label_8,0,16);
            setLED(ui->label_12,0,16);
            setLED(ui->label_13,0,16);
            setLED(ui->label_14,0,16);
            break;
        case 3:
            setLED(ui->label_5,0,16);
            setLED(ui->label_6,0,16);
            setLED(ui->label_7,1,16);
            setLED(ui->label_8,0,16);
            setLED(ui->label_12,0,16);
            setLED(ui->label_13,0,16);
            setLED(ui->label_14,0,16);
            break;
        case 4:
            setLED(ui->label_5,0,16);
            setLED(ui->label_6,0,16);
            setLED(ui->label_7,0,16);
            setLED(ui->label_8,1,16);
            setLED(ui->label_12,0,16);
            setLED(ui->label_13,0,16);
            setLED(ui->label_14,0,16);
            break;
        case 5:
            setLED(ui->label_5,0,16);
            setLED(ui->label_6,0,16);
            setLED(ui->label_7,0,16);
            setLED(ui->label_8,0,16);
            setLED(ui->label_12,1,16);
            setLED(ui->label_13,0,16);
            setLED(ui->label_14,0,16);
            break;
        case 6:
            setLED(ui->label_5,0,16);
            setLED(ui->label_6,0,16);
            setLED(ui->label_7,0,16);
            setLED(ui->label_8,0,16);
            setLED(ui->label_12,0,16);
            setLED(ui->label_13,1,16);
            setLED(ui->label_14,0,16);
            break;
        case 7:
            setLED(ui->label_5,0,16);
            setLED(ui->label_6,0,16);
            setLED(ui->label_7,0,16);
            setLED(ui->label_8,0,16);
            setLED(ui->label_12,0,16);
            setLED(ui->label_13,0,16);
            setLED(ui->label_14,1,16);
            break;
        }
            ele.runStep();
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLED(QLabel* label, int color, int size)
{
    label->setText("");

    //size
    QString min_width = QString("min-width: %1px;").arg(size);
    QString min_height = QString("min-height: %1px;").arg(size);
    QString max_width = QString("max-width: %1px;").arg(size);
    QString max_height = QString("max-height: %1px;").arg(size);

    //border
    QString border_radius = QString("border-radius: %1px;").arg(size/2);
    QString border = QString("border:1px solid black;");
    //bg
    QString background = "background-color:";
        switch (color) {
        case 0:
            // 白色
            background += "rgb(255,255,255)";
            break;
        case 1:
            // 绿色
            background += "rgb(0,255,0)";
            break;
        case 2:
            // 黄色
            background += "rgb(255,255,0)";
            break;
        default:
            break;
        }
    const QString sheetStyle = min_width+min_height+max_width+max_height +border_radius+border+background;
    label->setStyleSheet(sheetStyle);
}
