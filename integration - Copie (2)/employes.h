#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSqlQueryModel>
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
class Employes
{
public:
    Employes();
    Employes(int,QString,QString,int,int,int,int,QString);
    int get_cin();
    int get_nbconge();
    int get_nbheuresup();
    int get_nbabsence();
    int get_tel();
    QString get_nom();
    QString get_prenom();
    QString get_mail();
    void setcin(int cin);
    void setnbconge(int nbconge);
    void setnbheuresup(int nbheuresup);
    void setnbabsence(int nbabsence);
    void settel(int tel);
    void setnom(QString nom);
    void setprenom(QString prenom);
    void setmail(QString mail);
    bool ajouter();
    bool supprimer (int);
    bool modifier ();
    QSqlQueryModel * afficher();
     QSqlQueryModel *Rechercher(QString value );
     QSqlQueryModel * Trier_em (QString croissance,QString critere);
     QChartView *stat_absence();
     QSqlQueryModel*afficherMeilleurEmploye();
QString cherchercode(QString id);
//int chercherpassword(int id);
QString chercherpassword(QString id);


private:
    int cin ,nbconge,nbheuresup,nbabsence,tel;
    QString nom,prenom,mail;
};

#endif // EMPLOYES_H
