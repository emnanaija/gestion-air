#ifndef VOLS_H
#define VOLS_H
#include<QString>
#include<QSqlQueryModel>
class vols
{
public:
    vols();
    vols(QString,int,QString,QString,QString,QString,QString);


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






private:
QString numvol;
int numpiste;
QString avion;
QString pilote;
QString destination;
QString datee;
QString description;

};

#endif // VOLS_H
