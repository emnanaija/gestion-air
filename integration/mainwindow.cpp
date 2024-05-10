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
#include "smtp.h"
#include "connection.h"
#include<QtCharts>
#include <QChart>
#include <QGraphicsView>
#include<QPieSeries>
#include<QFile>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{ui->setupUi(this);
 vols v;
     ui->table_vol->setModel(v.afficher());
    QPixmap pix("C:/Users/MSI/Desktop/logo.png");
       ui->label_3->setPixmap(pix);
      int w=ui->label_3->width();
      int h=ui->label_3->height();
      ui->label_3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


     ui->table_vol->setModel(v.afficher());
    ui->le_numpiste->setValidator(new QIntValidator(0,9999999,this));
     ui->le_duree->setValidator(new QIntValidator(0,999,this));
      v.stat_type()->setParent(ui->stat_3);
     // connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
      //connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));


      QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                         QCoreApplication::organizationName(), QCoreApplication::applicationName());


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

            !(ui->dateTimeEdit->text().contains(QRegExp("^[A-Z0-9./%+-]+$"))) ||

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















