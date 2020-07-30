#include <QScrollArea>

#include "gui/mainwindow.h"
#include "gui/taskItem.h"
#include "gui/newDialog.h"
#include "ui_newDialog.h"

Dialog::Dialog(double size_coefficient, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //Set properties of this window
    setFixedSize(419,361);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnSave_clicked()
{
    /*********************************************************************************************
     * Effect: close the dialog and add a new button for the task
     *         (TODO) creat a new task and save the data to new task from the text edit
     *
     * INPUT: /
     *
     * OUTPUT: /
     ********************************************************************************************/
     this->close();
     QWidget *ptr = (QWidget *) parent();
     while (ptr->parent() != nullptr) {
         ptr = (QWidget *) ptr->parent();
     }
     MainWindow *ptr_main_window = (MainWindow *) ptr;
    ptr_main_window->refresh_task_item();

}
