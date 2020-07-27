#include <iostream>
#include <cstdlib>

#include "task.h"

/*
 * Task::Task()
 *
 * EFFECT:
 * The ONLY task object constructor
 * You should NOT directly add an object through this function
 *
 * INPUT:
 * unsigned int new_ID: The new task ID
 * std::string new_task_name: The new task name
 * std::string new_task_description: The new task description
 * const int *new_due: The pointer pointing to the due array of the new task
 * int new_time_cost: The new task time cost
 * int new_priority: The new task priority
 *
 * OUTPUT:
 * None
 *
 */
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
/*
 * Task::get_ID()
 *
 * EFFECT:
 * Return the ID for a specific task object
 *
 * INPUT:
 * None
 *
 * OUTPUT:
 * unsigned int ID
 *
 */
unsigned int Task::get_ID() {return ID;}

/*
 * Task::get_name()
 *
 * EFFECT:
 * Return the name for a specific task object
 *
 * INPUT:
 * None
 *
 * OUTPUT:
 * std::string task_name
 *
 */
std::string Task::get_name() {return task_name;}

/*
 * Task::get_description()
 *
 * EFFECT:
 * Return the description for a specific task object
 *
 * INPUT:
 * None
 *
 * OUTPUT:
 * std::string task_description
 *
 */
std::string Task::get_description() {return task_description;}

/*
 * Task::get_due()
 *
 * EFFECT:
 * Return the pointer pointing to the due array for a specific task object
 * The returned pointer should NOT be used to modify the due array
 *
 * INPUT:
 * None
 *
 * OUTPUT:
 * const int *due
 *
 */
const int *Task::get_due() {return due;}

/*
 * Task::get_time_cost()
 *
 * EFFECT:
 * Return the time cost for a specific task object
 *
 * INPUT:
 * None
 *
 * OUTPUT:
 * int time_cost
 *
 */
int Task::get_time_cost() {return time_cost;}

/*
 * Task::get_priority()
 *
 * EFFECT:
 * Return the priority for a specific task object
 *
 * INPUT:
 * None
 *
 * OUTPUT:
 * int priority
 *
 */
int Task::get_priority() {return priority;}

//Functions for editing task attributes
/*
 * Task::edit_name()
 *
 * EFFECT:
 * Change the name for a specific task object
 *
 * INPUT:
 * std::string new_task_name
 *
 * OUTPUT:
 * bool is_successful
 * This function will check the validity of the input new_task_name
 * If it's not empty, the task name will be changed
 *
 */
bool Task::edit_name(std::string new_task_name){
    if (new_task_name != ""){
        task_name = new_task_name;
        return true;
    }
    else{
        return false;
    }
}

/*
 * Task::edit_description()
 *
 * EFFECT:
 * Change the description for a specific task object
 *
 * INPUT:
 * std::string new_task_description
 *
 * OUTPUT:
 * bool is_successful
 * This function will check the validity of the input new_task_description
 * If it's not empty, the task description will be changed
 *
 */
bool Task::edit_description(std::string new_task_description){
    if (new_task_description != ""){
        task_description = new_task_description;
        return true;
    }
    else{
        return false;
    }
}

/*
 * Task::edit_due()
 *
 * EFFECT:
 * Change the due for a specific task object
 *
 * INPUT:
 * const int *new_due
 * The array new_due points to should NOT be changed in this function
 *
 * OUTPUT:
 * bool is_successful
 *
 */
bool Task::edit_due(const int *new_due){
    for (int i = 0; i < INT_TASK_DUE_SIZE; i++) due[i] = new_due[i];
    return true;
}

/*
 * Task::edit_time_cost()
 *
 * EFFECT:
 * Change the time cost for a specific task object
 *
 * INPUT:
 * int new_time_cost
 *
 * OUTPUT:
 * bool is_successful
 * This function will check the validity of the input new_time_cost
 * If it's within INT_TASK_TIME_COST_MIN and INT_TASK_TIME_COST_MAX,
 * the task time cost will be changed
 *
 */
bool Task::edit_time_cost(int new_time_cost){
    if (new_time_cost > INT_TASK_TIME_COST_MIN && new_time_cost <= INT_TASK_TIME_COST_MAX){
        time_cost = new_time_cost;
        return true;
    }
    else{
        return false;
    }
}

/*
 * Task::edit_priority()
 *
 * EFFECT:
 * Change the priority for a specific task object
 *
 * INPUT:
 * int new_priority
 *
 * OUTPUT:
 * bool is_successful
 * This function will check the validity of the input new_priority
 * If it's within INT_TASK_PRIORITY_MIN and INT_TASK_PRIORITY_MAX,
 * the task priority will be changed
 *
 */
bool Task::edit_priority(int new_priority){
    if (new_priority >= INT_TASK_PRIORITY_MIN && new_priority <= INT_TASK_PRIORITY_MAX){
        priority = new_priority;
        return true;
    }
    else{
        return false;
    }
}

/*
 * search_task_ID()
 *
 * EFFECT:
 * Search for a task by ID
 *
 * INPUT:
 * std::vector <Task> &task_list: The task list vector
 * unsigned int ID: The ID of the task for search
 *
 * OUTPUT:
 * int task_index
 * If found, return the index of the task in the current order
 * If not found, return -1
 */
int search_task_ID(std::vector <Task> &task_list, unsigned int ID){
    for (int i = 0; i < task_list.size(); i++){
        if (task_list[i].get_ID() == ID) return i;
    }
    return -1;
}

/*
 * generate_task_ID()
 *
 * EFFECT:
 * Generate a new random task ID within TASK_ID_MIN and TASK_ID_MAX
 *
 * INPUT:
 * std::vector <Task> &task_list
 *
 * OUTPUT:
 * unsigned int new_ID
 *
 */
unsigned int generate_task_ID(std::vector <Task> &task_list){
    unsigned int new_ID;
    bool hasGenValidID;
    do{
        hasGenValidID = true;
        new_ID = rand() % (TASK_ID_MAX-TASK_ID_MIN+1) + TASK_ID_MIN;
        if (search_task_ID(task_list, new_ID) != -1) hasGenValidID = false;
    }while (!hasGenValidID);

    return new_ID;
}

/*
 * new_task()
 *
 * EFFECT:
 * Add a new task with specified attributes WITHOUT given task ID
 *
 * INPUT:
 * std::vector <Task> &task_list: The task list vector
 * std::string new_task_name: The new task name
 * std::string new_task_description: The new task description
 * const int *new_due: The pointer pointing to the due array of the new task
 * int new_time_cost: The new task time cost
 * int new_priority: The new task priority
 *
 * OUTPUT:
 * unsigned int new_ID
 *
 */
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

/*
 * new_task()
 *
 * EFFECT:
 * Add a new task with specified attributes WITH given task ID
 *
 * INPUT:
 * std::vector <Task> &task_list: The task list vector
 * unsigned int new_ID: The specified ID for the new task
 * std::string new_task_name: The new task name
 * std::string new_task_description: The new task description
 * const int *new_due: The pointer pointing to the due array of the new task
 * int new_time_cost: The new task time cost
 * int new_priority: The new task priority
 *
 * OUTPUT:
 * bool is_successful
 * If the specified task ID already exists, return false
 * If the addition is successful, return true
 *
 */
bool new_task(  std::vector <Task> &task_list,
                unsigned int new_ID,
                std::string new_task_name,
                std::string new_task_description,
                const int *new_due,
                int new_time_cost,
                int new_priority){
    if (search_task_ID(task_list, new_ID) != -1) return false;
    task_list.emplace_back( new_ID,
                            new_task_name,
                            new_task_description,
                            new_due,
                            new_time_cost,
                            new_priority);
    return true;
}

/*
 * edit_task()
 *
 * EFFECT:
 * Change all (some) attributes of the task specified by ID
 *
 * INPUT:
 * std::vector <Task> &task_list: The task list vector
 * unsigned int ID: The ID of the task for change
 * std::string new_task_name: The new task name
 * std::string new_task_description: The new task description
 * const int *new_due: The pointer pointing to the due array of the new task
 * int new_time_cost: The new task time cost
 * int new_priority: The new task priority
 *
 * OUTPUT:
 * bool is_successful
 * If the specified task does not exist, return false
 * If the change is successful, return true
 *
 */
bool edit_task( std::vector <Task> &task_list,
                unsigned int ID,
                std::string new_task_name,
                std::string new_task_description,
                const int *new_due,
                int new_time_cost,
                int new_priority){
    int index = search_task_ID(task_list, ID);
    if (index == -1) return false;

    task_list[index].edit_name(new_task_name);
    task_list[index].edit_description(new_task_description);
    task_list[index].edit_due(new_due);
    task_list[index].edit_time_cost(new_time_cost);
    task_list[index].edit_priority(new_priority);
    return true;
}

/*
 * delete_task()
 *
 * EFFECT:
 * Delete the task specified by ID
 *
 * INPUT:
 * std::vector <Task> &task_list: The task list vector
 * unsigned int ID: The ID of the task to delete
 *
 * OUTPUT:
 * bool is_successful
 * If the specified task does not exist, return false
 * If the deletion is successful, return true
 *
 */
bool delete_task(std::vector <Task> &task_list, unsigned int ID){
    int index = search_task_ID(task_list, ID);
    if (index == -1) return false;

    task_list.erase(task_list.begin()+index);
    return true;
}
