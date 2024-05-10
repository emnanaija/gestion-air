#ifndef BAGAGES_H
#define BAGAGES_H

#include<QString>
#include<QSqlQueryModel>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSlice>
#include <QSqlQueryModel>

class Bagages
{
public:
    Bagages();
    Bagages (int,int,QString);
    int getid_bagages();
    int getpoids();
    QString getdestination_bagages();
    void setid_bagages(int);
    void setpoids(int);
    void setdestination_bagages(QString);
    bool ajouter();
    bool modifier();
   QSqlQueryModel* afficher ();
   bool supprimer (int);
QSqlQueryModel *trie(QString croissance,QString critere);
QChartView *stat_Poids();
QSqlQueryModel * rechercher_Destination(QString a);
bool rech_Destination(QString x);
QSqlQueryModel*rechercherpoids(QString a);
bool rechpoids(QString x);
QSqlQueryModel* rechercher(QString a);
bool rech(int x);
private:
    int id_bagages,poids;
    QString destination_bagages ;

};

#endif // BAGAGES_H
