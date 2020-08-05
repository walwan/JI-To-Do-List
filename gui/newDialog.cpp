#include <QScrollArea>

#include "gui/mainWindow.h"
#include "gui/taskItem.h"
#include "gui/newDialog.h"
#include "ui_newDialog.h"

#include "core/task.h"

Dialog::Dialog(double size_coefficient, bool new_mode, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    new_mode(new_mode)
{
    ui->setupUi(this);

    //Set properties of this window
    setFixedSize(419,361);

    if(!new_mode){
        taskItem *ptr_parent = (taskItem *) parent;
        int task_index = search_task_ID(task_list, ptr_parent->get_ID());
        ui->textTaskName->setPlainText(QString::fromStdString(task_list[task_index].get_name()));
        ui->textTaskDescription->setPlainText(QString::fromStdString(task_list[task_index].get_description()));

        const int *due = task_list[task_index].get_due();
        ui->textTaskDueYear->setPlainText(QString::number(due[INDEX_DATE_YEAR]));
        ui->textTaskDueMonth->setPlainText(QString::number(due[INDEX_DATE_MONTH]));
        ui->textTaskDueDay->setPlainText(QString::number(due[INDEX_DATE_DAY]));
        ui->textTaskDueHour->setPlainText(QString::number(due[INDEX_DATE_HOUR]));
        ui->textTaskDueMinute->setPlainText(QString::number(due[INDEX_DATE_MIN]));

        ui->textTaskTimeCost->setPlainText(QString::number(task_list[task_index].get_time_cost()));
        ui->textTaskPriority->setPlainText(QString::number(task_list[task_index].get_priority()));
    }

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

    bool name_validity = is_valid_name(ui->textTaskName->toPlainText().toStdString());

    int due[5];
    due[INDEX_DATE_YEAR] = ui->textTaskDueYear->toPlainText().toInt();
    due[INDEX_DATE_MONTH] = ui->textTaskDueMonth->toPlainText().toInt();
    due[INDEX_DATE_DAY] = ui->textTaskDueDay->toPlainText().toInt();
    due[INDEX_DATE_HOUR] = ui->textTaskDueHour->toPlainText().toInt();
    due[INDEX_DATE_MIN] = ui->textTaskDueMinute->toPlainText().toInt();

    bool due_validity = is_valid_date(due);

    bool time_cost_validity = is_valid_time_cost(ui->textTaskTimeCost->toPlainText().toInt());

    bool priority_validity = is_valid_priority(ui->textTaskPriority->toPlainText().toInt());

    if (name_validity && due_validity && time_cost_validity && priority_validity){
        if (new_mode){
            new_task(task_list,
                     ui->textTaskName->toPlainText().toStdString(),
                     ui->textTaskDescription->toPlainText().toStdString(),
                     due,
                     ui->textTaskTimeCost->toPlainText().toInt(),
                     ui->textTaskPriority->toPlainText().toInt());
        }
        else{
            taskItem *ptr_parent = (taskItem *) parentWidget();
            edit_task(task_list,
                      ptr_parent->get_ID(),
                      ui->textTaskName->toPlainText().toStdString(),
                      ui->textTaskDescription->toPlainText().toStdString(),
                      due,
                      ui->textTaskTimeCost->toPlainText().toInt(),
                      ui->textTaskPriority->toPlainText().toInt());
        }

        list_store(task_list);

        this->close();

        QWidget *ptr = (QWidget *) parent();
        while (ptr->parent() != nullptr) {
         ptr = (QWidget *) ptr->parent();
        }
        MainWindow *ptr_main_window = (MainWindow *) ptr;
        ptr_main_window->refresh_task_item();

    }
}
