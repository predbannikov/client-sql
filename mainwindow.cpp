#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("testdb");
    db.setUserName("user");
    db.setPassword("user");
    bool ok = db.open();

    if (ok) {
        qDebug() << "ok";
//        db.close();
    } else {
        qDebug() << "no";
    }
    qDebug() << db.tables();


}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushPrintTables_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    auto list = db.tables();
    for (auto item: list) {
        qDebug() << item;
    }
}


void MainWindow::on_pushCreateTable_clicked()
{
    QSqlQuery query;
    query.prepare("CREATE TABLE tabletest(id VARCHAR(255) UNIQUE, description VARCHAR(255))");
    if (query.exec()) {
        qDebug() << "true";
    } else
        qDebug() << "false";
}


void MainWindow::on_pushPrintAllData_clicked()
{
    // get data
    QSqlQuery query;
    query.prepare("SELECT * FROM tabletest");
    if (query.exec()) {
        qDebug() << "true";
        QSqlRecord rec = query.record();
        QString id;
        QString description;
        while (query.next()) {
            id = query.value(rec.indexOf("id")).toString();
            description = query.value(rec.indexOf("description")).toString();
            qDebug() << QString("id = %1     description = %2").arg(id, description);
        }
    } else
        qDebug() << "false";
}


void MainWindow::on_pushSubmit_clicked()
{
    // submit
    QSqlQuery query;
    query.prepare("INSERT INTO tabletest (id, description) values(:id, :descr)");
    query.bindValue(":id", ui->spinBox->value());
    query.bindValue(":descr", ui->textEdit->toPlainText());
    if (query.exec()) {
        qDebug() << "true";
    } else
        qDebug() << "false";
}


