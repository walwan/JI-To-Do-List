#include <iostream>
#include <fstream>
#include "task.h"

using namespace std;
void listStr(std::vector <Task> &task_list);

int main() {
    vector <Task> task_list;
    listStr(task_list);
    return 0;
}

void listStr(std::vector <Task> &task_list){
    ofstream fout("task_local.txt");
    if (!fout.is_open())
    {
        cout << "Error opening file" << endl;
    }
    for (auto & start : task_list)
    {
        cout << start.get_name() << endl;
        cout << start.get_description() << endl;
        cout << start.get_due()[0] << " ";
        cout << start.get_due()[1] << " ";
        cout << start.get_due()[2] << " ";
        cout << start.get_due()[3] << " ";
        cout << start.get_due()[4] << endl;
        cout << start.get_priority() << " ";
        cout << start.get_time_cost() << endl;
        cout << endl;
    }
    fout.close();
}
