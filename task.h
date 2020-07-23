#ifndef TASK_H //Header guard
#define TASK_H

#define INT_TASK_DUE_SIZE 5
#define INDEX_DUE_MIN 4
#define INDEX_DUE_HOUR 3
#define INDEX_DUE_DAY 2
#define INDEX_DUE_MONTH 1
#define INDEX_DUE_YEAR 0
class Task{
    public:
        Task(   std::string new_task_name,
                std::string new_task_description,
                int *new_due,
                int new_priority = 0,
                int new_time_cost = 0);
        int * time_subtracter();
        int get_priority() const;
        std::string get_name();
        std::string get_description();
    private:
        std::string task_name;
        std::string task_description;
        int due[INT_TASK_DUE_SIZE];
        int priority;
        //A task should cost less than 1000 minutes
        int time_cost;
};

/*//Use doubly linked list for task storage
typedef struct _TASK{
    char *task_name;
    int task_name_length, task_name_limit;
    char *task_description;
    int task_description_length, task_description_limit;
    int due[INT_TASK_DUE_SIZE];
    int priority;
    double time_cost;
    struct _TASK *prev;
    struct _TASK *next;
}TASK;

bool newTask(
        TASK **head_ref,
        const char *task_name,
        const int task_name_length,
        const char *task_description,
        const int task_description_length,
        const int *due,
        const int priority,
        const double time_cost);

bool editTask(
        TASK *task,
        const char *task_name,
        const int task_name_length,
        const char *task_description,
        const int task_description_length,
        const int *due,
        const int priority,
        const double time_cost);*/

#endif
