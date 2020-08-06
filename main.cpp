#include <QApplication>
#include <QDebug>
#include <QString>

#include "gui/mainWindow.h"
#include "core/task.h"
#include "core/file.h"
#include "core/cryptopp.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Password for AES encryption
    pwdHashKey = sha1("TestPWD");

    //Initialize task_list vector
    init_list(task_list);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
