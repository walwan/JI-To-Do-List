#include <QApplication>
#include <fstream>

#include "gui/mainwindow.h"
#include "core/task.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Initialize task_list vector
    list_init(task_list);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
