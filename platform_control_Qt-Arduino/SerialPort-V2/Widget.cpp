#include "Widget.h"
#include <QWidget>
#include "ui_Widget.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;


    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier()){
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }
    }


    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                }
            }
        }
    }

    if(arduino_is_available){
        // open and configure the serialport
        ui->connectionTextEdit->setText("connected");
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }else{
        // give error message if not available
        QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
        ui->connectionTextEdit->setText("No connection");
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_forwardPushButton_pressed()
{
    if(arduino->isWritable()){
        arduino->write("a");
        arduino->waitForBytesWritten();
    }else{
        qDebug() << "Couldn't write a to serial!";
    }
}

void Widget::on_forwardPushButton_released()
{
    if(arduino->isWritable()){
        arduino->write("z");
    }else{
        qDebug() << "Couldn't write z to serial!";
    }
}

void Widget::on_backPushButton_pressed()
{
    if(arduino->isWritable()){
        arduino->write("b");
    }else{
        qDebug() << "Couldn't write b to serial!";
    }
}

void Widget::on_backPushButton_released()
{
    if(arduino->isWritable()){
        arduino->write("z");
    }else{
        qDebug() << "Couldn't write z to serial!";
    }
}

void Widget::on_leftPushButton_pressed()
{
    if(arduino->isWritable()){
        arduino->write("c");
    }else{
        qDebug() << "Couldn't write c to serial!";
    }
}

void Widget::on_leftPushButton_released()
{
    if(arduino->isWritable()){
        arduino->write("z");
    }else{
        qDebug() << "Couldn't write z to serial!";
    }
}

void Widget::on_rightPushButton_pressed()
{
    if(arduino->isWritable()){
        arduino->write("d");
    }else{
        qDebug() << "Couldn't write d to serial!";
    }
}

void Widget::on_rightPushButton_released()
{
    if(arduino->isWritable()){
        arduino->write("z");
    }else{
        qDebug() << "Couldn't write z to serial!";
    }
}
void Widget::on_spinLeftPushButton_pressed()
{
    if(arduino->isWritable()){
        arduino->write("e");
    }else{
        qDebug() << "Couldn't write e to serial!";
    }
}

void Widget::on_spinLeftPushButton_released()
{
    if(arduino->isWritable()){
        arduino->write("z");
    }else{
        qDebug() << "Couldn't write z to serial!";
    }
}

void Widget::on_spinRightPushButton_pressed()
{
    if(arduino->isWritable()){
        arduino->write("f");
    }else{
        qDebug() << "Couldn't write f to serial!";
    }
}

void Widget::on_spinRightPushButton_released()
{
    if(arduino->isWritable()){
        arduino->write("z");
    }else{
        qDebug() << "Couldn't write z to serial!";
    }
}
