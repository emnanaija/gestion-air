#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vols.h"
#include<QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_numpiste->setValidator(new QIntValidator(0,9999999,this));

ui->table_vol->setModel(v.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pb_ajouter_clicked()
{
    QString numvol=ui->le_numvol->text();
    int numpiste=ui->le_numpiste->text().toInt();
    QString avion=ui->le_avion->text();
    QString pilote=ui->le_pilote->text();
    QString destination=ui->le_destination->text();
    QString datee=ui->le_date->text();
    QString description=ui->le_description->text();

   vols v(numvol,numpiste,avion,pilote,destination,datee,description);
bool test=v.ajouter();
QMessageBox msgbox;

if(test)
   { msgbox.setText("ajout avc succes.");
   ui->table_vol->setModel(v.afficher());
   }
else

    msgbox.setText("echec d'ajout.");
   msgbox.exec();
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
