#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vols.h"
#include<QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QSqlError>
#include<QTextDocument>
#include <QTextStream>
#include <QtPrintSupport/QAbstractPrintDialog>
#include <QtPrintSupport/QPrinterInfo>
#include <QPrinter>
#include"connection.h"
#include<QPrintDialog>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSlice>
#include <QSqlQuery>
#include <QSqlError>
#include <QIntValidator>
#include <QString>
#include <QMessageBox>
#include<QTextDocument>
#include <QTextStream>
#include <QtPrintSupport/QAbstractPrintDialog>
#include <QtPrintSupport/QPrinterInfo>
#include <QPrinter>
#include <QTextDocument>
#include <QFileDialog>
#include <QDebug>
#include <QPrintDialog>
#include <QChartView>
#include <QGraphicsView>
#include <QtCharts>
#include <QTabWidget>
#include <QChartView>
#include "exportexcelobject.h"
#include <QFile>
#include "arduino.h"
#include "connection.h"
#include<QtCharts>
#include <QChart>
#include <QGraphicsView>
#include<QPieSeries>
#include<QFile>
#include "form.h"
#include "ui_form.h"

#include <QIntValidator>
#include <QMessageBox>
#include <QSqlQuery>
#include<QSqlError>
#include <iostream>
#include <QString>
#include<QTextDocument>
#include <QTextStream>
#include <QtPrintSupport/QAbstractPrintDialog>
#include <QtPrintSupport/QPrinterInfo>
//#include "connection.h"
#include <QPrintDialog>
#include <QPrinter>
#include <QWidget>
#include <QPrinterInfo>
#include <QDialog>
#include <QFile>
#include <QDebug>
#include"voyageurs.h"

using namespace std;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{ ui->setupUi(this);
    int ret = A.connect_arduino();
    switch(ret)
    { case (0): qDebug() << "arduino is available and connected to"<<A.getarduino_port_name();

       break;

      case (1):  qDebug() << "arduino is available but not  connected to"<<A.getarduino_port_name();
        break;
    case (-1):
         qDebug() << "arduino is not  available";


    }
    QObject:: connect (Ar.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

    //yosser
    int rete = Ar.connect_arduino();
    switch(rete)
    { case (0): qDebug() << "arduino is available and connected to"<<Ar.getarduino_port_name();

       break;

      case (1):  qDebug() << "arduino is available but not  connected to"<<Ar.getarduino_port_name();
        break;
    case (-1):
         qDebug() << "arduino is not  available";


    }
    QObject:: connect (Ar.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
    //yosser
     ui->le_cin->setValidator(new QIntValidator(0, 99999999, this));
     ui->le_tel->setValidator(new QIntValidator(0, 99999999, this));
     ui->le_nbheuresup->setValidator(new QIntValidator(0, 99, this));
     ui->le_nbabsence->setValidator(new QIntValidator(0, 99, this));
     ui->le_nbconge->setValidator(new QIntValidator(0, 99, this));
      //e.stat_absence()->setParent(ui->stat_2);

 vols v;
     ui->table_vol->setModel(v.afficher());
   /* QPixmap pix("C:/Users/MSI/Desktop/logo.png");
       ui->label_3->setPixmap(pix);
      int w=ui->label_3->width();
      int h=ui->label_3->height();
      ui->label_3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


      QPixmap pix1("C:/Users/MSI/Desktop/g_avion.png");
         ui->label_2->setPixmap(pix1);
        int w1=ui->label_2->width();
        int h1=ui->label_2->height();
        ui->label_2->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));

        QPixmap pix2("C:/Users/MSI/Desktop/g_empl.png");
           ui->label_7->setPixmap(pix2);
          int w2=ui->label_7->width();
          int h2=ui->label_7->height();
          ui->label_7->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));

          QPixmap pix3("C:/Users/MSI/Desktop/aaa.png");
             ui->label_16->setPixmap(pix3);
            int w3=ui->label_16->width();
            int h3=ui->label_16->height();
            ui->label_16->setPixmap(pix3.scaled(w,h,Qt::KeepAspectRatio));

            QPixmap pix4("C:/Users/MSI/Desktop/pas.png");
               ui->label_17->setPixmap(pix4);
              int w4=ui->label_17->width();
              int h4=ui->label_17->height();
              ui->label_17->setPixmap(pix4.scaled(w,h,Qt::KeepAspectRatio));

              QPixmap pix5("C:/Users/MSI/Desktop/g_avion.png");
                 ui->label_18->setPixmap(pix5);
                int w5=ui->label_18->width();
                int h5=ui->label_18->height();
                ui->label_18->setPixmap(pix5.scaled(w,h,Qt::KeepAspectRatio));


               QPixmap pix6("C:/Users/MSI/Desktop/logo.png");
                   ui->label_19->setPixmap(pix4);
                  int w6=ui->label_19->width();
                  int h6=ui->label_19->height();
                  ui->label_19->setPixmap(pix6.scaled(w,h,Qt::KeepAspectRatio));



                  QPixmap pix7("C:/Users/MSI/Desktop/g_bagage.png");
                      ui->label_37->setPixmap(pix7);
                     int w7=ui->label_37->width();
                     int h7=ui->label_37->height();
                     ui->label_37->setPixmap(pix7.scaled(w,h,Qt::KeepAspectRatio));


                     QPixmap pix8("C:/Users/MSI/Desktop/g_voyageur.png");
                         ui->label_38->setPixmap(pix8);
                        int w8=ui->label_38->width();
                        int h8=ui->label_38->height();
                        ui->label_38->setPixmap(pix8.scaled(w,h,Qt::KeepAspectRatio));

                        QPixmap pix9("C:/Users/MSI/Desktop/logo.png");
                            ui->label_39->setPixmap(pix9);
                           int w9=ui->label_39->width();
                           int h9=ui->label_39->height();
                           ui->label_39->setPixmap(pix9.scaled(w,h,Qt::KeepAspectRatio));

                          QPixmap pix10("C:/Users/MSI/Desktop/b.png");
                               ui->label_41->setPixmap(pix10);
                              int w10=ui->label_41->width();
                              int h10=ui->label_41->height();
                              ui->label_41->setPixmap(pix10.scaled(w,h,Qt::KeepAspectRatio));

                              QPixmap pix11("C:/Users/MSI/Desktop/back.png");
                                  ui->label_51->setPixmap(pix11);
                                 int w11=ui->label_51->width();
                                 int h11=ui->label_51->height();
                                 ui->label_51->setPixmap(pix11.scaled(w,h,Qt::KeepAspectRatio));
*/

                 ui->table_vol->setModel(v.afficher());
    ui->le_numpiste->setValidator(new QIntValidator(0,9999999,this));
     ui->le_duree->setValidator(new QIntValidator(0,999,this));
      v.stat_type()->setParent(ui->stat_3);
     // connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
      //connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

      QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                         QCoreApplication::organizationName(), QCoreApplication::applicationName());
 ui->table_vol->setModel(v.afficher());

                   if (v.notification()==2)
                   {
                       QString notif=QString::number(v.notification())+" vols bientot.\n""Click Ok to exit.";
                       QMessageBox::warning(nullptr, QObject::tr("Alerte"),notif, QMessageBox::Ok);
                   }



 }





MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::update_label2()
{
 dat="";

while((Ar.getdata().size()<5))
{
    QString key;
data=Ar.read_from_arduino();

break;

}
if(!dat.isEmpty())
{qDebug() << dat;

//qDebug()<<data.toLongLong();
}
if(dat!="")
{

//qDebug()<<data.toLongLong();
qDebug()<<"poids:"<<Ar.chercherid(dat).toInt();
if(Ar.chercherid(dat).toInt()>24)
{
  Ar.write_to_arduino("0");

}

else if(Ar.chercherid(dat).toInt()<=24)
{A.write_to_arduino("1");

}


}
 data="";
}



////////////////////////////
///
///
/// arduino
///
//////////////////
///
///
///
void MainWindow::on_pushButton_10_clicked()
{
    int data=ui->lineEdit_2->text().toInt();

        if(data!=0)
        {

        //qDebug()<<data.toLongLong();
        qDebug()<<"res:"<<A.cherchercode(data);
        if(A.cherchercode(data)!=0)
        {
          A.write_to_arduino("1");
        }

        else if(A.cherchercode(data)==0)
        A.write_to_arduino("0");


        }
         data=0;
}





////
////
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
/// vols
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
vols v(QString numvol,int numpiste,QString avion, QString pilote,QString destination,QString datee,QString description,int duree);


void MainWindow::on_pb_ajouter_clicked()
{


    if (controlSaisie())
    {

    QString numvol=ui->le_numvol->text();
    int numpiste=ui->le_numpiste->text().toInt();
    QString avion=ui->le_avion->text();
    QString pilote=ui->le_pilote->text();
    QString destination=ui->le_destination->text();
    QString datee= ui->dateTimeEdit->dateTime().toString("dd.MM.yyyy hh:mm");


    QString description=ui->le_description->text();
    int duree=ui->le_duree->text().toInt();

   vols v(numvol,numpiste,avion,pilote,destination,datee,description,duree);
    ui->table_vol->setModel(v.afficher());
bool test=v.ajouter();
QMessageBox msgbox;

if(test)
   { msgbox.setText("ajout avc succes.");
   ui->table_vol->setModel(v.afficher());
    msgbox.exec();
   }
else

    msgbox.setText("echec d'ajout.");
   msgbox.exec();
    ui->table_vol->setModel(v.afficher());
}
    else
    {

        QMessageBox::critical(nullptr, QObject::tr("not ok"),

                    QObject::tr("veuiller remplir tous les champs correctement.\n"

                                "Click cancel to exit."), QMessageBox::Cancel);

    }
}



void MainWindow::on_pb_supprimer_clicked()
{
    vols  v;
    v.setnumvol(ui->le_numvol_supp->text());
    bool test=v.supprimer(v.getnumvol());


    QMessageBox msgBox;

    if(test)
       { msgBox.setText("suppresion avec succes.");
        ui->table_vol->setModel(v.afficher());

    }
    else
         msgBox.setText("echec de suppression.");
        msgBox.exec();
}







void MainWindow::on_pb_modifier_clicked()
{


    QString numvol=ui->le_numvol->text();
    int numpiste=ui->le_numpiste->text().toInt();
    QString avion=ui->le_avion->text();
    QString pilote=ui->le_pilote->text();
    QString destination=ui->le_destination->text();
    QString datee= ui->dateTimeEdit->dateTime().toString("dd.MM.yyyy hh:mm");
    QString description=ui->le_description->text();
    int duree=ui->le_duree->text().toInt();
    vols v (numvol,numpiste,avion,pilote,destination,datee,description,duree);

QMessageBox msgbox;
 bool test =v.modifier();
if(test)
   { msgbox.setText("modifier avc succes.");
   ui->table_vol->setModel(v.afficher());
   }
else

    msgbox.setText("echec de modification.");
   msgbox.exec();

   }







void MainWindow::on_table_vol_activated(const QModelIndex &index)
{
    vols v;
   // vols v(QString numvol,int numpiste,QString avion, QString pilote,QString destination,QString datee,QString description);
   ui->table_vol->setModel(v.afficher());
   QString val=ui->table_vol->model()->data(index).toString();
   QSqlQuery qry;
   qry.prepare("select * from voll where numvol='"+val+"'");
   if(qry.exec())
   {
    while(qry.next())
    {
     ui->le_numvol->setText(qry.value(0).toString());
     ui->le_numpiste->setText(qry.value(1).toString());
     ui->le_avion->setText(qry.value(2).toString());
     ui->le_pilote->setText(qry.value(3).toString());
     ui->le_destination->setText(qry.value(4).toString());
     ui->dateTimeEdit->setDateTime(QDateTime::fromString(qry.value(5).toString(), "dd.MM.yyyy hh:mm"));
     ui->le_description->setText(qry.value(6).toString());
     ui->le_duree->setText(qry.value(7).toString());
    }
   }
   else
   {
    QMessageBox::critical(this,tr("error::"),qry.lastError().text());
   }
}




bool MainWindow::controlSaisie()
{
 vols v;
 ui->table_vol->setModel(v.afficher());

    if (

            !(ui->le_numvol->text().contains(QRegExp("^[A-Za-z]+$"))) ||

            !(ui->le_avion->text().contains(QRegExp("^[A-Za-z]+$"))) ||

            !(ui->le_pilote->text().contains(QRegExp("^[A-Za-z]+$"))) ||

            !(ui->le_destination->text().contains(QRegExp("^[A-Za-z]+$"))) ||

            //!(ui->dateTimeEdit->text().contains(QRegExp("^[A-Z0-9./%+-]+$"))) ||

            !(ui->le_description->text().contains(QRegExp("^[A-Za-z]+$")))
       )
        return 0;
else
         return 1;

}


void MainWindow::on_rechercher(const QString &arg1)
{ vols v;
    ui->table_vol->setModel(v.afficher());
    QString search =arg1;

      ui->table_vol->setModel(v.Rechercher(search));

}



void MainWindow::on_comboBox_highlighted(const QString &arg1)
{
    vols v;
    QString type="";
 ui->table_vol->setModel(v.afficher());
    if(ui->radioButton->isChecked())
        type="ASC";
    else if(ui->radioButton_2->isChecked())
        type="DESC";

    if(arg1 != "Choisir")
        ui->table_vol->setModel(v.Trier_em(type,arg1));

    else  ui->table_vol->setModel(v.afficher());
}




void MainWindow::on_radioButton_clicked()
{
    vols v;
    QString type="";

 ui->table_vol->setModel(v.afficher());
    if(ui->radioButton->isChecked())
        type="ASC";
    else if(ui->radioButton_2->isChecked())
        type="DESC";

    if(ui->comboBox->currentText() != "Choisir")
    {ui->table_vol->setModel(v.Trier_em(type,ui->comboBox->currentText()));
         ui->table_vol->setModel(v.afficher());}

    else  ui->table_vol->setModel(v.afficher());
}





void MainWindow::on_radioButton_2_clicked()
{
    vols v;
    QString type="";
     ui->table_vol->setModel(v.afficher());
    if(ui->radioButton->isChecked())
        type="ASC";
    else if(ui->radioButton_2->isChecked())
        type="DESC";

    if(ui->comboBox->currentText() != "Choisir")
       { ui->table_vol->setModel(v.Trier_em(type,ui->comboBox->currentText()));
            ui->table_vol->setModel(v.afficher());}

    else  ui->table_vol->setModel(v.afficher());
}



void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{vols v;
    ui->table_vol->setModel(v.afficher());
    QString search =arg1;

      ui->table_vol->setModel(v.Rechercher(search));

}






void MainWindow::on_pdf_clicked()
{
        QTableView table_vol;
        QSqlQueryModel * Mod=new  QSqlQueryModel();
        QString value=ui->le_numvol->text();
             //Connection c;

             QSqlQuery qry;
             qry.prepare("select * from voll where numvol='"+value+"'");
             qry.exec();
             Mod->setQuery(qry);
             table_vol.setModel(Mod);
             //c.closeconnection();

             QString strStream;
             QTextStream out(&strStream);

           /*  const int rowCount = tab_affaire.model()->rowCount();
             const int columnCount =  tab_affaire.model()->columnCount();*/

             const QString strTitle ="Document";



             out <<  "<html>\n"
                                   //"<img src=':/icons/icons/icone.png'/>"
                                  "<head>\n"
                                      "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                  <<  QString("<title>%1</title>\n").arg(strTitle)
                                  <<  "</head>\n"
                                      "<style> h3{"
                                      "font-family: Century Gothic; color: #333; font-weight: lighter;"
                                      "}\n"
                                      "</style>\n"
                                  "<body bgcolor=#ffffff link=#5000A0>\n"
                                 << QString("<h1 style=\" font-size: 100px; font-family: Century Gothic; color: #e80e90; font-weight: lighter; text-align: center;\">%1</h1>\n").arg("Fiche du vol")
                                 <<"<br>";

                                QString NUMVOL = table_vol.model()->data(table_vol.model()->index(0, 0)).toString().simplified();
                                qDebug()<<NUMVOL;
                                out << QString("<h3>NUMVOL : %1</h3>").arg((!NUMVOL.isEmpty()) ? NUMVOL : QString("&nbsp;"));
                                QString NUMPISTE = table_vol.model()->data(table_vol.model()->index(0, 1)).toString().simplified();
                                out << QString("<h3>NUMPISTE : %1</h3>").arg((!NUMPISTE.isEmpty()) ? NUMPISTE : QString("&nbsp;"));
                                QString AVION = table_vol.model()->data(table_vol.model()->index(0, 2)).toString().simplified();
                                out << QString("<h3>AVION : %1</h3>").arg((!AVION.isEmpty()) ? AVION : QString("&nbsp;"));
                                QString PILOTE = table_vol.model()->data(table_vol.model()->index(0, 3)).toString().simplified();
                                out << QString("<h3 bkcolor=0> PILOTE: %1</h3>").arg((!PILOTE.isEmpty()) ? PILOTE : QString("&nbsp;"));
                                QString DESTINATION = table_vol.model()->data(table_vol.model()->index(0, 4)).toString().simplified();
                                out << QString("<h3 bkcolor=0>DESTINATION : %1</h3>").arg((!DESTINATION.isEmpty()) ? DESTINATION : QString("&nbsp;"));
                                QString DATEE = table_vol.model()->data(table_vol.model()->index(0, 5)).toString().simplified();
                                out << QString("<h3 bkcolor=0>DATEE : %1</h3>").arg((!DATEE.isEmpty()) ? DATEE : QString("&nbsp;"));
                                QString DESCRIPTION = table_vol.model()->data(table_vol.model()->index(0, 6)).toString().simplified();
                                out << QString("<h3 bkcolor=0>DESCRIPTION  : %1</h3>").arg((!DESCRIPTION .isEmpty()) ? DESCRIPTION  : QString("&nbsp;"));
                                QString DUREE = table_vol.model()->data(table_vol.model()->index(0, 6)).toString().simplified();
                                out << QString("<h3 bkcolor=0>DUREE  : %1</h3>").arg((!DUREE .isEmpty()) ? DUREE  : QString("&nbsp;"));

                                out<<
                                  "</body>\n"
                                  "</html>\n";

                                      QTextDocument *document = new QTextDocument();
                                                      document->setHtml(strStream);

                                                      QPrinter printer;
                                                      QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                                                      if (dialog->exec() == QDialog::Accepted) {

                                                          document->print(&printer);
                                                      }

                                                      printer.setOutputFormat(QPrinter::PdfFormat);
                                                      printer.setPaperSize(QPrinter::A2);
           printer.setOutputFileName("/tmp/voll.pdf");
           printer.setPageMargins(QMarginsF(15, 15, 15, 15));

           delete document;

}













void MainWindow::on_pushButton_2_clicked()
{
    vols v;
    ui->table_vol->setModel(v.afficherlesNlignes());



}


















void MainWindow::on_export_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->table_vol);

    //colums to export
    obj.addField(0, "numvol", "char(20)");

     obj.addField(1, "numpiste", "char(20)");
    obj.addField(2, "avion", "char(20)");
    obj.addField(3, "pilote", "char(20)");
    obj.addField(4, "destination", "char(20)");
    obj.addField(5, "date", "char(20)");
    obj.addField(5, "timeedit", "char(20)");


    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}










void MainWindow::on_stat_0_clicked()
{
    s = new stat_combo();

  s->setWindowTitle("statistique ComboBox");
  s->choix_pie();
  s->show();
}







void MainWindow::on_actionplay_video_clicked()
{
    player= new QMediaPlayer;
    vw=new QVideoWidget;

    auto filename=QFileDialog::getOpenFileName(this,"import mp4 file",QDir::rootPath(),"Excel Files(*.mp4)");


    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile(filename));
    vw->setGeometry(100,100,300,400);
    vw->show();
    player->play();
}
//////stacked
void MainWindow::on_pushButton_3_clicked()
{
 ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_4_clicked()
{
 ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_9_clicked()
{
 ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_5_clicked()
{
    QString data=ui->username->text();
    QString a=ui->password->text();
    Employes e;
    if(data!=nullptr && a!=nullptr)
    {
    qDebug()<<"res:"<<e.chercherpassword(a);
    qDebug()<<"res:"<<e.cherchercode(data);
    if(e.cherchercode(data)!=nullptr && e.chercherpassword(a)!=nullptr)
    {

       ui->stackedWidget->setCurrentIndex(2);
    }


}
}


/////////////menu
void MainWindow::on_pb_vols_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_pb_employees_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pb_bagages_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pb_parking_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}



void MainWindow::on_pushButton_11_clicked()
{
 ui->stackedWidget->setCurrentIndex(2);
}



void MainWindow::on_pushButton_12_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pb__voyageurs_clicked()
{
   ui->stackedWidget->setCurrentIndex(6);
}
void MainWindow::on_pushButton_13_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
/// employes
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
 void MainWindow::on_bt_ajouter_clicked()
{   /*if (controlSaisie1())*/
    {
    int cin=ui->le_cin->text().toInt();
     QString nom=ui->le_nom->text();
     QString prenom=ui->le_prenom->text();
     int tel=ui->le_tel->text().toInt();
     QString mail=ui->le_mail->text();
    int nbconge=ui->le_nbconge->text().toInt();
    int nbheuresup=ui->le_nbheuresup->text().toInt();
    int nbabsence=ui->le_nbabsence->text().toInt();




    Employes e ( cin, nom,prenom,nbconge,nbabsence, nbheuresup,tel,mail);

    bool test=e.ajouter();
    QMessageBox msgbox;

    if(test)
       { msgbox.setText("ajout avc succes.");
         ui->tabemployes->setModel(e.afficher());     // e.stat_absence()->setParent(ui->stat_2);

         QFile file("C:/Users/MSI/Desktop/integration - Copie (2)/Historique_Des_Employes");
                     if(file.open(QIODevice::Append | QIODevice::ReadWrite))
                     {
                         QTextStream stream(&file);
                         stream << "l'employe" << nom << " " << prenom << "\ncin: " << cin << "\nmail:" << mail<< "\nnombre dheure supplementaires: " << nbheuresup << "\n nombre de conge"<< nbconge <<"\nnombre dabsence:"<< nbabsence<<endl<<endl<<endl;
                     }
                     file.close();
       }
    else

        msgbox.setText("echec d'ajout.");
       msgbox.exec();
    }
   /*else
    {

        QMessageBox::critical(nullptr, QObject::tr("not ok"),

                    QObject::tr("veuiller remplir tous les champs correctement.\n"

                                "Click cancel to exit."), QMessageBox::Cancel);

    }
*/

}

void MainWindow::on_tabemployes_activated(const QModelIndex &index)
 {

     QString val=ui->tabemployes->model()->data(index).toString();
     QSqlQuery qry ;
     qry.prepare("select * from EMPLOYES where cin='"+val+"'");
     if(qry.exec())
     {
      while(qry.next())
      {
       ui->le_cin->setText(qry.value(0).toString());
       ui->le_nom->setText(qry.value(1).toString());
       ui->le_prenom->setText(qry.value(2).toString());
       ui->le_nbconge->setText(qry.value(3).toString());
       ui->le_nbheuresup->setText(qry.value(4).toString());
       ui->le_nbabsence->setText(qry.value(5).toString());
       ui->le_tel->setText(qry.value(6).toString());
       ui->le_mail->setText(qry.value(7).toString());

      }
     }
     else
     {
      QMessageBox::critical(this,tr("error::"), qry.lastError().text());
     }

 }






 bool MainWindow::controlSaisie1(){



     if (

             !(ui->le_nom->text().contains(QRegExp("^[A-Za-z]+$"))) ||

             !(ui->le_prenom->text().contains(QRegExp("^[A-Za-z]+$"))) ||

             !(ui->le_mail->text().contains(QRegExp("^[A-Za-z]+$"))) ||

             ui->le_cin->text().isEmpty() ||

             ui->le_cin ->text().toInt() == 0 ||

             ui->le_tel->text().isEmpty() ||
             ui->le_tel ->text().toInt() == 0 ||
             ui->le_nbheuresup->text().isEmpty() ||
             ui->le_nbabsence->text().isEmpty() ||
             ui->le_nbconge->text().isEmpty()

             )





         return 0;

     else

         return 1;
}


 void MainWindow::on_lineEdit_rech_textChanged(const QString &arg1)
 {
     Employes e;
         ui->tabemployes->setModel(e.afficher());
         QString search =arg1;

           ui->tabemployes->setModel(e.Rechercher(search));
 }




 void MainWindow::on_pb_meilleur_Employe_clicked()
 {
     Employes E;

   ui->tabemployes->setModel(E.afficherMeilleurEmploye());
 }








void MainWindow::on_pb_modifier_2_clicked()
{
    int cin=ui->le_cin->text().toInt();
     QString nom=ui->le_nom->text();
     QString prenom=ui->le_prenom->text();
     int nbconge=ui->le_nbconge->text().toInt();
      int nbabsence=ui->le_nbabsence->text().toInt();
      int nbheuresup=ui->le_nbheuresup->text().toInt();
     int tel=ui->le_tel->text().toInt();
     QString mail=ui->le_mail->text();

    Employes e (cin,nom,prenom,nbconge,nbabsence,nbheuresup,tel,mail);

    bool test=e.modifier();
  // cout<<test;
    QMessageBox msgbox;


    if(test)
       { msgbox.setText("modifier avc succes.");
       ui->tabemployes->setModel(e.afficher());

       }
    else

        msgbox.setText("echec de modification.");
       msgbox.exec();

}






void MainWindow::on_radioButton_e_clicked()
{
    Employes e;
            QString type="";

       //  ui->tabemployes->setModel(e.afficher());
            if(ui->radioButton_e->isChecked())
                type="ASC";
          else if(ui->radioButton_e2->isChecked())
                type="DESC";

            if(ui->comboBox_3->currentText() !="Choisir")
            {ui->tabemployes->setModel(e.Trier_em(type,ui->comboBox_3->currentText()));
                // ui->tabemployes->setModel(e.afficher());
            }

            else  ui->tabemployes->setModel(e.afficher());
}

void MainWindow::on_radioButton_e2_clicked()
{
    Employes e;
            QString type="";
            // ui->tabemployes->setModel(e.afficher());
            if(ui->radioButton_e->isChecked())
                type="ASC";
            else if(ui->radioButton_e2->isChecked())
                type="DESC";

            if(ui->comboBox_3->currentText() != "Choisir")
               { ui->tabemployes->setModel(e.Trier_em(type,ui->comboBox_3->currentText()));
                   // ui->tabemployes->setModel(e.afficher());}
}
            else  ui->tabemployes->setModel(e.afficher());
}


void MainWindow::on_pushButtonpdf_clicked()
{
    QTableView tabemployes;
               QSqlQueryModel * Mod=new  QSqlQueryModel();
               QString value=ui->le_cin->text();
                    //Connection c;

                    QSqlQuery qry;
                    qry.prepare("select * from EMPLOYES where CIN='"+value+"'");
                    qry.exec();
                    Mod->setQuery(qry);
                    tabemployes.setModel(Mod);
                    //c.closeconnection();

                    QString strStream;
                    QTextStream out(&strStream);


                    const QString strTitle ="Document";



                    out <<  "<html>\n"
                                          //"<img src=':/icons/icons/icone.png'/>"
                                         "<head>\n"
                                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                         <<  QString("<title>%1</title>\n").arg(strTitle)
                                         <<  "</head>\n"
                                             "<style> h3{"
                                             "font-family: Century Gothic; color: #333; font-weight: lighter;"
                                             "}\n"
                                             "</style>\n"
                                         "<body bgcolor=#ffffff link=#5000A0>\n"
                                        << QString("<h1 style=\" font-size: 40px; font-family: Century Gothic; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h1>\n").arg("Fiche employes")
                                        <<"<br>";

                                       QString CIN = tabemployes.model()->data(tabemployes.model()->index(0, 0)).toString().simplified();
                                       qDebug()<<CIN;
                                       out << QString("<h3>cin : %1</h3>").arg((!CIN.isEmpty()) ? CIN : QString("&nbsp;"));
                                   QString nom = tabemployes.model()->data(tabemployes.model()->index(0, 1)).toString().simplified();
                                       out << QString("<h3>nom : %1</h3>").arg((!nom.isEmpty()) ? nom: QString("&nbsp;"));
                                       QString prenom = tabemployes.model()->data(tabemployes.model()->index(0, 2)).toString().simplified();
                                       out << QString("<h3>prenom : %1</h3>").arg((!prenom.isEmpty()) ? prenom : QString("&nbsp;"));
                                       QString nbheuresup = tabemployes.model()->data(tabemployes.model()->index(0, 3)).toString().simplified();
                                       out << QString("<h3 bkcolor=0> nbheuresup : %1</h3>").arg((!nbheuresup .isEmpty()) ? nbheuresup  : QString("&nbsp;"));
                                       QString nbconge = tabemployes.model()->data(tabemployes.model()->index(0, 4)).toString().simplified();
                                       out << QString("<h3 bkcolor=0>nbconge  : %1</h3>").arg((!nbconge .isEmpty()) ? nbconge  : QString("&nbsp;"));
                                       QString nbabsence= tabemployes.model()->data(tabemployes.model()->index(0, 5)).toString().simplified();
                                       out << QString("<h3 bkcolor=0> nbabsence : %1</h3>").arg((! nbabsence.isEmpty()) ?  nbabsence : QString("&nbsp;"));
                                       QString tel = tabemployes.model()->data(tabemployes.model()->index(0, 6)).toString().simplified();
                                       out << QString("<h3 bkcolor=0>tel : %1</h3>").arg((!tel.isEmpty()) ? tel  : QString("&nbsp;"));
                                       QString mail = tabemployes.model()->data(tabemployes.model()->index(0, 7)).toString().simplified();
                                       out << QString("<h3 bkcolor=0>mail : %1</h3>").arg((!mail.isEmpty()) ? mail : QString("&nbsp;"));

                                       out<<
                                         "</body>\n"
                                         "</html>\n";

                                             QTextDocument *document = new QTextDocument();
                                                             document->setHtml(strStream);

                                                             QPrinter printer;
                                                             QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                                                             if (dialog->exec() == QDialog::Accepted) {

                                                                 document->print(&printer);
                                                             }

                                                             printer.setOutputFormat(QPrinter::PdfFormat);
                                                            printer.setPaperSize(QPrinter::A4);

                                                             printer.setOutputFileName("/tmp/tabemployes.pdf");
                                                             printer.setPageMargins(QMarginsF(15, 15, 15, 15));

                                                             delete document;

}

void MainWindow::on_pushButton_clicked()
{
    Employes e1;
    e1.setcin(ui->le_cinsup_2->text().toInt());
    bool test= e1.supprimer(e1.get_cin());
    QMessageBox msgbox;
    if(test)
       { msgbox.setText("sup avc succes.");
        ui->tabemployes->setModel(e.afficher());
       }
    else

        msgbox.setText("echec de suppression.");
       msgbox.exec();
}

































///
///
///
///
///
///
///
///
///
///
///
/// bagages
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
///
 void MainWindow::on_pb_ajouter_1_clicked()
 { int id_bagages=ui->le_id->text().toInt();
     int poids =ui->le_poids->text().toInt();
     QString destination_bagages=ui->la_destination->text();

     Bagages B(id_bagages,poids,destination_bagages);
     bool test=B.ajouter();
     QMessageBox msgBox;
     if (test){

         msgBox.setText("Ajout avec succes.");
     ui->tab_bagages->setModel(B.afficher());}
     else
         msgBox.setText("Echec d'ajout");
         msgBox.exec();
 }

 void MainWindow::on_pb_supprimer_2_clicked()
 {
     Bagages B1; B1.setid_bagages(ui->le_id_supp->text().toInt());
     bool test=B1.supprimer(B1.getid_bagages());
     QMessageBox msgBox;
     if (test)
         msgBox.setText("Supression avec succes.");
     else
         msgBox.setText("Echec de suppression");
         msgBox.exec();


 }

 void MainWindow::on_pb_modifier_1_clicked()
 {

     QString destination_bagages=ui->la_destination->text();
        int id_bagages=ui->le_id->text().toInt();
      int poids=ui->le_poids->text().toInt();

       Bagages B (id_bagages,poids,destination_bagages);
    bool test=B.modifier();
    QMessageBox msgbox;

    if(test)
       { msgbox.setText("modifier avc succes.");
       ui->tab_bagages->setModel(B.afficher());
       }
    else

        msgbox.setText("echec de modification.");
       msgbox.exec();

       }


 void MainWindow::on_tab_bagages_activated(const QModelIndex &index)
 {
 QString val=ui->tab_bagages->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from Bagages where id_bagages='"+val+"'");
    if(qry.exec())
    {
     while(qry.next())
     {
      ui->le_id->setText(qry.value(0).toString());
      ui->le_poids->setText(qry.value(1).toString());
      ui->la_destination->setText(qry.value(2).toString());

     }
    }
    else
    {
     QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
 }

 bool MainWindow::controlSaisie2()
 {



     if (



            ! (ui->la_destination->text().contains(QRegExp("^[A-Za-z]+$"))) ||

             ui->le_id->text().isEmpty() ||

             ui->le_id->text().toInt() == 0 ||

             ui->le_poids->text().isEmpty() ||

             ui->le_poids->text().toInt() == 0
  )
         return 0;

     else

         return 1;

 }


 void MainWindow::on_radioButton_a_clicked()
 {
     Bagages b;
   QString type="";


   if(ui->radioButton_a->isChecked())
       type="ASC";
   else if(ui->radioButton_d->isChecked())
       type="DESC";

   if(ui->comboBox->currentText() != "Choisir")
       ui->tab_bagages->setModel(b.trie(type,ui->comboBox_3->currentText()));

   else  ui->tab_bagages->setModel(b.afficher());
 }

 void MainWindow::on_radioButton_d_clicked()
 {
     Bagages b;
   QString type="";


   if(ui->radioButton_a->isChecked())
       type="ASC";
   else if(ui->radioButton_d->isChecked())
       type="DESC";

   if(ui->comboBox->currentText() != "Choisir")
       ui->tab_bagages->setModel(b.trie(type,ui->comboBox_3->currentText()));

   else  ui->tab_bagages->setModel(b.afficher());
 }

 void MainWindow::on_pb_pdf_clicked()
 {
     QTableView tab_bagages;
            QSqlQueryModel * Mod=new  QSqlQueryModel();
            QString value=ui->le_id->text();
                // Connection c;

                 QSqlQuery qry;




                 qry.prepare("select * from BAGAGES where ID_BAGAGES ='"+value+"'");
                 qry.exec();
                 Mod->setQuery(qry);
                 tab_bagages.setModel(Mod);
                 //c.closeconnection();

                 QString strStream;
                 QTextStream out(&strStream);

               /*  const int rowCount = table_necessiteux.model()->rowCount();
                 const int columnCount =  table_necessiteux.model()->columnCount();*/

                 const QString strTitle ="Document";



                 out <<  "<html>\n"
                                      "<img src='C:/icone.png'/>"
                                      "<head>\n"
                                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                      <<  QString("<title>%1</title>\n").arg(strTitle)
                                      <<  "</head>\n"
                                          "<style> h3{"
                                          "font-family: Century Gothic; color: #333; font-weight: lighter;"
                                          "}\n"
                                          "</style>\n"
                                      "\n<body bgcolor=#fffcff link=#5000A0>\n"
                                     << QString("<h1 style=\" font-size: 50px; font-family: Century Gothic; color: #e80e33; font-weight: lighter; text-align: center;\">%1</h1>\n").arg("Fiche Bagages")
                                     <<"<br>";

                                    QString ID = tab_bagages.model()->data(tab_bagages.model()->index(0, 0)).toString().simplified();
                                    qDebug()<<ID;
                                    out << QString("<h3>ID : %1</h3>\n").arg((!ID.isEmpty()) ? ID: QString("&nbsp;"));

                                    QString poids = tab_bagages.model()->data(tab_bagages.model()->index(0, 1)).toString().simplified();
                                    out << QString("<h3>poids : %1</h3>\n").arg((!poids.isEmpty()) ? poids: QString("&nbsp;"));

                                    QString destination = tab_bagages.model()->data(tab_bagages.model()->index(0, 2)).toString().simplified();
                                    out << QString("<h3>destination : %1</h3>").arg((!destination.isEmpty()) ? destination: QString("&nbsp;"));


                                    out<<
                                      "</body>\n"
                                      "</html>\n";

                                          QTextDocument *document = new QTextDocument();
                                                          document->setHtml(strStream);

                                                          QPrinter printer;
                                                          QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                                                          if (dialog->exec() == QDialog::Accepted) {

                                                              document->print(&printer);
                                                          }

                                                          printer.setOutputFormat(QPrinter::PdfFormat);
                                                          printer.setPaperSize(QPrinter::A4);
                                                          printer.setOutputFileName("/tmp/B.pdf");
                                                          printer.setPageMargins(QMarginsF(18, 18, 18, 18));

                                                          delete document;
 }

 /*void MainWindow::on_pushButton_6_clicked()
 {
     Bagages b;
        QString choix=ui->comboBox_4->currentText();

        if (choix=="id")
        {
            QString id= ui->lineEdit_rech->text();
            ui->tab_bagages->setModel(b.rechercher(id));
        }
        if (choix=="poids")
        {
            QString poids = ui->lineEdit_rech->text();
            ui->tab_bagages->setModel(b.rechercherpoids(poids));
        }
        if (choix=="destination")
        {
            QString destination = ui->lineEdit_rech->text();
            ui->tab_bagages->setModel(b.rechercher_Destination(destination));
        }
 }
*/

 void MainWindow::on_pb_qrcode_clicked()
 {
     using namespace qrcodegen;

        ///////////////// FETCH DATA FROM DATABASE ////////////////////////
        QTableView tab_bagages;
        QSqlQueryModel * Mod=new  QSqlQueryModel();
        QString value=ui->le_id->text();


             QSqlQuery qry;




             qry.prepare("select * from BAGAGES where id_bagages='"+value+"'");
             qry.exec();
             Mod->setQuery(qry);
             tab_bagages.setModel(Mod);


            ///////////////// SAVING DATA ///////////
            QString id = tab_bagages.model()->data(tab_bagages.model()->index(0, 0)).toString().simplified();
            QString poids= tab_bagages.model()->data(tab_bagages.model()->index(0, 1)).toString().simplified();
            QString destinations = tab_bagages.model()->data(tab_bagages.model()->index(0, 2)).toString().simplified();



        QString text = id+"\n"+poids+"\n"+destinations+"\n";
          // Create the QR Code object
          QrCode qr = QrCode::encodeText( text.toUtf8().data(), QrCode::Ecc::MEDIUM );

          qint32 sz = qr.getSize();
          QImage im(sz,sz, QImage::Format_RGB32);
            QRgb black = qRgb( 191,112,105 );
            QRgb white = qRgb(255,255,255);
          for (int y = 0; y < sz; y++)
            for (int x = 0; x < sz; x++)
              im.setPixel(x,y,qr.getModule(x, y) ? black : white );//setpixelmap tafichilek qr code
          ui->qrcode->setPixmap( QPixmap::fromImage(im.scaled(200,200,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );
 }

/* void MainWindow::on_export_excel_clicked()
 {
     QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                         tr("Excel Files (*.xls)"));
         if (fileName.isEmpty())
             return;

         ExportExcelObject obj(fileName, "mydata", ui->tab_bagages);

         //colums to export
         obj.addField(0, "id_bagages", "char(20)");

          obj.addField(1, "poids", "char(20)");
         obj.addField(2, "destination_bagages", "char(20)");



         int retVal = obj.export2Excel();
         if( retVal > 0)
         {
             QMessageBox::information(this, tr("Done"),
                                      QString(tr("%1 records exported!")).arg(retVal)
                                      );
 }
 }*/

 void MainWindow::on_pushButton_7_clicked()
 {
     chat *chat_window= new chat(this);
         chat_window->setModal(true);
         chat_window->show();

         qDebug()<< "Chat is running on " << QThread::currentThread();

         chat_window->exec();
 }


 bool MainWindow::launch_chat(chat &chat_window)
 {
     chat_window.setModal(true);
     chat_window.show();

     qDebug()<< "Chat is running on " << QThread::currentThread();

     return chat_window.exec();
 }

 void MainWindow::on_pushButton_8_clicked()
 {
     QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
     QDesktopServices::openUrl(link);
 }











void MainWindow::on_pbmodif_historique_clicked()
{
    QString code=ui->lineEdit_code_histo->text();
        if(code=="111")
        {   ui->label_historique->setText("!!!Right code!!!\nYou can now modify the file.");
            QFile file("C:/Users/MSI/Desktop/integration - Copie (2)/Historique_Des_Employes");
            if(file.open(QIODevice::Truncate | QIODevice::ReadWrite))
            {
                QTextStream stream(&file);
               stream << ui->historique->toPlainText();
             }
        }
        else
        {
            ui->label_historique->setText("!!!WRONG code!!!\nAcess denied Sorry.");
        }
}

void MainWindow::on_pb_sauv_historique_clicked()
{
    //clear();
        QFile file("C:/Users/MSI/Desktop/integration - Copie (2)/Historique_Des_Employes");
        if(file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            QString filedata;
            while(stream.atEnd()==false)
            {
               filedata +=stream.readLine() + "\n";
            }
            ui->historique->setText(filedata);
            }
}

void MainWindow::on_pushButton_6_clicked()
{
    Bagages b;
       QString choix=ui->comboBox_4->currentText();

       if (choix=="id")
       {
           QString id= ui->lineEdit_rech_2->text();
           ui->tab_bagages->setModel(b.rechercher(id));
       }
       if (choix=="poids")
       {
           QString poids = ui->lineEdit_rech_2->text();
           ui->tab_bagages->setModel(b.rechercherpoids(poids));
       }
       if (choix=="destination")
       {
           QString destination = ui->lineEdit_rech_2->text();
           ui->tab_bagages->setModel(b.rechercher_Destination(destination));
       }
}



//////
////
////
///
///
///
///
///
///
///
///amin
///
///
///
///
///
///
///
///
///
///
///
///
///
///


void MainWindow::on_pb_ajouter_3_clicked()
{
    int id=ui->Le_id->text().toInt();
    int num_pass=ui->Le_num_pass->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString destination=ui->Le_destination->currentText();


voyageurs E(id,num_pass,nom,prenom,destination);

bool test=E.ajouter();
QMessageBox msgbox;

if(test)
{
   msgbox.setText("Ajout avec succes.");
ui->tab_voyageurs->setModel(E.afficher());
}
else
    msgbox.setText("Echec d'ajout");
    msgbox.exec();
}




void MainWindow::on_pb_supprimer_4_clicked()
{
    voyageurs E1; E1.setid(ui->le_id_supp_3->text().toInt());
        bool test=E1.supprimer(E1.getid());

        QMessageBox msgbox;


        if(test)
           {msgbox.setText("Suppression avec succes.");
        ui->tab_voyageurs->setModel(E.afficher());
        }
        else
            msgbox.setText("Echec ");
            msgbox.exec();
}












void MainWindow::on_modif_voy_clicked()
{
    QString id, num_pass,nom,prenom,destination;
             id=ui->Le_id->text();
             num_pass=ui->Le_num_pass->text();
             nom=ui->le_nom->text();
            prenom=ui->le_prenom->text();
            destination=ui->Le_destination->currentText();
         //   tmpvoy.modifier(id,num_pass,nom,prenom,destination);
             ui->tab_voyageurs->setModel(E.afficher());

}

void MainWindow::on_btn_image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"),"",tr("*.png,*.jpg,*.jpeg*,*.bmp,*.gif"));

       if(QString::compare(filename,QString()) != 0)
       {



       QImage image;
       bool valid = image.load(filename);

       if(valid)
       {
           //image = image.scaledToWidth(ui->lbl_image->width(),Qt::SmoothTransformation  );
          // ui->lbl_image->setPixmap(QPixmap::fromImage(image));
       }
       else
       {
          //Error handling

       }

   }
}

void MainWindow::on_export_excel_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                              tr("Excel Files (*.xls)"));
              if (fileName.isEmpty())
                  return;

              ExportExcelObject obj(fileName, "mydata", ui->tab_voyageurs);

              //colums to export
              obj.addField(0, "id", "char(20)");

               obj.addField(1, "num_pass", "char(20)");
               obj.addField(2, "nom", "char(20)");
                obj.addField(3, "prenom", "char(20)");
              obj.addField(4, "destination", "char(20)");



              int retVal = obj.export2Excel();
              if( retVal > 0)
              {
                  QMessageBox::information(this, tr("Done"),
                                           QString(tr("%1 records exported!")).arg(retVal)
                                           );
      }


}

void MainWindow::on_tab_voyageurs_activated(const QModelIndex &index)
{

    {
        voyageurs v;
       // vols v(QString numvol,int numpiste,QString avion, QString pilote,QString destination,QString datee,QString description);
       ui->tab_voyageurs->setModel(v.afficher());
       QString val=ui->tab_voyageurs->model()->data(index).toString();
       QSqlQuery qry;
       qry.prepare("select * from voll where numvol='"+val+"'");
       if(qry.exec())
       {
        while(qry.next())
        {
         ui->Le_id->setText(qry.value(0).toString());
         ui->Le_num_pass->setText(qry.value(1).toString());
         ui->le_nom->setText(qry.value(2).toString());
         ui->le_prenom->setText(qry.value(3).toString());
         //ui->Le_destination->setText(qry.value(4).toString());



        }
       }
       else
       {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());}



}
}

void MainWindow::on_statsmed_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
              model->setQuery("select * from VOYAGEURS where destination='Milan' ");
              int number1=model->rowCount();
              model->setQuery("select * from VOYAGEURS where destination ='Barcelone' ");
              int number2=model->rowCount();
              model->setQuery("select * from VOYAGEURS where destination='Newyork' ");
              int number3=model->rowCount(); // calculer le nombre de direction = ny
             model->setQuery("select * from VOYAGEURS where destination='London' ");
                   int number4=model->rowCount();
                   model->setQuery("select * from VOYAGEURS where destination ='Tokyo' ");
                   int number5=model->rowCount();
              model->setQuery("select * from VOYAGEURS where destination='Autre' ");
              int number6=model->rowCount();
              int total=number1+number2+number3+number4+number5+number6;
              QString a = QString("Milan"+QString::number((number1*100)/total,'f',2)+"%" );
              QString b = QString("Barcelone"+QString::number((number2*100)/total,'f',2)+"%" );
              QString c = QString("Newyork"+QString::number((number3*100)/total,'f',2)+"%" );
              QString d = QString("London" +QString::number((number4*100)/total,'f',2)+"%" );
              QString e = QString("Tokyo" +QString::number((number5*100)/total,'f',2)+"%" );
              QString f = QString("Autre"+QString::number((number6*100)/total,'f',2)+"%" );


              QPieSeries *series = new QPieSeries();
              series->append(a,number1);
              series->append(b,number2);
              series->append(c,number3);
              series->append(d,number4);
              series->append(e,number5);
              series->append(f,number6);
              if (number1!= 0)
              {
                  QPieSlice *slice = series->slices().at(0);
                  slice->setLabelVisible();
                  slice->setPen(QPen());
              }
              if (number2!=0)
              {
                       // Add label, explode and define brush for 2nd slice
                       QPieSlice *slice1 = series->slices().at(1);
                       //slice1->setExploded();
                       slice1->setLabelVisible();
              }
              if(number3!=0)
              {
                       // Add labels to rest of slices
                       QPieSlice *slice2 = series->slices().at(2);
                       //slice1->setExploded();
                       slice2->setLabelVisible();
              }
              if(number4!=0)
              {
                       // Add labels to rest of slices
                       QPieSlice *slice3 = series->slices().at(3);
                       //slice1->setExploded();
                       slice3->setLabelVisible();
              }
              if(number5!=0)
              {
                       // Add labels to rest of slices
                       QPieSlice *slice4 = series->slices().at(4);
                       //slice1->setExploded();
                       slice4->setLabelVisible();
              }
              if(number6!=0)
              {
                       // Add labels to rest of slices
                       QPieSlice *slice5 = series->slices().at(5);
                       //slice1->setExploded();
                       slice5->setLabelVisible();
              }
                      // Create the chart widget
                      QChart *chart = new QChart();
                      // Add data to chart with title and hide legend
                      chart->addSeries(series);
                      chart->setTitle("Pourcentage Par destination"+ QString::number(total));
                      chart->legend()->hide();
                      // Used to display the chart
                      QChartView *chartView = new QChartView(chart);
                      chartView->setRenderHint(QPainter::Antialiasing);
                      chartView->resize(1000,500);
                      chartView->show();
}

void MainWindow::on_radioButton_croissant_clicked()
{
   ui->tab_voyageurs->setModel(E.tri());
}


void MainWindow::on_radioButton_dcroissant_clicked()
{
 ui->tab_voyageurs->setModel(E.trid());
}

void MainWindow::on_rechercher_button_clicked()
{
    QString rech =ui->ID_VOL->text();
                  ui->tab_voyageurs->setModel(E.rechercher(rech));
}




