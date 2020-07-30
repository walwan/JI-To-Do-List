#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

//This header requires QT 5.0.0+
#include <QScreen>
#include <QGuiApplication>

#include "gui/mainwindow.h"
#include "ui_mainwindow.h"

//=====================================================
//Include the header files below to use taskItem button!
#include <QVBoxLayout>
#include "gui/taskItem.h"
//=====================================================

MainWindow::MainWindow(std::vector <Task> &new_task_list, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    task_list(new_task_list)
{
    ui->setupUi(this);
    setWindowTitle("JI To-Do List");

    //Get the resize coefficient
    size_coefficient = cal_size_coefficient(1920,1080);

    //Basic settings for layout.
    //You may not change these code.
    setFixedSize(1200*size_coefficient, 900*size_coefficient);

    ui->buttons->setMaximumSize(350*size_coefficient, 150*size_coefficient);
    ui->btnNewTask->setMinimumHeight(40*size_coefficient);
    ui->btnSuggestedList->setMinimumHeight(40*size_coefficient);
    ui->btnSynchronize->setMinimumHeight(40*size_coefficient);

    ui->suggestedListDisplay->setMaximumWidth(350*size_coefficient);

    //Initialzie the task items in the scrollarea
    refresh_task_item();

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * MainWindow::cal_size_coefficient()
 *
 * EFFECT:
 * Calculate the resize coefficient according to user's screen resolution
 *
 * INPUT:
 * int sample_width: The width of the default screen resolution when designing UI
 * int sample_height: The height of the default screen resolution when designing UI
 *
 * OUTPUT:
 * double size_coefficient: The resize coefficient
 *
 * NOTE:
 * This function SHOULD be called when the mainwindow object is being constructed
 * The coefficient returned by this function SHOULD be used in all the widgets with
 * preset size
 *
 */
double MainWindow::cal_size_coefficient(int sample_width, int sample_height){
    //Please DO NOT release memory from this pointer.
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screen_size = screen->geometry();
    double sample_ratio = (double) sample_width / sample_height;
    double screen_ratio = (double) screen_size.width() / screen_size.height();
    if (screen_ratio >= sample_ratio) return (double) screen_size.height() / sample_height;
    else return (double) screen_size.width() / sample_width;
}

void MainWindow::refresh_task_item(){
    if(ui->scrollArea->layout() != nullptr)
    {
        int cnt = ui->scrollArea->layout()->count();
        for (int i = 0; i < cnt; i++)
        {
            QLayoutItem *delItem = ui->scrollArea->layout()->takeAt(0);
            ui->scrollArea->layout()->removeWidget(delItem->widget());
            delete delItem->widget();
        }
        delete ui->scrollArea->layout();
    }
    QVBoxLayout *scrollLayout = new QVBoxLayout(ui->scrollArea);
    //An example of using the taskItem button.
    //*Notice: A new taskItem button should be created after newTask ("Add New Task") button is clicked!
    //*Notice: Remember to add it to the corresponding layout (scrollLayout).
    if (!task_list.empty()){
        taskItem *newTask;
        for (auto e: task_list){
            newTask = new taskItem(size_coefficient, e, ui->scrollArea, scrollLayout);
            scrollLayout->addWidget(newTask);
        }
    }

    ui->scrollArea->setLayout(scrollLayout);
}

void MainWindow::on_btnNewTask_clicked()
{
    Dialog *new_dialog = new Dialog(size_coefficient, this);
    new_dialog->show();
}
