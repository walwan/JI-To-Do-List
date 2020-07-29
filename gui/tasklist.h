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
    void on_edit_clicked();
};

#endif // TASKLIST_H
