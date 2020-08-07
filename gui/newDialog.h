#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(double size_coefficient, bool new_mode, QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btnSave_clicked();

private:
    Ui::Dialog *ui;

    bool new_mode;
};

#endif // NEWDIALOG_H
