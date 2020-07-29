#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

//This header requires QT 5.0.0+
#include <QScreen>
#include <QGuiApplication>
#include <QDebug>

//=====================================================
//Include the header files below to use tasklist button!
#include <QVBoxLayout>
#include "tasklist.h"
//=====================================================

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("JI To-Do List");

    double size_coefficient = cal_size_coefficient(1920,1080);

    //Basic settings for layout.
    //You may not change these code.
    QSize main_window_size(1200*size_coefficient, 900*size_coefficient);
    ui->buttons->setMaximumWidth(350*size_coefficient);
    ui->buttons->setMinimumHeight(150*size_coefficient);
    ui->newTask->setMinimumHeight(40*size_coefficient);
    ui->suggestedList->setMinimumHeight(40*size_coefficient);
    ui->synchronize->setMinimumHeight(40*size_coefficient);
    ui->suggestedListDisplay->setMaximumWidth(350*size_coefficient);

    QVBoxLayout *scrollLayout = new QVBoxLayout(ui->scrollArea);
    //An example of using the tasklist button.
    //*Notice: A new tasklist button should be created after newTask ("Add New Task") button is clicked!
    //*Notice: Remember to add it to the corresponding layout (scrollLayout).
    taskList *newTask = new taskList(ui->scrollArea,size_coefficient);
    scrollLayout->addWidget(newTask);
    ui->scrollArea->setLayout(scrollLayout);


}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::cal_size_coefficient(int sample_width, int sample_height){
    //Please DO NOT release memory from this pointer.
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screen_size = screen->geometry();
//    qDebug() << screen_geo.width() << screen_geo.height();

    return (double)screen_size.height()/sample_height;
}
