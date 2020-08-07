#ifndef TASK_H //Header guard
#define TASK_H

#include <string>
#include <vector>

//Task attributes default value
#define TASK_DEFAULT_ID 0
#define TASK_DEFAULT_NAME ""
#define TASK_DEFAULT_DESCRIPTION ""
#define TASK_DEFAULT_DATE {0}
#define TASK_DEFAULT_TIME_COST 0
#define TASK_DEFAULT_PRIORITY 0

//Task attributes limits
#define TASK_ID_MAX 9999
#define TASK_ID_MIN 1000

#define INT_TASK_TIME_COST_MIN 0
#define INT_TASK_TIME_COST_MAX 1000

#define INT_TASK_PRIORITY_MIN 0
#define INT_TASK_PRIORITY_MAX 5

//Task date size and index
#define INT_TASK_DATE_SIZE 5
#define INDEX_DATE_MIN 4
#define INDEX_DATE_HOUR 3
#define INDEX_DATE_DAY 2
#define INDEX_DATE_MONTH 1
#define INDEX_DATE_YEAR 0

class Task;

//Global const task_list
extern std::vector <Task> task_list;

//Task class
class Task{
    public:
        //Prototype for constructors
        Task() = default; //Trivial constructor
        Task(   unsigned int new_ID,
                std::string new_task_name,
                std::string new_task_description,
                const int *new_due,
                int new_time_cost,
                int new_priority);

        //Functions for getting task attributes
        unsigned int get_ID() const;
        std::string get_name() const;
        std::string get_description() const;
        const int *get_due() const;
        int get_time_cost() const;
        int get_priority() const;

        //Functions for editing task attributes
        bool edit_name(std::string new_task_name);
        bool edit_description(std::string new_task_description);
        bool edit_due(const int *new_due);
        bool edit_time_cost(int new_time_cost);
        bool edit_priority(int new_priority);

        int *time_subtracter();

private:
        unsigned int ID = TASK_DEFAULT_ID;
        std::string task_name = TASK_DEFAULT_NAME;
        std::string task_description = TASK_DEFAULT_DESCRIPTION;
        int due[INT_TASK_DATE_SIZE] = TASK_DEFAULT_DATE;
        //A task should cost less than INT_TASK_TIME_COST_MAX minutes
        int time_cost = TASK_DEFAULT_TIME_COST;
        int priority = TASK_DEFAULT_PRIORITY;
};

bool is_valid_name(std::string task_name);

bool is_valid_description(std::string task_description);

bool is_valid_date(const int *date);

bool is_valid_time_cost(int time_cost);

bool is_valid_priority(int priority);

int search_task_ID(std::vector <Task> &task_list, unsigned int ID);

unsigned int generate_task_ID(std::vector <Task> &task_list);

unsigned int new_task(  std::vector <Task> &task_list,
                        std::string new_task_name,
                        std::string new_task_description,
                        const int *new_due,
                        int new_time_cost,
                        int new_priority);

bool new_task(  std::vector <Task> &task_list,
                unsigned int new_ID,
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

bool delete_task(std::vector <Task> &task_list, unsigned int ID);

void date_modifier(int *temp);

#endif
