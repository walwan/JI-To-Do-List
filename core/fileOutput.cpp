#include <iostream>
#include <fstream>
#include "task.h"

using namespace std;
void listStr(std::vector <Task> &task_list);
//Functions for storing the to-do list in a .txt file
/*
 * Task::get_ID()
 *
 * EFFECT:
 * Saving the to-do list in a .txt file
 *
 * INPUT:
 * The head reference of vector task_list
 *
 * OUTPUT:
 * None
 *
 */

int main() {
    vector <Task> task_list;
    listStr(task_list);
    return 0;
}

void listStr(std::vector <Task> &task_list){
    ofstream fout("task_local.txt");
    for (auto & start : task_list)
    {
        fout << start.get_name() << endl;
        fout << start.get_description() << endl;
        fout << start.get_due()[0] << " ";
        fout << start.get_due()[1] << " ";
        fout << start.get_due()[2] << " ";
        fout << start.get_due()[3] << " ";
        fout << start.get_due()[4] << endl;
        fout << start.get_priority() << " ";
        fout << start.get_time_cost() << endl;
        fout << endl;
    }
    fout.close();
}
