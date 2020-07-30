#ifndef TASKITEM_H
#define TASKITEM_H

#include <vector>
#include <QWidget>

#include "core/task.h"

class taskItem : public QWidget
{
    Q_OBJECT
private:
    unsigned int ID;

    double size_coefficient;


public:
    explicit taskItem(double new_size_coefficient, Task &task, QWidget *parent = nullptr);

signals:

public slots:
    void on_edit_clicked();
};

#endif // TASKITEM_H
