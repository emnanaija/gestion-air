#include "vols.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
vols::vols()
{
     numvol=" ";
     numpiste=0;
     avion=" ";
     pilote=" ";
     destination=" ";
     datee=" ";
     description=" ";
}

/*
QString numvol;
int numpiste;
QString avion;
QString pilote;
QString destination;
QString date;
QString description;
*/

vols::vols(QString numvol,int numpiste,QString avion,QString pilote,QString destination,QString datee,QString description)
{

  this->numvol=numvol;
  this->numpiste=numpiste;
  this->avion=avion;
  this->pilote=pilote;
  this->destination=destination;
  this->datee=datee;
  this->description=description;

}

QString vols:: getnumvol(){return numvol;}
int vols::getnumpiste(){ return numpiste; }
QString vols::getavion(){ return avion;}
QString vols:: getpilote() {return pilote;}
QString vols::getdestination() {return destination;}
QString vols:: getdate() {return datee ;}
QString vols::getdescription() {return description;}



void vols::setnumvol(QString numvol){this->numvol=numvol ;};
void vols:: setnumpiste(int numpiste ){this->numpiste=numpiste;};
void vols::setavion(QString avion){this->avion=avion;};
void vols::setpilote(QString pilote){this->pilote=pilote;};
void vols::setdestinantion(QString destination){this->destination=destination ;};
void vols::setdate(QString date){this->datee=date;};
void vols::setdescription(QString description){this->description=description;};

bool vols:: ajouter()
{

QSqlQuery query;
QString numpiste_string =QString::number(numpiste);
     query.prepare("INSERT INTO VOLL (numvol,numpiste,avion,pilote,destination,datee,description) "
                   "VALUES (:numvol, :numpiste, :avion ,:pilote ,:destination,:datee,:description)");
     query.bindValue(0,numvol);
     query.bindValue(1, numpiste_string);
     query.bindValue(2,avion);
     query.bindValue(3,pilote);
     query.bindValue(4,destination);
     query.bindValue(5,datee);
     query.bindValue(6,description);

return query.exec();
}

bool vols:: supprimer (QString numvol)
{

    QSqlQuery query;

         query.prepare("Delete from VOLL where numvol=:numvol");
         query.bindValue(0,numvol);


    return query.exec();


}



QSqlQueryModel *vols :: afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM VOLL");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numvol"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("numpiste"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("avion"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("pilote"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("destination"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datee"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("description"));



return model;
}






