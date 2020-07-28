#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
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
    setWindowTitle("JI To-do List");

    //Basic settings for layout.
    //You may not change these code.
    setFixedSize(1200, 900);
    ui->buttons->setMaximumWidth(350);
    ui->buttons->setMinimumHeight(150);
    ui->newTask->setMinimumHeight(40);
    ui->suggestedList->setMinimumHeight(40);
    ui->synchronize->setMinimumHeight(40);
    ui->suggestedListDisplay->setMaximumWidth(350);

    QVBoxLayout *scrollLayout = new QVBoxLayout(ui->scrollArea);
    //An example of using the tasklist button.
    //*Notice: A new tasklist button should be created after newTask ("Add New Task") button is clicked!
    //*Notice: Remember to add it to the corresponding layout (scrollLayout).
    taskList *newTask = new taskList(ui->scrollArea);
    scrollLayout->addWidget(newTask);
    ui->scrollArea->setLayout(scrollLayout);


//    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
