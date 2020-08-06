#include "task.h"

#include <cstdlib>

std::vector<Task> task_list;

/*
 * Task::Task()
 *
 * EFFECT:
 * The ONLY task object constructor WITH arguments
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
 * NOTE:
 * You should NOT directly add an object through this function
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
    for (int i = 0; i < INT_TASK_DATE_SIZE; i++) due[i] = new_due[i];
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
 * const unsigned int ID
 *
 */
unsigned int Task::get_ID() const {return ID;}

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
 * const std::string task_name
 *
 */
std::string Task::get_name() const {return task_name;}

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
 * const std::string task_description
 *
 */
std::string Task::get_description() const {return task_description;}

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
const int *Task::get_due() const {return due;}

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
 * const int time_cost
 *
 */
int Task::get_time_cost() const {return time_cost;}

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
 * const int priority
 *
 */
int Task::get_priority() const {return priority;}

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
 * Always true
 *
 */
bool Task::edit_name(std::string new_task_name){
    task_name = new_task_name;
    return true;
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
 * Always true
 *
 */
bool Task::edit_description(std::string new_task_description){
    task_description = new_task_description;
    return true;
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
 * Always true
 *
 */
bool Task::edit_due(const int *new_due){
    for (int i = 0; i < INT_TASK_DATE_SIZE; i++) due[i] = new_due[i];
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
 * Always true
 *
 */
bool Task::edit_time_cost(int new_time_cost){
    time_cost = new_time_cost;
    return true;
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
 * Always true
 *
 */
bool Task::edit_priority(int new_priority){
    priority = new_priority;
    return true;
}

/*
 * Task::time_subtracter()
 *
 * EFFECT:
 * Get the latest start date for the user to finish this task by subtracting the due date by the expected time cost
 *
 * INPUT:
 * None
 *
 * OUTPUT:
 * int *latest_start_date
 *
 */
int * Task::time_subtracter(){
    int *latest_start_date = new int[INT_TASK_DATE_SIZE];
    for (int i = 0; i < INT_TASK_DATE_SIZE; i++)
        latest_start_date[i] = due[i];
    int minutes = time_cost;
    while (minutes >= 60){
        latest_start_date[INDEX_DATE_HOUR] -= 1;
        minutes -= 60;
        date_modifier(latest_start_date);
    }
    latest_start_date[INDEX_DATE_MIN] -= minutes;
    date_modifier(latest_start_date);
    return latest_start_date;
}

/*
 * date_modifier()
 *
 * EFFECT:
 * Used in Task::time_subtracter()
 * Modify the date when it is invalid during subtraction
 *
 * INPUT:
 * int *date
 *
 * OUTPUT:
 * None
 *
 */
void date_modifier(int *date){
    if (date[INDEX_DATE_HOUR] < 0) {
        date[INDEX_DATE_HOUR] = 23;
        date[INDEX_DATE_DAY] -= 1;
        if (date[INDEX_DATE_DAY] == 0 && date[INDEX_DATE_MONTH] != 1) {
            date[INDEX_DATE_MONTH] -= 1;
            if (date[INDEX_DATE_MONTH] == 1 || date[INDEX_DATE_MONTH] == 3 || date[INDEX_DATE_MONTH] == 5 || \
                date[INDEX_DATE_MONTH] == 7 || date[INDEX_DATE_MONTH] == 8 || date[INDEX_DATE_MONTH] == 10 || \
                date[INDEX_DATE_MONTH] == 12)
                date[INDEX_DATE_DAY] = 31;
            else if (date[INDEX_DATE_MONTH] == 4 || date[INDEX_DATE_MONTH] == 6 || date[INDEX_DATE_MONTH] == 9 || \
                date[INDEX_DATE_MONTH] == 11)
                date[INDEX_DATE_DAY] = 30;
            else if (date[INDEX_DATE_MONTH] == 2 && (date[INDEX_DATE_YEAR] % 100 != 0 && date[INDEX_DATE_YEAR] % 4 == 0) \
                || (date[INDEX_DATE_YEAR] % 400 == 0))
                date[INDEX_DATE_DAY] = 29;
            else if (date[INDEX_DATE_MONTH] == 2 && !(date[INDEX_DATE_YEAR] % 100 != 0 && date[INDEX_DATE_YEAR] % 4 == 0) \
                || (date[INDEX_DATE_YEAR] % 400 == 0))
                date[INDEX_DATE_DAY] = 28;
        }
        else if (date[INDEX_DATE_DAY] == 0 && date[INDEX_DATE_MONTH] == 1) {
            date[INDEX_DATE_MONTH] = 12;
            date[INDEX_DATE_YEAR] -= 1;
            date[INDEX_DATE_DAY] = 31;
        }
    }
}

/*
 * is_valid_name()
 *
 * EFFECT:
 * Check the validity of a potential task name
 *
 * INPUT:
 * std::string task_name
 *
 * OUTPUT:
 * bool is_valid_name
 *
 */
bool is_valid_name(std::string task_name) {return task_name != "";}

/*
 * is_valid_description()
 *
 * EFFECT:
 * Check the validity of a potential task description
 *
 * INPUT:
 * std::string task_description
 *
 * OUTPUT:
 * bool is_valid_description
 *
 */
bool is_valid_description(std::string task_description) {return true;}

/*
 * is_valid_date()
 *
 * EFFECT:
 * Check the validity of a date represented as an array
 *
 * INPUT:
 * const int *date
 *
 * OUTPUT:
 * bool is_valid_date
 *
 */
bool is_valid_date(const int *date){
    bool is_valid_year = date[INDEX_DATE_YEAR] >= 1583;
    if (!is_valid_year) return false;

    bool is_valid_month = date[INDEX_DATE_MONTH] >= 1 && date[INDEX_DATE_MONTH] <= 12;
    if (!is_valid_month) return false;

    int month_max_date;
    if (date[INDEX_DATE_MONTH] == 1 || \
        date[INDEX_DATE_MONTH] == 3 || \
        date[INDEX_DATE_MONTH] == 5 || \
        date[INDEX_DATE_MONTH] == 7 || \
        date[INDEX_DATE_MONTH] == 8 || \
        date[INDEX_DATE_MONTH] == 10 || \
        date[INDEX_DATE_MONTH] == 12){
        month_max_date = 31;
    }
    else if (   date[INDEX_DATE_MONTH] == 4 || \
                date[INDEX_DATE_MONTH] == 6 || \
                date[INDEX_DATE_MONTH] == 9 || \
                date[INDEX_DATE_MONTH] == 11){
        month_max_date = 30;
    }
    else{
        if ((date[INDEX_DATE_YEAR] % 4 == 0 && date[INDEX_DATE_YEAR] % 100 != 0) || \
            date[INDEX_DATE_YEAR] % 400 == 0){
            month_max_date = 29;
        }
        else{
            month_max_date = 28;
        }
    }
    bool is_valid_day = date[INDEX_DATE_DAY] >= 1 && date[INDEX_DATE_DAY] <= month_max_date;
    if (!is_valid_day) return false;

    bool is_valid_hour = date[INDEX_DATE_HOUR] >= 0 && date[INDEX_DATE_HOUR] <= 23;
    if (!is_valid_hour) return false;

    bool is_valid_minute = date[INDEX_DATE_MIN] >= 0 && date[INDEX_DATE_MIN] <= 59;
    return is_valid_minute;

}

/*
 * is_valid_time_cost()
 *
 * EFFECT:
 * Check the validity of a potential task time cost
 * Within INT_TASK_TIME_COST_MIN and INT_TASK_TIME_COST_MAX
 *
 * INPUT:
 * int time_cost
 *
 * OUTPUT:
 * bool is_valid_time_cost
 *
 */
bool is_valid_time_cost(int time_cost){
    return time_cost >= INT_TASK_TIME_COST_MIN && time_cost <= INT_TASK_TIME_COST_MAX;
}

/*
 * is_valid_priority()
 *
 * EFFECT:
 * Check the validity of a potential task priority
 * Within INT_TASK_PRIORITY_MIN and INT_TASK_PRIORITY_MAX
 *
 * INPUT:
 * int priority
 *
 * OUTPUT:
 * bool is_valid_priority
 *
 */
bool is_valid_priority(int priority){
    return priority >= INT_TASK_PRIORITY_MIN && priority <= INT_TASK_PRIORITY_MAX;
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
 *
 * NOTE:
 * You should ALWAYS use this function to search for a task through ID
 *
 */
int search_task_ID(std::vector <Task> &task_list, unsigned int ID){
    for (int i = 0; i < (int) task_list.size(); ++i) if (task_list[i].get_ID() == ID) return i;
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
 * NOTE:
 * You should ALWAYS add tasks through this function
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
 * NOTE:
 * You should ALWAYS add tasks through this function
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
