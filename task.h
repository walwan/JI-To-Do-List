#ifndef TASK_H //Header guard
#define TASK_H

#include <vector>

//Task due size and index
#define INT_TASK_DUE_SIZE 5
#define INDEX_DUE_MIN 4
#define INDEX_DUE_HOUR 3
#define INDEX_DUE_DAY 2
#define INDEX_DUE_MONTH 1
#define INDEX_DUE_YEAR 0

//Task class
class Task{
    public:
        //Prototype for constructors
        Task(   unsigned int new_ID,
                std::string new_task_name,
                std::string new_task_description,
                const int *new_due);

        Task(   unsigned int new_ID,
                std::string new_task_name,
                std::string new_task_description,
                const int *new_due,
                int new_priority,
                int new_time_cost);

        //functions for getting task information
        unsigned int get_ID();
        std::string get_name();
        std::string get_description();
        int get_priority() const;

        int * time_subtracter();

private:
        unsigned int ID = 0;
        std::string task_name = "";
        std::string task_description = "";
        int due[INT_TASK_DUE_SIZE] = {0};
        int priority = 0;
        //A task should cost less than 1000 minutes
        int time_cost = 0;
};

unsigned int generateTaskID(std::vector <Task> &task_list);

#endif
