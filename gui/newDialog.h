#ifndef NEW_DIALOG_H
#define NEW_DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(double size_coefficient, QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btnSave_clicked();

private:
    Ui::Dialog *ui;
};

#endif // NEW_DIALOG_H
