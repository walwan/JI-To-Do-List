#ifndef TASKLIST_H
#define TASKLIST_H

#include <QWidget>

class taskList : public QWidget
{
    Q_OBJECT
public:
    explicit taskList(QWidget *parent = nullptr, double size_coefficient = 1);

signals:

public slots:
};

#endif // TASKLIST_H
