#ifndef TASKITEM_H
#define TASKITEM_H

#include <vector>
#include <QWidget>
#include <QVBoxLayout>

#include "core/task.h"

extern std::vector <Task> task_list;

class taskItem : public QWidget
{
    Q_OBJECT
private:
    unsigned int ID;

    double size_coefficient;


public:
    explicit taskItem(double new_size_coefficient, Task &task, QWidget *parent = nullptr, QVBoxLayout *layout = nullptr);

    unsigned int get_ID() const {return ID;}

signals:

public slots:
};

#endif // TASKITEM_H
