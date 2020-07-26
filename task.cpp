#include <iostream>
#include <cstdlib>

#include "task.h"

#define TASK_ID_MAX 9999
#define TASK_ID_MIN 1000

//Task Constructors
Task::Task( unsigned int new_ID,
            std::string new_task_name,
            std::string new_task_description,
            const int *new_due,
            int new_time_cost,
            int new_priority) :
            ID(new_ID),
            task_name(new_task_name),
            task_description(new_task_description),
            time_cost(new_time_cost),
            priority(new_priority){
    for (int i = 0; i < INT_TASK_DUE_SIZE; i++) due[i] = new_due[i];
}

//Functions for getting task attributes

unsigned int Task::get_ID() {return ID;}

std::string Task::get_name() {return task_name;}

std::string Task::get_description() {return task_description;}

const int *Task::get_due() {return due;}

int Task::get_time_cost() {return time_cost;}

int Task::get_priority() {return priority;}

//Functions for editing task attributes

bool Task::edit_name(std::string new_task_name){
    if (new_task_name != ""){
        task_name = new_task_name;
        return true;
    }
    else{
        return false;
    }
}

bool Task::edit_description(std::string new_task_description){
    if (new_task_description != ""){
        task_description = new_task_description;
        return true;
    }
    else{
        return false;
    }
}

bool Task::edit_due(const int *new_due){
    for (int i = 0; i < INT_TASK_DUE_SIZE; i++) due[i] = new_due[i];
}

bool Task::edit_time_cost(int new_time_cost){
    if (new_time_cost > INT_TASK_TIME_COST_MIN && new_time_cost <= INT_TASK_TIME_COST_MAX){
        time_cost = new_time_cost;
        return true;
    }
    else{
        return false;
    }
}

bool Task::edit_priority(int new_priority){
    if (new_priority >= INT_TASK_PRIORITY_MIN && new_priority <= INT_TASK_PRIORITY_MAX){
        priority = new_priority;
        return true;
    }
    else{
        return false;
    }
}

unsigned int generate_task_ID(std::vector <Task> &task_list){
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

unsigned int new_task(  std::vector <Task> &task_list,
                        std::string new_task_name,
                        std::string new_task_description,
                        const int *new_due,
                        int new_time_cost,
                        int new_priority){
    unsigned new_ID = generate_task_ID(task_list);
    task_list.emplace_back( new_ID,
                            new_task_name,
                            new_task_description,
                            new_due,
                            new_time_cost,
                            new_priority);
    return new_ID;
}

bool edit_task( std::vector <Task> &task_list,
                unsigned int ID,
                std::string new_task_name,
                std::string new_task_description,
                const int *new_due,
                int new_time_cost,
                int new_priority){
    if (task_list.empty()) return false;
    for (auto e : task_list){
        if (e.get_ID() == ID){
            e.edit_name(new_task_name);
            e.edit_description(new_task_description);
            e.edit_due(new_due);
            e.edit_time_cost(new_time_cost);
            e.edit_priority(new_priority);
            return true;
        }
    }
    return false;
}

bool delete_task( std::vector <Task> &task_list, unsigned int ID){
    if (task_list.empty()) return false;
    for (auto it = task_list.begin() ; it != task_list.end(); it++){
        if ((*it).get_ID() == ID){
            task_list.erase(it);
            return true;
        }
    }
    return false;
}
