#ifndef TASK_H //Header guard
#define TASK_H

#include <vector>

//Task attributes default value
#define TASK_DEFAULT_ID 0
#define TASK_DEFAULT_NAME ""
#define TASK_DEFAULT_DESCRIPTION ""
#define TASK_DEFAULT_DUE {0}
#define TASK_DEFAULT_TIME_COST 0
#define TASK_DEFAULT_PRIORITY 0

//Task attributes limtis
#define INT_TASK_TIME_COST_MIN 0
#define INT_TASK_TIME_COST_MAX 1000

#define INT_TASK_PRIORITY_MIN 0
#define INT_TASK_PRIORITY_MAX 5

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
                const int *new_due,
                int new_time_cost,
                int new_priority);

        //Functions for getting task attributes
        unsigned int get_ID();
        std::string get_name();
        std::string get_description();
        const int *get_due();
        int get_time_cost();
        int get_priority();

        //Functions for editing task attributes
        bool edit_name(std::string new_task_name);
        bool edit_description(std::string new_task_description);
        bool edit_due(const int *new_due);
        bool edit_time_cost(int new_time_cost);
        bool edit_priority(int new_priority);

        int * time_subtracter();

private:
        unsigned int ID = TASK_DEFAULT_ID;
        std::string task_name = TASK_DEFAULT_NAME;
        std::string task_description = TASK_DEFAULT_DESCRIPTION;
        int due[INT_TASK_DUE_SIZE] = TASK_DEFAULT_DUE;
        //A task should cost less than INT_TASK_TIME_COST_MAX minutes
        int time_cost = TASK_DEFAULT_TIME_COST;
        int priority = TASK_DEFAULT_PRIORITY;
};

unsigned int generate_task_ID(std::vector <Task> &task_list);

//EFFECT: Add a new task,
//If time cost or priority not provided,
//use TASK_DEFAULT_TIME_COST and TASK_DEFAULT_PRIORITY instead
unsigned int new_task(  std::vector <Task> &task_list,
                        std::string new_task_name,
                        std::string new_task_description,
                        const int *new_due,
                        int new_time_cost,
                        int new_priority);

bool edit_task( std::vector <Task> &task_list,
                unsigned int ID,
                std::string new_task_name,
                std::string new_task_description,
                const int *new_due,
                int new_time_cost,
                int new_priority);

bool delete_task( std::vector <Task> &task_list, unsigned int ID);

#endif
