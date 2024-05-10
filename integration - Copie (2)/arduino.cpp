#include "arduino.h"


arduino::arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *arduino::getserial()
{
   return serial;
}
int arduino::connect_arduino()
{   // recherche du port sur lequel la carte arduino identifée par  arduino_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
           if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
               if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()
                       == arduino_uno_producy_id) {
                   arduino_is_available = true;
                   arduino_port_name=serial_port_info.portName();
               } } }
        qDebug() << "arduino_port_name is :" << arduino_port_name;
        if(arduino_is_available){ // configuration de la communication ( débit...)
            serial->setPortName(arduino_port_name);
            if(serial->open(QSerialPort::ReadWrite)){
                serial->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
                serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
                serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
                serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0;
            }
            return 1;
        }
        return -1;
}

int arduino::close_arduino()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;


}


 QByteArray arduino::read_from_arduino()
{
    if(serial->isReadable()){
         data=serial->readAll(); //récupérer les données reçues

         return data;
    }
}


int arduino::write_to_arduino( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}


int arduino::cherchercode(int id)
{

          QSqlDatabase bd = QSqlDatabase::database();
          int cin;

              QSqlQuery query;
              query.prepare("SELECT cin FROM employes WHERE cin =:id");
              query.bindValue(0,id);

              query.exec();
              if (query.next())
              {

                  cin=query.value(0).toInt();

                   return cin;

              }
              else {
                  return 0;
              }

  }
QByteArray arduino::getdata()
{

  return data;
}
QString arduino::chercherid(QString id){

          QSqlDatabase bd = QSqlDatabase::database();
      QString poids;

              QSqlQuery query;
              query.prepare("SELECT poids FROM bagages WHERE id_bagages =:id");
       query.bindValue(0,id);

              query.exec();
              if (query.next())
              {

                  poids=query.value(0).toString();

                   return poids;
              }
              else {
                  return "";
              }

  }



