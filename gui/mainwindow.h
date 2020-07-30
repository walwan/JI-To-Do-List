#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>

#include "gui/newDialog.h"
#include "core/task.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(std::vector <Task> &new_task_list, QWidget *parent = nullptr);
    ~MainWindow();

    void refresh_task_item();

private slots:
    void on_btnNewTask_clicked();

private:
    std::vector <Task> &task_list;

    double size_coefficient = 1;

    double cal_size_coefficient(int sample_width, int sample_height);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
