#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class QSerialPort;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:

    void on_forwardPushButton_pressed();

    void on_forwardPushButton_released();

    void on_backPushButton_pressed();

    void on_backPushButton_released();

    void on_leftPushButton_pressed();

    void on_leftPushButton_released();

    void on_rightPushButton_pressed();

    void on_rightPushButton_released();

    void on_spinLeftPushButton_pressed();

    void on_spinLeftPushButton_released();

    void on_spinRightPushButton_pressed();

    void on_spinRightPushButton_released();

private:
    Ui::Widget *ui;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;
};

#endif // WIDGET_H
