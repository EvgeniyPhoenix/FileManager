#ifndef SIGNIN_H
#define SIGNIN_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDir>
#include <mainwindow.h>

namespace Ui {
class signin;
}

class signin : public QWidget
{
    Q_OBJECT

public:
    explicit signin(QWidget *parent = nullptr);
    ~signin();

private slots:
    void on_loginButton_clicked();

private:
    Ui::signin *ui;
    QSqlDatabase mydb;
    MainWindow *mWindow;
};

#endif // SIGNIN_H
