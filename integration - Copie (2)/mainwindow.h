#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlQuery>
#include <QSqlError>
#include <QMainWindow>
#include <QSqlQueryModel>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include<QChartView>
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include "exportexcelobject.h"
#include "connection.h"
#include <QFile>
#include "smtp.h"
#include<QtCharts>
#include <QChart>
#include <QGraphicsView>
#include "employes.h"

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>


#include "stat_combo.h"

#include <QMainWindow>
#include "bagages.h"
#include <QTableWidget>
#include <QTcpServer>
#include<QTcpSocket>
#include"chat.h"
#include <QDialog>
#include <QUdpSocket>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QNetworkInterface>
#include "ui_chat.h"
#include "qrcodegen.hpp"

#include "arduino.h"
#include "voyageurs.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
  bool controlSaisie1();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_table_vol_activated(const QModelIndex &index);

    bool controlSaisie();

    void on_rechercher(const QString &arg1);

    void on_comboBox_highlighted(const QString &arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();
    void on_pdf_clicked();
    void on_lineEdit_textChanged(const QString &arg1);


    void on_pushButton_2_clicked();
    void on_export_excel_clicked();

    void on_stat_0_clicked();

    void on_actionplay_video_clicked();

    //khhedmet emna employes


    void on_bt_ajouter_clicked();

    void on_tabemployes_activated(const QModelIndex &index);

    void on_lineEdit_rech_textChanged(const QString &arg1);
    void on_pb_meilleur_Employe_clicked();
    void on_pbmodif_historique_clicked();
    //void on_pb_sauvg_historique_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pb_modifier_2_clicked();

    void on_radioButton_e_clicked();

    void on_radioButton_e2_clicked();



    void on_pushButtonpdf_clicked();

    void on_pushButton_clicked();








    void on_pb_ajouter_1_clicked();

   void on_pb_supprimer_2_clicked();

   void on_pb_modifier_1_clicked();

   void on_tab_bagages_activated(const QModelIndex &index);

    bool controlSaisie2();
    void on_radioButton_a_clicked();

    void on_radioButton_d_clicked();

    void on_pb_pdf_clicked();


    void on_pb_qrcode_clicked();

    //void on_export_excel_clicked();

    //void on_pushButton1_2_clicked();
   bool launch_chat(chat &chat_window) ;

   void on_pushButton_8_clicked();

   void on_pushButton_7_clicked();

   void on_pb_vols_clicked();

   void on_pb_employees_clicked();

   void on_pb_bagages_clicked();

   void on_pushButton_9_clicked();

   void on_pb_parking_clicked();

   void on_pushButton_10_clicked();

   void on_pushButton_11_clicked();

   void on_pushButton_12_clicked();

   void on_pb_sauv_historique_clicked();
   void update_label2();

   void on_pushButton_6_clicked();

   void on_pb_ajouter_3_clicked();

   void on_pb_supprimer_4_clicked();

   void on_modif_voy_clicked();

   void on_btn_image_clicked();

   void on_export_excel_3_clicked();

   void on_tab_voyageurs_activated(const QModelIndex &index);

   void on_statsmed_clicked();

   void on_radioButton_croissant_clicked();

   void on_radioButton_dcroissant_clicked();

   void on_rechercher_button_clicked();

   void on_pb__voyageurs_clicked();

   void on_pushButton_13_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QVideoWidget* vw;
    Connection c;
    int selected=0;
    QStringList files;
    stat_combo *s;
     Employes e;
     arduino A;
     QByteArray data;
     arduino Ar;
     QByteArray dat;
     voyageurs E;
};
#endif // MAINWINDOW_H
