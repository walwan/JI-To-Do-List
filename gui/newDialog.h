#ifndef NEW_DIALOG_H
#define NEW_DIALOG_H

#include <QDialog>

#include "core/task.h"

extern std::vector <Task> task_list;

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

#endif // NEW_DIALOG_H
