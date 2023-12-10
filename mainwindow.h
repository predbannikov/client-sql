#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

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

    void on_pushPrintTables_clicked();

    void on_pushCreateTable_clicked();

    void on_pushPrintAllData_clicked();

    void on_pushSubmit_clicked();

    void on_pushCreateUser_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
