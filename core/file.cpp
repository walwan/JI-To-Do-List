#include "file.h"

#include <fstream>
#include <string>

using namespace std;

//Functions for initializing the to-do list from a .txt file
/*
 * list_init()
 *
 * EFFECT:
 * Initialize the vector task_list
 *
 * INPUT:
 * None
 *
 * OUTPUT:
 * None
 *
 */
void init_list(std::vector <Task> &task_list){
    string taskName, taskDescription, temp;
    int Due[5], Priority, timeCost;

    ifstream fp("task_local.txt");
    while(getline(fp,taskName))
    {
        getline(fp,taskDescription);
        for(int & i : Due)
        {
            fp >> i;
        }
        fp >> Priority;
        fp >> timeCost;
        new_task(task_list,
                 taskName,
                 taskDescription,
                 Due, timeCost,
                 Priority);
        getline(fp,temp);
        getline(fp,temp);
    }
    fp.close();
}

//Functions for storing the to-do list in a .txt file
/*
 * list_store()
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
void store_list(std::vector <Task> &task_list){
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
