#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qaction.h>
#include <qapplication.h>
#include <qmenubar.h>
#include <qlistview.h>
#include <qpushbutton.h>
#include <qmenu.h>
#include <qmessagebox.h>
#include <qinputdialog.h>
#include <qfiledialog.h>
#include <QFileSystemModel>
#include <qdir.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <infoform.h>
#include <qdesktopservices.h>


typedef unsigned char uchar;
typedef unsigned long ulong;
typedef unsigned int  uint;

typedef struct bfile
{
    FILE *file;
    uchar mask;
    int rack;
    int pacifier_counter;
}
BFILE;

#define PACIFIER_COUNT 2047


#define BITS                       12
#define MAX_CODE                   ( ( 1 << BITS ) - 1 )
#define TABLE_SIZE                 5021
#define END_OF_STREAM              256
#define FIRST_CODE                 257
#define UNUSED                     -1



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionInformation_triggered();

    void on_FirstList_doubleClicked(const QModelIndex &index);

    void on_SecondList_doubleClicked(const QModelIndex &index);

    void on_FirstList_clicked(const QModelIndex &index);

    void on_SecondList_clicked(const QModelIndex &index);

    void on_OpenButton_clicked();

    void on_DirButton_clicked();

    void on_RenameButton_clicked();

    void on_CopyButton_clicked();

    void on_MoveButton_clicked();

    void on_DeleteButton_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *model;
    InfoForm *sWindow;

};

void contentDifference (QDir &sDir, QDir &dDir, QFileInfoList &difflist);
void recursiveContentList (QDir &dir, QFileInfoList &contentList);

#endif // MAINWINDOW_H
