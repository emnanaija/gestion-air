#include "employes.h"
//#include "mainwindow.h"
#include<QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>

Employes::Employes()
{
 cin=0;
 nom="";
 prenom="";
 nbconge=0;
 nbabsence=0;
 nbheuresup=0;
 tel=0;
 mail="";
}


Employes::Employes(int cin, QString nom,QString prenom,int nbconge,int nbabsence,int nbheuresup,int tel,QString mail )
{

    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->nbconge=nbconge;
    this->nbabsence=nbabsence;

    this->nbheuresup=nbheuresup;


    this->tel=tel;

    this->mail=mail;

}

int Employes :: get_cin()
{
    return cin ;
}

int  Employes ::get_nbconge ()
{
    return nbconge;
}

int Employes :: get_nbheuresup()
{
    return nbheuresup;
}

int Employes :: get_nbabsence()
{
    return nbabsence;
}

int Employes :: get_tel()
{
    return tel;
}
 QString Employes :: get_nom()
 {
     return nom;
 }

 QString Employes :: get_prenom()
 {
     return prenom;
 }

 QString Employes :: get_mail()
 {
     return mail;
 }

 void  Employes :: setcin(int cin)
 {
     this->cin=cin;
 }
 void    Employes :: setnbconge(int nbconge)
 { this->nbconge=nbconge;
 }

  void  Employes :: setnbheuresup(int nbheuresup)
  {this->nbheuresup=nbheuresup;}

void  Employes :: setnbabsence(int nbabsence)
{this->nbabsence=nbabsence;}

  void  Employes:: settel(int tel)
  { this->tel=tel;}
 void  Employes:: setnom(QString nom)
 {this->nom=nom;}
  void  Employes:: setprenom(QString prenom)
  {  this->prenom=prenom;}
  void  Employes:: setmail(QString mail)
  {  this->mail=mail;}




    bool  Employes:: ajouter()
   {




        QSqlQuery query;

        {
        QString cin_string=QString::number(cin);
        QString nbabsence_string=QString::number(nbabsence);
        QString nbheuresup_string=QString::number(nbheuresup);
        QString nbconge_string=QString::number(nbconge);
        QString tel_string=QString::number(tel);
        query.prepare("INSERT INTO EMPLOYES (cin,nom,prenom,nbconge,nbabsence,nbheuresup,tel,mail) "
                      "VALUES (:cin,:nom,:prenom, :nbconge,:nbabsence,:nbheuresup,:tel,:mail)");
        query.bindValue(0, cin_string);
        query.bindValue(1, nom);
        query.bindValue(2, prenom);
        query.bindValue(3, nbconge_string);
        query.bindValue(4, nbabsence_string);
        query.bindValue(5, nbheuresup_string);
        query.bindValue(6,tel_string);
        query.bindValue(7, mail);




      }

         return query.exec();


    }

  bool  Employes ::supprimer (int cin)
  {
      QSqlQuery query;

      query.prepare("delete  from EMPLOYES where cin=:cin ");

      query.bindValue(0, cin);


  return query.exec();

  }
    QSqlQueryModel * Employes:: afficher()
    {
           QSqlQueryModel *model= new   QSqlQueryModel ();


               model->setQuery("SELECT*  FROM employes");
             model->setHeaderData(0, Qt::Horizontal,  QObject::tr("cin"));
               model->setHeaderData(1, Qt::Horizontal,  QObject ::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal,  QObject ::tr("prenom"));
               model->setHeaderData(3, Qt::Horizontal,  QObject ::tr("nbconge"));
               model->setHeaderData(4, Qt::Horizontal,  QObject ::tr("nbabsence"));
               model->setHeaderData(5, Qt::Horizontal,  QObject ::tr("nbheuresup"));
               model->setHeaderData(6, Qt::Horizontal,  QObject ::tr("tel"));
               model->setHeaderData(7, Qt::Horizontal,  QObject ::tr("mail"));


            return  model;

    }



    bool Employes:: modifier()
    {
       QSqlQuery query;
       QString cin_string =QString::number(cin);
       QString nbconge_string =QString::number(nbconge);
        QString nbabsence_string =QString::number(nbabsence);
        QString nbheuresup_string =QString::number(nbheuresup);
        QString tel_string =QString::number(tel);


query.prepare("UPDATE  EMPLOYES SET cin='"+cin_string+"',nom='"+nom+"',prenom='"+prenom+"',nbconge='"+nbconge_string+"',nbabsence='"+nbabsence_string+"',nbheuresup='"+nbheuresup_string+"',tel='"+tel_string+"',mail='"+mail+"' where cin='"+cin_string+"'");
             query.bindValue(0,cin_string);
             query.bindValue(1,nom);
             query.bindValue(2,prenom);
             query.bindValue(3, nbconge_string);
             query.bindValue(4,nbabsence_string);
             query.bindValue(5,nbheuresup_string);
             query.bindValue(6,tel_string);
             query.bindValue(7,mail);
             return query.exec();


    }

    QSqlQueryModel *Employes::Rechercher(QString value )
    {
         QSqlQueryModel *modal=new QSqlQueryModel();
         modal->setQuery("select * from EMPLOYES where cin like '%"+value+"%' or nbheuresup like '%"+value+"%' or nom like '%"+value+"%'or prenom like '%"+value+"%'or mail like '%"+value+"%' or nbabsence like '%"+value+"%' or nbconge like '%"+value+"%' ");
         return modal;
    }


    QSqlQueryModel *Employes::Trier_em (QString croissance,QString critere)
    {
        QSqlQueryModel *modal=new QSqlQueryModel();

        if(critere == "cin" && croissance == "ASC")
            modal->setQuery("select * from EMPLOYES order by CIN ASC ");
        else if(critere == "cin" && croissance == "DESC")
            modal->setQuery("select * from EMPLOYES order by CIN DESC ");

      /* else if(critere == "nom" && croissance == "ASC")
            modal->setQuery("select * from EMPLOYES order by nom ASC ");
        else if(critere == "nom" && croissance == "DESC")
            modal->setQuery("select * from EMPLOYES order by nom DESC ");

        else if(critere == "prenom" && croissance == "ASC")
            modal->setQuery("select * from EMPLOYES order by prenom ASC ");
        else if(critere == "prenom" && croissance == "DESC")
            modal->setQuery("select * from EMPLOYES order by prenom DESC ");

        else if(critere == "tel" && croissance == "ASC")
            modal->setQuery("select * from EMPLOYES order by tel ASC ");
        else if(critere == "tel" && croissance == "DESC")
            modal->setQuery("select * from EMPLOYES order by tel DESC ");

        else if(critere == "nbabsence" && croissance == "ASC")
            modal->setQuery("select * from EMPLOYES order by nbabsence ASC ");
        else if(critere == "nbabsence" && croissance == "DESC")
            modal->setQuery("select * from EMPLOYES order by nbabsence DESC ");

        else if(critere == "nbheuresup" && croissance == "ASC")
            modal->setQuery("select * from EMPLOYES order by nbheuresup ASC ");
        else if(critere == "nbheuresup" && croissance == "DESC")
            modal->setQuery("select * from EMPLOYES order by nbheuresup DESC ");

        else if(critere == "nbconge" && croissance == "ASC")
            modal->setQuery("select * from EMPLOYES order by nbconge ASC ");
        else if(critere == "nbconge" && croissance == "DESC")
            modal->setQuery("select * from EMPLOYES order by nbconge DESC ");

        else if(critere == "mail" && croissance == "ASC")
            modal->setQuery("select * from EMPLOYES order by mail ASC ");
        else if(critere == "mail" && croissance == "DESC")
            modal->setQuery("select * from EMPLOYES order by mail DESC ");
*/

        return  modal;
    }


    QChartView *Employes::stat_absence()
     {

         int a1=0;
         int a2=0;

         QSqlQuery query;
         query.prepare("select * from EMPLOYES where nbabsence>=10");
         query.exec();

         while(query.next())
             a1++;

         query.prepare("select * from EMPLOYES where  nbabsence<=10");
         query.exec();

         while(query.next())
             a2++;



         qDebug() << a1<< a2;

         QPieSeries *series = new QPieSeries();
             series->append("nbabsence >=10", a1);
             series->append("nbabsence <= 10", a2);

             QPieSlice *slice = series->slices().at(0);
             slice->setExploded(true);
             slice->setColor("#ffffff");
             QPieSlice *slice2 = series->slices().at(1);
             slice2->setColor("#000000");



             QChart *chart = new QChart();
             chart->addSeries(series);
             chart->setTitle("Statistique de NOMBRE D'ABSENCE");

             series->setLabelsVisible();

             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
   chartView->chart()->setAnimationOptions(QChart::AllAnimations);
    chartView->chart()->legend()->hide();
             return chartView;

     }



    QSqlQueryModel* Employes::afficherMeilleurEmploye()
        {
        QString nbheuresup_string=QString::number(nbheuresup);

        QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("SELECT * FROM EMPLOYES WHERE nbheuresup=(SELECT MAX(nbheuresup) FROM EMPLOYES)");


                return model;
        }





    QString Employes::cherchercode(QString id)
    {

              QSqlDatabase bd = QSqlDatabase::database();
              QString username;

                  QSqlQuery query;
                  query.prepare("SELECT username FROM username WHERE username =:id");
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

      }






    QString Employes::chercherpassword(QString id)
    {

              QSqlDatabase bd = QSqlDatabase::database();
              QString cin;

                  QSqlQuery query;
                  query.prepare("SELECT department FROM username WHERE department =:id");
                  query.bindValue(0,id);

                  query.exec();
                  if (query.next())
                  {

                      cin=query.value(0).toInt();

                       return cin;

                  }
                  else {
                      return nullptr;
                  }

      }


