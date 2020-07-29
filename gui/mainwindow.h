#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "new_dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_newTask_clicked();

private:
    Ui::MainWindow *ui;

    double cal_size_coefficient(int sample_width, int sample_height);

};

#endif // MAINWINDOW_H
