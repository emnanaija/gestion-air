#ifndef VOLS_H
#define VOLS_H
#include<QString>
#include<QSqlQueryModel>
#include<QtWidgets>
#include<QtCharts/QAreaSeries>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include <QtCharts/QAreaSeries>
#include <QChartView>
#include <QtCharts/QLineSeries>
#include <QGridLayout>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSlice>
#include<QtCharts>
#include <QChart>
#include <QGraphicsView>
using namespace std;


class vols
{
public:
    vols();
    vols(QString,int,QString,QString,QString,QString,QString,int);


    QString getnumvol();
       int getnumpiste();
         QString getavion();
            QString getpilote();
                QString getdestination();
                     QString getdate();
                          QString getdescription();



              void setnumvol(QString);
            void setnumpiste(int);
          void setavion(QString);
        void setpilote(QString);
      void setdestinantion(QString);
    void setdate(QString);
  void setdescription(QString);
QSqlQueryModel * afficher();
bool ajouter();
bool supprimer (QString);
bool  modifier();
QSqlQueryModel *Rechercher(QString value );
QSqlQueryModel *Trier_em(QString croissance,QString critere);
QChartView *stat_type();
QSqlQueryModel* afficherlesNlignes();
int notification();



private:
QString numvol;
int numpiste;
QString avion;
QString pilote;
QString destination;
QString datee;
QString description;
int duree;
};

#endif // VOLS_H
