#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QFileSystemModel(this);
    model->setFilter(QDir::AllEntries);
    model->setRootPath("");
    ui->FirstList->setModel(model);
    ui->SecondList->setModel(model);
    sWindow = new InfoForm();
    sWindow->setStyleSheet("QWidget {background: 'white';}");
    sWindow->setWindowIcon(QIcon(":/rec/Icon32.png"));
    connect(sWindow, &InfoForm::firstWindow, this, &MainWindow::show);
    ui->OpenButton->setEnabled(false);
    ui->RenameButton->setEnabled(false);
    ui->DirButton->setEnabled(false);
    ui->CopyButton->setEnabled(false);
    ui->MoveButton->setEnabled(false);
    ui->DeleteButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QFileDialog dialog;
    //QFileInfo fileInfo;
    QString str = dialog.getExistingDirectory(this, "Выберите рабочий каталог", "", dialog.ShowDirsOnly);
    QDir dir = str;
    ui->FirstList->setRootIndex(model->index(dir.absolutePath()));
}

void MainWindow::on_actionInformation_triggered()
{
    sWindow->show();
    this->close();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_FirstList_doubleClicked(const QModelIndex &index)
{
    QListView* listView = (QListView*)sender();
    QFileInfo fileInfo = model->fileInfo(index);
    ui->FirstList->setStatusTip("Active");
    ui->SecondList->setStatusTip("Passive");
    ui->OpenButton->setEnabled(false);
    ui->DirButton->setEnabled(false);
    ui->RenameButton->setEnabled(false);
    ui->CopyButton->setEnabled(false);
    ui->MoveButton->setEnabled(false);
    ui->DeleteButton->setEnabled(false);
    if (fileInfo.fileName() == "..")
    {
        QDir dir = fileInfo.dir();
        dir.cdUp();
        listView->setRootIndex(model->index(dir.absolutePath()));
    }
    else if (fileInfo.fileName() == ".")
    {
        listView->setRootIndex(model->index(""));
    }
    else if (fileInfo.isDir())
    {
        listView->setRootIndex(index);
    }
    else
    {
        QDesktopServices::openUrl(QUrl(fileInfo.absoluteFilePath(), QUrl::TolerantMode));
    }
}


void MainWindow::on_SecondList_doubleClicked(const QModelIndex &index)
{
    QListView* listView = (QListView*)sender();
    QFileInfo fileInfo = model->fileInfo(index);
    ui->SecondList->setStatusTip("Active");
    ui->FirstList->setStatusTip("Passive");
    ui->OpenButton->setEnabled(false);
    ui->DirButton->setEnabled(false);
    ui->RenameButton->setEnabled(false);
    ui->CopyButton->setEnabled(false);
    ui->MoveButton->setEnabled(false);
    ui->DeleteButton->setEnabled(false);
    if (fileInfo.fileName() == "..")
    {
        QDir dir = fileInfo.dir();
        dir.cdUp();
        listView->setRootIndex(model->index(dir.absolutePath()));
    }
    else if (fileInfo.fileName() == ".")
    {
        listView->setRootIndex(model->index(""));
    }
    else if (fileInfo.isDir())
    {
        listView->setRootIndex(index);
    }
    else
    {
        QDesktopServices::openUrl(QUrl(fileInfo.absoluteFilePath(), QUrl::TolerantMode));
    }
}


void MainWindow::on_FirstList_clicked(const QModelIndex &index)
{
    QFileInfo fileInfo = model->fileInfo(index);
    ui->FirstList->setStatusTip("Active");
    ui->SecondList->setStatusTip("Passive");
    //ui->SecondList->clearSelection();
    if ((fileInfo.fileName() == "..") || (fileInfo.fileName() == "."))
    {
        ui->OpenButton->setEnabled(false);
        ui->DirButton->setEnabled(true);
        ui->RenameButton->setEnabled(false);
        ui->CopyButton->setEnabled(false);
        ui->MoveButton->setEnabled(false);
        ui->DeleteButton->setEnabled(false);
    }
    else
    {
        ui->OpenButton->setEnabled(true);
        ui->DirButton->setEnabled(true);
        ui->RenameButton->setEnabled(true);
        ui->CopyButton->setEnabled(true);
        ui->MoveButton->setEnabled(true);
        ui->DeleteButton->setEnabled(true);
    }
}


void MainWindow::on_SecondList_clicked(const QModelIndex &index)
{
    QFileInfo fileInfo = model->fileInfo(index);
    ui->SecondList->setStatusTip("Active");
    ui->FirstList->setStatusTip("Passive");
    //ui->FirstList->clearSelection();
    if ((fileInfo.fileName() == "..") || (fileInfo.fileName() == "."))
    {
        ui->OpenButton->setEnabled(false);
        ui->DirButton->setEnabled(true);
        ui->RenameButton->setEnabled(false);
        ui->CopyButton->setEnabled(false);
        ui->MoveButton->setEnabled(false);
        ui->DeleteButton->setEnabled(false);
    }
    else
    {
        ui->OpenButton->setEnabled(true);
        ui->DirButton->setEnabled(true);
        ui->RenameButton->setEnabled(true);
        ui->CopyButton->setEnabled(true);
        ui->MoveButton->setEnabled(true);
        ui->DeleteButton->setEnabled(true);
    }
}


void MainWindow::on_OpenButton_clicked()
{
    QFileInfo fileI = model->fileInfo(ui->FirstList->currentIndex());
    QFileInfo fileII = model->fileInfo(ui->SecondList->currentIndex());
    if (ui->FirstList->statusTip() == "Active")
    {
        if (fileI.isDir())
        {
            ui->FirstList->setRootIndex(ui->FirstList->currentIndex());
        }
        else
        {
            QDesktopServices::openUrl(QUrl(fileI.absoluteFilePath(), QUrl::TolerantMode));
        }
    }
    else if (ui->SecondList->statusTip() == "Active")
    {
        if (fileII.isDir())
        {
            ui->SecondList->setRootIndex(ui->SecondList->currentIndex());
        }
        else
        {
            QDesktopServices::openUrl(QUrl(fileII.absoluteFilePath(), QUrl::TolerantMode));
        }
    }
}


void MainWindow::on_DirButton_clicked()
{

    if (ui->FirstList->statusTip() == "Active")
    {
        QString filename = QInputDialog::getText(this, "Enter file name", "Enter name:");
        model->mkdir(ui->FirstList->currentIndex().parent(), filename);
    }
    else if (ui->SecondList->statusTip() == "Active")
    {
        QString filename = QInputDialog::getText(this, "Enter file name", "Enter name:");
        model->mkdir(ui->SecondList->currentIndex().parent(), filename);
    }
}

void MainWindow::on_RenameButton_clicked()
{
    QFileInfo fileI = model->fileInfo(ui->FirstList->currentIndex());
    QFileInfo fileII = model->fileInfo(ui->SecondList->currentIndex());
    if (ui->FirstList->statusTip() == "Active")
    {
        if (fileI.isDir())
        {
            QString filename = QInputDialog::getText(this, "Enter new name", "Enter name:");
            QFile::rename(fileI.absoluteFilePath(), fileI.absolutePath()+"/"+filename);
        }
        else
        {
            QString filename = QInputDialog::getText(this, "Enter new name", "Enter name:");
            QFile::rename(fileI.absoluteFilePath(), fileI.absolutePath()+"/"+filename+"."+fileI.suffix());
        }
    }
    else if (ui->SecondList->statusTip() == "Active")
    {
        if (fileII.isDir())
        {
            QString filename = QInputDialog::getText(this, "Enter new name", "Enter name:");
            QFile::rename(fileII.absoluteFilePath(), fileII.absolutePath()+"/"+filename);
        }
        else
        {
            QString filename = QInputDialog::getText(this, "Enter new name", "Enter name:");
            QFile::rename(fileII.absoluteFilePath(), fileII.absolutePath()+"/"+filename+"."+fileII.suffix());
        }
    }
}

void contentDifference (QDir &sDir, QDir &dDir, QFileInfoList &diffList)
{
    foreach (QFileInfo sInfo, sDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
        bool fileExists = false;
        foreach (QFileInfo dInfo, dDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
        {
            if (sInfo.fileName() == dInfo.fileName())
            {
                if (sInfo.isDir() || sInfo.lastModified() <= dInfo.lastModified())
                    fileExists = true;
                break;
            }
        }
        if (!fileExists)
            diffList.append(sInfo);
        if (sInfo.isFile())
            continue;
        if (fileExists)
        {
            sDir.cd(sInfo.fileName());
            dDir.cd(sInfo.fileName());
            contentDifference(sDir, dDir, diffList);
            sDir.cdUp();
            dDir.cdUp();
        }
        else
        {
            sDir.cd(sInfo.fileName());
            recursiveContentList(sDir, diffList);
            sDir.cdUp();
        }
    }
}

void recursiveContentList(QDir &dir, QFileInfoList &contentList)
{
    foreach(QFileInfo info, dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
        contentList.append(info);
        if (info.isDir() && dir.cd(info.fileName()))
        {
            recursiveContentList(dir, contentList);
            dir.cdUp();
        }
    }
}

void MainWindow::on_CopyButton_clicked()
{
    QFileInfo fileI = model->fileInfo(ui->FirstList->currentIndex());
    QFileInfo fileII = model->fileInfo(ui->SecondList->currentIndex());
    if (ui->FirstList->statusTip() == "Active")
    {
        if (fileI.isDir())
        {
            QDir sDir = QDir(model->filePath(ui->FirstList->rootIndex()));
            QDir dDir = QDir(model->filePath(ui->SecondList->rootIndex()));
            model->mkdir(ui->SecondList->rootIndex(), fileI.baseName());
            dDir.cd(fileI.baseName());
            sDir = QDir(model->filePath(ui->FirstList->currentIndex()));
            QFileInfoList diffList = QFileInfoList();
            contentDifference(sDir, dDir, diffList);
            foreach (QFileInfo diffInfo, diffList)
            {
                QString backupPath = diffInfo.filePath().replace(sDir.absolutePath(), dDir.absolutePath());
                if (diffInfo.isFile())
                {
                    QFile::remove(backupPath);
                    QFile::copy(diffInfo.absoluteFilePath(), backupPath);
                }
                if (diffInfo.isDir())
                {
                    dDir.mkdir(backupPath);
                }
            }

        }
        else
        {
            QFile::copy(fileI.absoluteFilePath(), model->filePath(ui->SecondList->rootIndex())+"/"+fileI.fileName());
        }
    }
    else if (ui->SecondList->statusTip() == "Active")
    {
        if (fileII.isDir())
        {
            QDir sDir = QDir(model->filePath(ui->SecondList->rootIndex()));
            QDir dDir = QDir(model->filePath(ui->FirstList->rootIndex()));
            model->mkdir(ui->FirstList->rootIndex(), fileII.baseName());
            dDir.cd(fileII.baseName());
            sDir = QDir(model->filePath(ui->SecondList->currentIndex()));
            QFileInfoList diffList = QFileInfoList();
            contentDifference(sDir, dDir, diffList);
            foreach (QFileInfo diffInfo, diffList)
            {
                QString backupPath = diffInfo.filePath().replace(sDir.absolutePath(), dDir.absolutePath());
                if (diffInfo.isFile())
                {
                    QFile::remove(backupPath);
                    QFile::copy(diffInfo.absoluteFilePath(), backupPath);
                }
                if (diffInfo.isDir())
                {
                    dDir.mkdir(backupPath);
                }
            }

        }
        else
        {
            QFile::copy(fileII.absoluteFilePath(), model->filePath(ui->FirstList->rootIndex())+"/"+fileII.fileName());
        }
    }
}

void MainWindow::on_MoveButton_clicked()
{
    QFileInfo fileI = model->fileInfo(ui->FirstList->currentIndex());
    QFileInfo fileII = model->fileInfo(ui->SecondList->currentIndex());
    if (ui->FirstList->statusTip() == "Active")
    {
        if (fileI.isDir())
        {
            QDir sDir = QDir(model->filePath(ui->FirstList->rootIndex()));
            QDir dDir = QDir(model->filePath(ui->SecondList->rootIndex()));
            model->mkdir(ui->SecondList->rootIndex(), fileI.baseName());
            dDir.cd(fileI.baseName());
            sDir = QDir(model->filePath(ui->FirstList->currentIndex()));
            QFileInfoList diffList = QFileInfoList();
            contentDifference(sDir, dDir, diffList);
            foreach (QFileInfo diffInfo, diffList)
            {
                QString backupPath = diffInfo.filePath().replace(sDir.absolutePath(), dDir.absolutePath());
                if (diffInfo.isFile())
                {
                    QFile::remove(backupPath);
                    QFile::copy(diffInfo.absoluteFilePath(), backupPath);
                }
                if (diffInfo.isDir())
                {
                    dDir.mkdir(backupPath);
                }
            }
            QDir dir(fileI.absolutePath()+"/"+fileI.baseName());
            dir.removeRecursively();
        }
        else
        {
            QFile::copy(fileI.absoluteFilePath(), model->filePath(ui->SecondList->rootIndex())+"/"+fileI.fileName());
            QFile::remove(fileI.absoluteFilePath());
        }
    }
    else if (ui->SecondList->statusTip() == "Active")
    {
        if (fileII.isDir())
        {
            QDir sDir = QDir(model->filePath(ui->SecondList->rootIndex()));
            QDir dDir = QDir(model->filePath(ui->FirstList->rootIndex()));
            model->mkdir(ui->FirstList->rootIndex(), fileII.baseName());
            dDir.cd(fileII.baseName());
            sDir = QDir(model->filePath(ui->SecondList->currentIndex()));
            QFileInfoList diffList = QFileInfoList();
            contentDifference(sDir, dDir, diffList);
            foreach (QFileInfo diffInfo, diffList)
            {
                QString backupPath = diffInfo.filePath().replace(sDir.absolutePath(), dDir.absolutePath());
                if (diffInfo.isFile())
                {
                    QFile::remove(backupPath);
                    QFile::copy(diffInfo.absoluteFilePath(), backupPath);
                }
                if (diffInfo.isDir())
                {
                    dDir.mkdir(backupPath);
                }
            }
            QDir dir(fileII.absolutePath()+"/"+fileII.baseName());
            dir.removeRecursively();
        }
        else
        {
            QFile::copy(fileII.absoluteFilePath(), model->filePath(ui->FirstList->rootIndex())+"/"+fileII.fileName());
            QFile::remove(fileII.absoluteFilePath());
        }
    }
}



void MainWindow::on_DeleteButton_clicked()
{
    QFileInfo fileI = model->fileInfo(ui->FirstList->currentIndex());
    QFileInfo fileII = model->fileInfo(ui->SecondList->currentIndex());
    if (ui->FirstList->statusTip() == "Active")
    {
        if (fileI.isDir())
        {
            QDir dir(fileI.absolutePath()+"/"+fileI.baseName());
            dir.removeRecursively();
        }
        else
        {
            QFile::remove(fileI.absoluteFilePath());
        }
    }
    else if (ui->SecondList->statusTip() == "Active")
    {
        if (fileII.isDir())
        {
            QDir dir(fileII.absolutePath()+"/"+fileII.baseName());
            dir.removeRecursively();
        }
        else
        {
            QFile::remove(fileII.absoluteFilePath());
        }
    }
}

