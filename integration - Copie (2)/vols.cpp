#include "vols.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include<QTextDocument>
#include<QtCharts>
#include<QPieSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSlice>
#include <QChartView>
#include<QtCharts>
#include <QChart>
#include <QGraphicsView>


vols::vols()
{
     numvol=" ";
     numpiste=0;
     avion=" ";
     pilote=" ";
     destination=" ";
     datee=" ";
     description=" ";
     duree=0;
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

vols::vols(QString numvol,int numpiste,QString avion,QString pilote,QString destination,QString datee,QString description,int duree)
{

  this->numvol=numvol;
  this->numpiste=numpiste;
  this->avion=avion;
  this->pilote=pilote;
  this->destination=destination;
  this->datee=datee;
  this->description=description;
   this->duree=duree;

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
     query.prepare("INSERT INTO VOLL (numvol,numpiste,avion,pilote,destination,datee,description,duree) "
                   "VALUES (:numvol, :numpiste, :avion ,:pilote ,:destination,:datee,:description,:duree)");
     query.bindValue(0,numvol);
     query.bindValue(1, numpiste_string);
     query.bindValue(2,avion);
     query.bindValue(3,pilote);
     query.bindValue(4,destination);
     query.bindValue(5,datee);
     query.bindValue(6,description);
      query.bindValue(7,duree);

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
 model->setHeaderData(7, Qt::Horizontal, QObject::tr("duree"));


return model;
}


bool vols:: modifier()
{


    QSqlQuery query;
    QString numpiste_string =QString::number(numpiste);
     QString duree_string =QString::number(duree);
         query.prepare("UPDATE  VOLL SET numvol='"+numvol+"' ,numpiste='"+ numpiste_string+"', avion='"+avion+"', destination='"+destination+"',datee='"+datee+"',description='"+ description+"',duree='"+duree_string+"' where numvol='"+numvol+"'");

         query.bindValue(0,numvol);
         query.bindValue(1, numpiste_string);
         query.bindValue(2,avion);
         query.bindValue(3,pilote);
         query.bindValue(4,destination);
         query.bindValue(5,datee);
         query.bindValue(6,description);
         query.bindValue(7,duree);


 return query.exec();
}





QSqlQueryModel *vols::Rechercher(QString value )
{
     QSqlQueryModel *modal=new QSqlQueryModel();
     modal->setQuery("select * from voll where numvol like '%"+value+"%' or numpiste like '%"+value+"%' or avion like '%"+value+"%'or destination like '%"+value+"%'or description like '%"+value+"%'or numvol like '%"+value+"%' ");
     return modal;
}






QSqlQueryModel *vols::Trier_em(QString croissance,QString critere)
{
    QSqlQueryModel *modal=new QSqlQueryModel();

    if(critere == "NUM VOL" && croissance == "ASC")
        modal->setQuery("select * from VOLL order by numvol ASC ");
    else if(critere == "NUMVOL" && croissance == "DESC")
        modal->setQuery("select * from VOLL order by numvol DESC ");

    else if(critere == "NUMPISTE" && croissance == "ASC")
        modal->setQuery("select * from VOLL order by numpiste ASC ");
    else if(critere == "NUMPISTE" && croissance == "DESC")
        modal->setQuery("select * from VOLL order by numpiste DESC ");

    else if(critere == "DATE" && croissance == "ASC")
        modal->setQuery("select * from VOLL order by  ASC ");
    else if(critere == "DATE" && croissance == "DESC")
        modal->setQuery("select * from VOLL order by numpiste DESC ");

    else if(critere == "DESTINATION" && croissance == "ASC")
        modal->setQuery("select * from VOLL order by destination ASC ");
    else if(critere == "DESTINATION" && croissance == "DESC")
        modal->setQuery("select * from VOLL order by destination DESC ");


    return  modal;
}





QChartView *vols:: stat_type()
{
int v1=0;

int v2=0;

int v3=0;



QSqlQuery query;

query.prepare("select * from  VOLL where DESTINATION='paris'");

query.exec();



while(query.next())

    v1++;


/*
query.prepare("select * from VOLL where DESTINATION='rome'");

query.exec();



while(query.next())

    v2++;



query.prepare("select * from VOLL where DESTINATION='japon'");

query.exec();



while(query.next())

    v3++;

*/

qDebug() << v1<< v2 << v3;



QPieSeries *series = new QPieSeries();

    series->append("PARIS", v1);

    series->append("ROME", v2);

    series->append("JAPON", v3);



    QPieSlice *slice = series->slices().at(0);

    slice->setExploded(true);

    slice->setColor("#092cdb");

   QPieSlice *slice2 = series->slices().at(1);

    slice2->setColor("#4360f0");

    QPieSlice *slice3 = series->slices().at(2);

    slice3->setColor("#e6a88a");



    QChart *chart = new QChart();

    chart->addSeries(series);

    chart->setTitle("Statistique des Destinations");



    series->setLabelsVisible();



    QChartView *chartView = new QChartView(chart);

    chartView->setRenderHint(QPainter::Antialiasing);

     chartView->chart()->setAnimationOptions(QChart::AllAnimations);

     chartView->chart()->legend()->hide();

    return chartView;
}






QSqlQueryModel* vols::afficherlesNlignes()
    {
    QString duree_string=QString::number(duree);

    QSqlQueryModel * model= new QSqlQueryModel();


    model->setQuery("SELECT  MAX(duree) FROM voll;");



            return model;
    }













int vols::notification()
{
    int i=2;
    QSqlQuery query("SELECT DATEE FROM VOLL");
    while (query.next())
    {
        QDateTime date=query.value(0).toDateTime();
        if (date.addDays(7)<QDateTime::currentDateTime())
        {
            i++;
        }

    }
    return i;
}
