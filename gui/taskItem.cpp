#include <QPushButton>
#include <QGridLayout>

#include "taskItem.h"
#include "newDialog.h"
#include "mainwindow.h"

#include "core/task.h"

taskItem::taskItem(double new_size_coefficient, Task &task, QWidget *parent, QVBoxLayout *scrollLayout) :
    QWidget(parent),
    ID(task.get_ID()),
    size_coefficient(new_size_coefficient)
{

    //Create a button for a new task.
    QPushButton *btnTask = new QPushButton(this);
    btnTask->setFixedSize(785*size_coefficient, 150*size_coefficient);

    //*Notice: The text content on the button needs to be changed!
    //*Notice: The format of display needs modification.
    QString btnTaskText = QString::fromStdString(task.get_name() + "\n" + task.get_description());
    btnTask->setText(btnTaskText);

    //Basic settings of "Edit" button and "Delete" button.
    //Including size, layout.
    //You may not change these code.
    QGridLayout *listLayout = new QGridLayout(btnTask);
    QPushButton *edit = new QPushButton(btnTask);
    QPushButton *delet = new QPushButton(btnTask);
    edit->setText("Edit");
    delet->setText("Delete");
    edit->setFixedSize(80*size_coefficient, 45*size_coefficient);
    delet->setFixedSize(80*size_coefficient, 45*size_coefficient);
    listLayout->addWidget(edit);
    listLayout->addWidget(delet);
    listLayout->setVerticalSpacing(16*size_coefficient);
    listLayout->setAlignment(Qt::AlignRight);

    connect(edit, &QPushButton::released,
            [=]()
    {
        Dialog *new_dialog = new Dialog(size_coefficient, false, this);
        new_dialog->setAttribute(Qt::WA_DeleteOnClose);
        new_dialog->show();
        /*********************************************************************************************
         * Effect: open the newDialog
         * TODO: display the current data (eg.task_name) cooresponding in text edit
         ********************************************************************************************/
    });

    //Delete the task item after clicking "Delete"
    connect(delet, &QPushButton::released,
            [=]()
    {
        btnTask->setParent(nullptr);
        scrollLayout->removeWidget(btnTask);
        delete btnTask;

        delete_task(task_list,ID);

        list_store(task_list);

        QWidget *ptr = parent;
        while (ptr->parent() != nullptr) {
         ptr = (QWidget *) ptr->parent();
        }
        MainWindow *ptr_main_window = (MainWindow *) ptr;
        ptr_main_window->refresh_task_item();

    });
}
