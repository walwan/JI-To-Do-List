#include <iostream>
#include "task.h"

Task::Task( std::string new_task_name,
            std::string new_task_description,
            int *new_due,
            int new_priority,
            double new_time_cost) :
        task_name(new_task_name),
        task_description(new_task_description),
        priority(new_priority),
        time_cost(new_time_cost){
    for (int i = 0; i < INT_TASK_DUE_SIZE; i++) due[i] = new_due[i];
}

/*
bool newTask(
        TASK **head_ref,
        const char *task_name,
        const int task_name_length,
        const char *task_description,
        const int task_description_length,
        const int *due,
        const int priority,
        const double time_cost){
    TASK *newTaskList = new TASK;
//    if (newTaskList == nullptr) return false;

    newTaskList->prev = nullptr;
    newTaskList->next = *head_ref;
    *head_ref = newTaskList;

    return editTask(
            *head_ref,
            task_name,
            task_name_length,
            task_description,
            task_description_length,
            due, priority,
            time_cost);

}

bool editTask(
        TASK *task,
        const char *task_name,
        const int task_name_length,
        const char *task_description,
        const int task_description_length,
        const int *due,
        const int priority,
        const double time_cost){
    if (task == nullptr) return false;

    task->task_name_length = task_name_length;
    int new_task_name_limit = (int) pow(2,(int) (log(task_name_length) / log(2)+1));;
    if (task->task_name_limit != new_task_name_limit)
        task->task_name_limit = new_task_name_limit;

    task->task_description_length = task_description_length;
    int new_task_description_limit = (int) pow(2,(int) (log(task_description_length) / log(2)+1));
    if (task->task_description_limit != new_task_description_limit)
        task->task_description_limit = new_task_description_limit;

    for (int i = 0; i < INT_TASK_DUE_SIZE; i++){
        task->due[i] = due[i];
    }
    task->priority = priority;
    task->time_cost = time_cost;

    return true;
}
*/
