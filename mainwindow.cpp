#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <qfontdatabase.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const char *str = "北京芯普思信息技术有限公司";
    ui->label->setText(str);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << "System Support follow fonts:";

    QFontDatabase database;

    foreach (const QString &family, database.families())
    {
        qDebug()<<family;
    }

    qDebug()<<"\nNow is chinese font:";
    foreach (const QString &family, database.families(QFontDatabase::SimplifiedChinese))
    {
        qDebug()<<family;
    }
}
