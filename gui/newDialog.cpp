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
     * Effect: close the dialog and refresh the buttons in scrollArea
     * TODO: save the data into cooresponding task or a new task from the text edit
     ********************************************************************************************/
     this->close();
     QWidget *ptr = (QWidget *) parent();
     while (ptr->parent() != nullptr) {
         ptr = (QWidget *) ptr->parent();
     }
     MainWindow *ptr_main_window = (MainWindow *) ptr;
    ptr_main_window->refresh_task_item();

}
