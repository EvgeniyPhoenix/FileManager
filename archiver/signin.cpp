#include "signin.h"
#include "ui_signin.h"

signin::signin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
    mydb=QSqlDatabase::addDatabase("QODBC");
    QString path = "C:/project/login.accdb";
    mydb.setDatabaseName("Driver={Microsoft Access Driver (*.mdb, *.accdb)};DSN='';DBQ="+path);
    if (!mydb.open())
    {
        ui->ststusLabel->setText("Database is not available");
    }
    else
        ui->ststusLabel->setText("Database connected");
}

signin::~signin()
{
    delete ui;
}

void signin::on_loginButton_clicked()
{
    QString username, password;
    username = ui->usernameEdit->text();
    password = ui->passwordEdit->text();
    if (!mydb.isOpen())
    {
        return;
    }
    QSqlQuery qry;
    if (qry.exec("select * from users where username='"+username +"' and password='"+password +"'"))
    {
        int count=0;
        while (qry.next())
        {
            count++;
        }
        switch (count)
        {
        case 1:
        {
            ui->ststusLabel->setText("Login and password is correct");
            this->close();
            mWindow = new MainWindow();
            mWindow->setStyleSheet("QWidget {background: 'white';}");
            mWindow->setWindowIcon(QIcon(":/rec/Icon32.png"));
            mWindow->show();
            this->close();
        }
            break;
        case 0:
            ui->ststusLabel->setText("Login and password is not correct!");
            break;
        default:
            ui->ststusLabel->setText("Multiple match of login and password");
            break;
          }
    }

}

