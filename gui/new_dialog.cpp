#include "new_dialog.h"
#include "ui_new_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
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
}
