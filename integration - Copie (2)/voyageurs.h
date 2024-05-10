#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QSqlQuery>
#include <QSqlQueryModel>


#include <QString>
class voyageurs
{
public:
    voyageurs();
    voyageurs (int,int,QString,QString,QString);
    int getid();
    int getnum_pass();
    QString getnom();
    QString getprenom();
    QString getdestination();
    void setid(int);
    void setnum_pass(int);
    void setnom(QString);
    void setprenom(QString);
    void setdestination(QString);
    bool ajouter();

    QSqlQueryModel* afficher();

    bool supprimer(int);
QString cherchercode(QString id);
bool supprimer(QString);

QSqlQueryModel * rechercher(QString);
 QSqlQueryModel *tri();
 QSqlQueryModel * trid();

 bool modifier(QString,QString,QString,QString,QString);

private:
    int id,num_pass;
    QString nom,prenom,destination;

};

#endif // ETUDIANT_H
