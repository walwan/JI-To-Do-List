#include "tasklist.h"
#include <QPushButton>
#include <QGridLayout>

taskList::taskList(QWidget *parent, double size_coefficient) : QWidget(parent)
{
    //Create a button for a new task.
    QPushButton *task = new QPushButton(this);
    task->setFixedSize(795*size_coefficient, 150*size_coefficient);

    //*Notice: The text content on the button needs to be changed!
    //*Notice: The format of display needs modification.
    task->setText("Example task 1:\nTask Description: Press \"Edit\" to edit this task. Press \"Delete\" to delete this task"
                  "Due Date: 2020.8.7 23:59.\nExpected Time Cost: 120 minutes.");

    //Basic settings of "Edit" button and "Delete" button.
    //Including size, layout.
    //You may not change these code.
    QGridLayout *listLayout = new QGridLayout(task);
    QPushButton *edit = new QPushButton(task);
    QPushButton *delet = new QPushButton(task);
    edit->setText("Edit");
    delet->setText("Delete");
    edit->setFixedSize(80*size_coefficient,45*size_coefficient);
    delet->setFixedSize(80*size_coefficient,45*size_coefficient);
    listLayout->addWidget(edit);
    listLayout->addWidget(delet);
    listLayout->setVerticalSpacing(16*size_coefficient);
    listLayout->setAlignment(Qt::AlignRight);
}
