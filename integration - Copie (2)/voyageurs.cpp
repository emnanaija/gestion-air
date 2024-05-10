#include"voyageurs.h"
#include <QDebug>
#include<QTextDocument>
#include<QTextStream>
#include<QFile>
#include<QSqlQuery>
voyageurs::voyageurs()
{
    id=0; num_pass=0;nom=" "; prenom=" "; destination=" ";
}

voyageurs::voyageurs (int id,int num_pass,QString nom,QString prenom,QString destination)
{this->id=id;this->num_pass=num_pass; this->nom=nom; this->prenom=prenom;this->destination=destination;}
int voyageurs::getid(){return id;}
int voyageurs::getnum_pass(){return num_pass;}
QString voyageurs::getnom(){return nom;}
QString voyageurs::getprenom(){return prenom;}
QString voyageurs::getdestination(){return destination;}
void voyageurs::setid(int id){this->id=id;}
void voyageurs::setnum_pass(int num_pass){this->num_pass=num_pass;}
void voyageurs::setnom(QString nom){this->nom=nom;}
void voyageurs::setprenom(QString prenom){this->prenom=prenom;}
void voyageurs::setdestination(QString destination){this->destination=destination;}
bool voyageurs::ajouter ()


{bool test=false;


    QSqlQuery query;
    QString id_string= QString::number(id);
    QString num_pass_string= QString::number(num_pass);

    query.prepare("INSERT INTO VOYAGEURS (id,num_pass,nom,prenom,destination) "
                  "VALUES (:id, :num_pass,:nom, :prenom,:destination)");
    query.bindValue(":id", id_string);
    query.bindValue(":num_pass", num_pass_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":destination", destination);
    return   query.exec();



 return test;
}






QSqlQueryModel * voyageurs::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VOYAGEURS ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("num_pass"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("destination"));
    return model;
}



bool voyageurs::supprimer(int id)
{
QSqlQuery query;
query.prepare("Delete from VOYAGEURS  where id = :id ");
query.bindValue(":id", id);
return    query.exec();
}







bool voyageurs::modifier(QString id,QString num_pass,QString nom,QString prenom,QString destination)
{
    QSqlQuery query;

    query.prepare("update voyageurs set num_pass=:num_pass,nom=:nom,prenom=:prenom,destination=:destination where id=:id");
    query.bindValue(":id",id);
    query.bindValue(":num_pass", num_pass);
     query.bindValue(":nom", nom);
      query.bindValue(":prenom", prenom);
        query.bindValue(":destination", destination);
    return    query.exec();
}
/*
QSqlQueryModel * voyageurs::chercher(QString id)
{QSqlQueryModel * model= new QSqlQueryModel();
 QString res= id;
 model->setQuery("select * from system.voyageurs where cin='"+res+"'");
return model;
}


*/




QSqlQueryModel *voyageurs::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from voyageurs where id LIKE '"+rech+"%'");
    return model;
}

QSqlQueryModel *voyageurs::tri(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * from voyageurs  ORDER BY destination ");
   q->exec();
   model->setQuery(*q);

   return model;
}

QSqlQueryModel *voyageurs::trid(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM voyageurs ORDER BY destination DESC");
   q->exec();
   model->setQuery(*q);

   return model;
}






QString voyageurs::cherchercode(QString id)
{

          QSqlDatabase bd = QSqlDatabase::database();
          QString username;

              QSqlQuery query;
              query.prepare("SELECT * FROM login WHERE username =:id");
              query.bindValue(0,id);

              query.exec();
              if (query.next())
              {

                 username=query.value(0).toString();

                   return username;

              }
              else {
                  return nullptr;
              }
              /*
              int voyageurs::chercherpassword(int id)
                 {

                           QSqlDatabase bd = QSqlDatabase::database();
                           int cin;

                               QSqlQuery query;
                               query.prepare("SELECT * FROM login WHERE password =:id");
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

                   }*/


  }
