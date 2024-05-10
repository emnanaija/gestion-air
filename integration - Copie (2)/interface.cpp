#include "interface.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"vols.h"

#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/MSI/Desktop/logo.png");
       ui->label_pic2->setPixmap(pix);
      int w=ui->label_pic2->width();
      int h=ui->label_pic2->height();
      ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


      QPixmap pix2("C:/Users/MSI/Desktop/s4/bienvenue.png");
         ui->label_bienvenue->setPixmap(pix2);
      int w1=ui->label_bienvenue ->width();
      int h1=ui->label_bienvenue->height();
      ui->label_bienvenue->setPixmap(pix2.scaled(w1,h1,Qt::KeepAspectRatio));


}





MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
 client c;
 c.setusername(ui->lineEdit_username->text());
 //c.setprenom(ui->lineEdit_motepasse->text());

 Dialog  d;
 d.setclient(c);
 d.exec();


}
