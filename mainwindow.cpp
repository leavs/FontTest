#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <qfontdatabase.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const char *str = "这是中文中文中文！@#￥%……&*（）";
    ui->label->setText(str);
    on_pushButton_clicked();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString buf;
    qDebug() << "System Support follow fonts:";
    buf = "System Support follow fonts:\n";

    QFontDatabase database;

    foreach (const QString &family, database.families())
    {
        qDebug()<<family;
        buf = buf + family + "\n";
    }

    qDebug()<<"\nNow is chinese font:";
    buf = buf + "\nNow is chinese font:\n";
    foreach (const QString &family, database.families(QFontDatabase::SimplifiedChinese))
    {
        qDebug()<<family;
        buf = buf + family + "\n";
    }

    ui->plainTextEdit->setPlainText(buf);
}

void MainWindow::on_pushButton_Exit_clicked()
{
    close();
}

