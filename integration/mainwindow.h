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







QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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


private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QVideoWidget* vw;
    Connection c;
    int selected=0;
    QStringList files;
    stat_combo *s;
};
#endif // MAINWINDOW_H
