/*********************************************************************************************************************
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include "task.h"


int main() {
    char taskName[50], taskDescription[100], temp[10];
    int Due[INT_TASK_DUE_SIZE], Priority;
    double timeCost;
    TASK *head = nullptr;

    FILE *fp = fopen("task_local.txt","r");
    if (fp == nullptr)
    {
        std::cout << "Error opening file" << std::endl;
    }

    while(fgets(taskName,50,fp) != nullptr)
    {
        fgets(taskDescription,100,fp);
        for(int & i : Due)
        {
            fscanf(fp, "%d", &i);
        }
        fscanf(fp,"%d",&Priority);
        fscanf(fp,"lf",&timeCost);
        newTask(
                &head,
                taskName,
                strlen(taskName),
                taskDescription,
                strlen(taskDescription),
                Due, Priority,
                timeCost
                );
        fgets(temp,10,fp);
        fgets(temp,10,fp);
    }
    fclose(fp);

    return 0;
}
**********************************************************************************************************************/

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "task.h"

using namespace std;
void listInit(std::vector <Task> &task_list);
//Functions for initializing the to-do list from a .txt file
/*
 * Task::get_ID()
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


int main() {
    vector <Task> task_list;
    listInit(task_list);
    return 0;
}

void listInit(std::vector <Task> &task_list){
    string taskName, taskDescription, temp;
    int Due[5], Priority, timeCost;

    ifstream fp("task_local.txt");
    if (!fp.is_open())
    {
        cout << "Error opening file" << endl;
    }
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
