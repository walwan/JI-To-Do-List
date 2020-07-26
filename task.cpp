#include <iostream>
#include <cstdlib>

#include "task.h"

#define TASK_ID_MAX 9999
#define TASK_ID_MIN 1000

//Task Constructors
Task::Task( unsigned int new_ID,
            std::string new_task_name,
            std::string new_task_description,
            const int *new_due) :
            ID(new_ID),
            task_name(new_task_name),
            task_description(new_task_description){
    for (int i = 0; i < INT_TASK_DUE_SIZE; i++) due[i] = new_due[i];
}

Task::Task( unsigned int new_ID,
            std::string new_task_name,
            std::string new_task_description,
            const int *new_due,
            int new_priority,
            int new_time_cost) :
            ID(new_ID),
            task_name(new_task_name),
            task_description(new_task_description),
            priority(new_priority),
            time_cost(new_time_cost){
    for (int i = 0; i < INT_TASK_DUE_SIZE; i++) due[i] = new_due[i];
}

unsigned int Task::get_ID() {return ID;}

std::string Task::get_name() {return task_name;}

std::string Task::get_description() {return task_description;}

int Task::get_priority() const {return priority;}


unsigned int generateTaskID(std::vector <Task> &task_list){
    unsigned int new_ID;
    bool hasGenValidID;
    do{
        hasGenValidID = true;
        new_ID = rand() % (TASK_ID_MAX-TASK_ID_MIN+1) + TASK_ID_MIN;
        if (!task_list.empty()){
            for (auto e : task_list){
                if (e.get_ID() == new_ID){
                    hasGenValidID = false;
                    break;
                }
            }
        }
    }while (hasGenValidID == false);

    return new_ID;
}
