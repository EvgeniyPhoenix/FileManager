#ifndef INFOFORM_H
#define INFOFORM_H

#include <QWidget>

namespace Ui {
class InfoForm;
}

class InfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit InfoForm(QWidget *parent = nullptr);
    ~InfoForm();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InfoForm *ui;
};

#endif // INFOFORM_H
