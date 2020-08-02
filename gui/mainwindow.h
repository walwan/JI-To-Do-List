#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>

#include "gui/newDialog.h"
#include "core/task.h"

extern std::vector <Task> task_list;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void refresh_task_item();

private slots:
    void on_btnNewTask_clicked();
    void on_btnSuggestedList_clicked();

private:
    Ui::MainWindow *ui;

    double size_coefficient = 1;

    double cal_size_coefficient(int sample_width, int sample_height);

signals:
    void task_item_need_refresh();

};

#endif // MAINWINDOW_H
