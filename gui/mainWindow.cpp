#include "mainWindow.h"
#include "ui_mainWindow.h"

#include <QGridLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

//These headers requires QT 5.0.0+
#include <QScreen>
#include <QGuiApplication>

#include "gui/newDialog.h"
#include "gui/taskItem.h"
#include "core/task.h"
#include "core/suggestedList.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("JI To-Do List");

    QPalette pal = this->palette();
    QColor color = QColor(Qt::white);
    pal.setColor(QPalette::Window,color);
    this->setPalette(pal);

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
    int cnt = 0;
    if(ui->scrollAreaWidgetContents->layout() != nullptr)
    {
        int cnt = ui->scrollAreaWidgetContents->layout()->count();
        for (int i = 0; i < cnt; i++)
        {
            QLayoutItem *delItem = ui->scrollAreaWidgetContents->layout()->takeAt(0);
            ui->scrollAreaWidgetContents->layout()->removeWidget(delItem->widget());
            delete delItem->widget();
        }
        delete ui->scrollAreaWidgetContents->layout();
    }
    QVBoxLayout *scrollLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);

    //An example of using the taskItem button.
    //*Notice: A new taskItem button should be created after newTask ("Add New Task") button is clicked!
    //*Notice: Remember to add it to the corresponding layout (scrollLayout).
    if (!task_list.empty()){
        taskItem *newTask;
        for (auto e: task_list){
            newTask = new taskItem(size_coefficient, e, ui->scrollArea, scrollLayout);
            scrollLayout->addWidget(newTask);
            cnt++;
        }
    }
    scrollLayout->setSpacing(0);

    ui->scrollAreaWidgetContents->setLayout(scrollLayout);
    ui->scrollAreaWidgetContents->setFixedSize(850*size_coefficient,180*cnt*size_coefficient);
}

void MainWindow::on_btnNewTask_clicked()
{
    Dialog *new_dialog = new Dialog(size_coefficient, true, this);
    new_dialog->show();
}

void MainWindow::on_btnSuggestedList_clicked(){

    task_list = suggested_list_generator(task_list);

    refresh_task_item();
}
