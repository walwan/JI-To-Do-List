#include <QApplication>

#include "gui/mainwindow.h"
#include "core/task.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Initialize task_list vector
    vector <Task> task_list;

    //Test code
    int due1[INT_TASK_DATE_SIZE] = {2020, 7, 29, 23, 59};
    int due2[INT_TASK_DATE_SIZE] = {2020, 7, 28, 23, 59};
    int due3[INT_TASK_DATE_SIZE] = {2020, 7, 28, 15, 30};
    new_task(task_list,"Short Writing Assignment", "Write a few sentences to analyze Shakespeare"\
            "in Love", due1, 2, 30);
    new_task(task_list,"Homework 6", "Submit the codes to JOJ corresponding problems.",due2, \
            3, 60);
    new_task(task_list,"Problem Set 10", "20hp1-home10", due3, 5, 180);
    new_task(task_list,"Short Writing Assignment", "Write a few sentences to analyze Shakespeare"\
            "in Love", due1, 2, 30);
    new_task(task_list,"Homework 6", "Submit the codes to JOJ corresponding problems.",due2, \
            3, 60);
    new_task(task_list,"Problem Set 10", "20hp1-home10", due3, 5, 180);
    new_task(task_list,"Short Writing Assignment", "Write a few sentences to analyze Shakespeare"\
            "in Love", due1, 2, 30);
    new_task(task_list,"Homework 6", "Submit the codes to JOJ corresponding problems.",due2, \
            3, 60);
    new_task(task_list,"Problem Set 10", "20hp1-home10", due3, 5, 180);
    //End test code

    QApplication a(argc, argv);
    MainWindow w(task_list);
    w.show();

    return a.exec();
}
