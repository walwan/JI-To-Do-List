#include <QApplication>

#include "gui/mainWindow.h"
#include "core/task.h"
#include "core/file.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Initialize task_list vector
    init_list(task_list);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
