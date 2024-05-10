#include "bagages.h"
#include<QSqlQuery>
#include<QDebug>
Bagages::Bagages()
{ id_bagages=0 ; poids=0; destination_bagages=" ";

}


Bagages::Bagages (int id_bagages,int poids, QString destination_bagages)
{this->id_bagages =id_bagages; this->poids=poids; this-> destination_bagages=destination_bagages;  }
int Bagages::  getid_bagages(){return id_bagages;}
int Bagages:: getpoids(){return poids;}
QString Bagages :: getdestination_bagages(){return destination_bagages; }
void Bagages:: setid_bagages(int id_bagages){this->id_bagages=id_bagages; }
void Bagages:: setpoids(int poids){this->poids=poids;}
void Bagages:: setdestination_bagages(QString destination_bagages){this->destination_bagages=destination_bagages;}
bool Bagages:: ajouter()
{
    QSqlQuery query;
    QString id_bagages_string = QString::number(id_bagages);
    QString id_poids_string = QString::number(poids);
         query.prepare("INSERT INTO bagages (id_bagages, poids, destination_bagages) "
                       "VALUES (:id_bagages, :poids, :destination_bagages)");
         query.bindValue(0, id_bagages_string);
         query.bindValue(1, poids);
         query.bindValue(2, destination_bagages);
         return query.exec();

}
bool Bagages:: modifier()
{


    QSqlQuery query;

    QString id_bagages_string =QString::number(id_bagages);
    QString poids_string =QString::number(poids);
         query.prepare("UPDATE  BAGAGES SET id_bagages='"+id_bagages_string+"' ,poids='"+ poids_string+"', destination_bagages='"+destination_bagages+"'where id_bagages='"+id_bagages_string+"'");

         query.bindValue(0,id_bagages_string);
         query.bindValue(1, poids_string);
         query.bindValue(2,destination_bagages);




 return query.exec();
}
bool Bagages::supprimer(int id_bagages)
{
    QSqlQuery query;
    QString id_bagages_string = QString::number(id_bagages);
    QString id_poids_string = QString::number(poids);
         query.prepare(" Delete from bagages where id_bagages=:id_bagages");
         query.bindValue(0, id_bagages);

         return query.exec();
}
QSqlQueryModel* Bagages:: afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM bagages");

          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
                model->setHeaderData(1, Qt::Horizontal, QObject::tr("poids"));
                model->setHeaderData(2, Qt::Horizontal, QObject::tr("destination"));


    return model;
}
QSqlQueryModel *Bagages::trie(QString croissance,QString critere)
{
    QSqlQueryModel *modal=new QSqlQueryModel();

    if(critere == "id" && croissance == "ASC")
        modal->setQuery("select * from BAGAGES order by ID_BAGAGES ASC ");
    else if(critere == "id" && croissance == "DESC")
        modal->setQuery("select * from BAGAGES order by ID_BAGAGES DESC ");

    else if(critere == "poids" && croissance == "ASC")
        modal->setQuery("select * from BAGAGES order by poids ASC ");
    else if(critere == "poids" && croissance == "DESC")
        modal->setQuery("select * from BAGAGES order by poids DESC ");

    else if(critere == "destination" && croissance == "ASC")
        modal->setQuery("select * from BAGAGES order by destination_bagages ASC ");
    else if(critere == "destination" && croissance == "DESC")
        modal->setQuery("select * from BAGAGES order by destination_bagages DESC ");

    return  modal;
}

QChartView *Bagages::stat_Poids()
  {

      int a1=0;
      int a2=0;

      QSqlQuery query;
      query.prepare("select * from BAGAGES where poids <=24");
      query.exec();

      while(query.next())
          a1++;

      query.prepare("select * from BAGAGES where poids >24");
      query.exec();

      while(query.next())
          a2++;



      qDebug() << a1<< a2 ;

      QPieSeries *series = new QPieSeries();
          series->append("poids <=24", a1);
          series->append("poids >24", a2);

          QPieSlice *slice = series->slices().at(0);
          slice->setExploded(true);
          slice->setColor("#092cdb");
          QPieSlice *slice2 = series->slices().at(1);
          slice2->setColor("#4360f0");



          QChart *chart = new QChart();
          chart->addSeries(series);
          chart->setTitle("Statistique de Poids");

          series->setLabelsVisible();

          QChartView *chartView = new QChartView(chart);
          chartView->setRenderHint(QPainter::Antialiasing);
chartView->chart()->setAnimationOptions(QChart::AllAnimations);
 chartView->chart()->legend()->hide();
          return chartView;

  }
bool Bagages::rech(int x){
    QSqlQuery query;
    query.prepare("select * from BAGAGES where id_bagages=:id_bagages;");
    query.bindValue(":id_bagages", x);
    return query.exec();
}

QSqlQueryModel* Bagages::rechercher(QString a)
    {

    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from BAGAGES where id_bagages='"+a+"' ");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("poids"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("destination"));

            return model;
    }

bool Bagages::rechpoids(QString x)
{
    QSqlQuery query;
    query.prepare("select * from BAGAGES where poids = :poids;");
    query.bindValue(":poids", x);
    return query.exec();
}

QSqlQueryModel* Bagages::rechercherpoids(QString a)
    {

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from BAGAGES where poids='"+a+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("poids"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("destination"));


            return model;
    }
bool Bagages::rech_Destination(QString x){
    QSqlQuery query;
    query.prepare("select * from BAGAGES where Destination_BAGAGES = :Destination_BAGAGES;");
    query.bindValue(":Destination_BAGAGES", x);
    return query.exec();
}
QSqlQueryModel* Bagages::rechercher_Destination(QString a)
    {

    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from BAGAGES where DESTINATION_BAGAGES ='"+a+"' ");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("poids"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("destination"));


            return model;
    }
