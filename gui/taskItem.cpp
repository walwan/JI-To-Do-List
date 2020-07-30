#include <QPushButton>
#include <QGridLayout>

#include "taskItem.h"
#include "newDialog.h"
#include "mainwindow.h"

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
//    btnTask->setText("Example task 1:\nTask Description: Press \"Edit\" to edit this task. Press \"Delete\" to delete this task"
//                  "Due Date: 2020.8.7 23:59.\nExpected Time Cost: 120 minutes.");
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
        Dialog *new_dialog = new Dialog(size_coefficient,this);
        new_dialog->setAttribute(Qt::WA_DeleteOnClose);
        new_dialog->show();
    });

    //Delete the task item after clicking "Delete"
    connect(delet, &QPushButton::released,
            [=]()
    {
        btnTask->setParent(nullptr);
        scrollLayout->removeWidget(btnTask);
        delete btnTask;
    });
}
