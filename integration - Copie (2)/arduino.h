#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>
class arduino
{
public:
    arduino();
    QByteArray getdata();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort * getserial();
    QString getarduino_port_name();
int cherchercode(int id);
QString chercherid(QString id);
private:
    QSerialPort *serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
};

#endif // ARDUINO_H
