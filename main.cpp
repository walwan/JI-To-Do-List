#include <QApplication>
#include <fstream>

#include "gui/mainwindow.h"
#include "core/task.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Initialize task_list vector
    vector <Task> task_list;

    //Test code
    listInit(task_list);
    listStr(task_list);
    //End test code

    QApplication a(argc, argv);
    MainWindow w(task_list);
    w.show();

    return a.exec();
}
