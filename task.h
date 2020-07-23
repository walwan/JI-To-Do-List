#ifndef TASK_H //Header guard
#define TASK_H

#define INT_TASK_DUE_SIZE 5

class Task{
    public:
        Task(   std::string new_task_name,
                std::string new_task_description,
                int *new_due,
                int new_priority = 0,
                double new_time_cost = 0);
    private:
        std::string task_name;
        std::string task_description;
        int due[INT_TASK_DUE_SIZE];
        int priority;
        //A task should cost less than 1000 minutes
        double time_cost;
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
