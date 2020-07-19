#ifndef TASK_H //Header guard
#define TASK_H

#define INT_TASK_DUE_SIZE 5

//Use doubly linked list for task storage
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

bool newTask(TASK **, char *, int, char *, int , int *, int, double);

bool editTask(TASK *, char *, int, char *, int , int *, int, double);

#endif