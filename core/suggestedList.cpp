#include <iostream>
#include "task.h"
#include "suggestedList.h"

int main(){
    //Test cases
    std::vector<Task> vector1;
    int due1[INT_TASK_DATE_SIZE] = {2020, 7, 29, 23, 59};
    int due2[INT_TASK_DATE_SIZE] = {2020, 7, 28, 23, 59};
    int due3[INT_TASK_DATE_SIZE] = {2020, 7, 28, 15, 30};

    new_task(vector1,"Short Writing Assignment", "Write a few sentences to analyze Shakespeare"\
            "in Love", due1, 2, 30);
    new_task(vector1,"Homework 6", "Submit the codes to JOJ corresponding problems.",due2, \
            3, 60);
    new_task(vector1,"Problem Set 10", "20hp1-home10", due3, 5, 180);
    vector1 = suggested_list_generator(vector1);
    for (int i = 0; i < vector1.size(); i++)
        std::cout << vector1[i].get_name() << ":" << std::endl << "    " << vector1[i].get_description() << std::endl;
    return 0;
}

/*
 * suggested_list_generator()
 *
 * EFFECT:
 * Generate a suggested list based on due date, priority and expected time cost
 *
 * INPUT:
 * std::vector<Task> &task_list
 *
 * OUTPUT:
 * std::vector<Task> result_list1
 *
 */
std::vector<Task> suggested_list_generator(std::vector<Task> &task_list){
    std::vector<Task> result_list1;
    std::vector<Task> result_list2;
    int *temp_latest_start_date = new int[INT_TASK_DATE_SIZE];
    //Obtain the current date
    time_t it = time(NULL);
    struct tm *ptr = localtime(&it);
    int year = ptr->tm_year+1900;
    int month = ptr->tm_mon + 1;
    int day = ptr->tm_mday;
    int hour = ptr->tm_hour;
    int minute = ptr->tm_min;
    //Deal with tasks with latest start dates within one week and the other tasks respectively
    int date_7_days_later[INT_TASK_DATE_SIZE] = {year, month, day + 7, hour, minute};
    for (int i = 0; i < task_list.size(); i++){
        temp_latest_start_date = task_list[i].time_subtracter();
        if (is_before(temp_latest_start_date, date_7_days_later))
            result_list1.push_back(task_list[i]);
        else
            result_list2.push_back(task_list[i]);
    }
    //Sort tasks whose latest start dates are within one week by their latest start dates
    std::sort(result_list1.begin(), result_list1.end(), compare_latest_start_date);
    //Sort the other tasks by priority
    std::sort(result_list2.begin(), result_list2.end(), compare_priority);
    //Merge two vectors
    result_list1.insert(result_list1.end(), result_list2.begin(), result_list2.end());
    delete [] temp_latest_start_date;
    return result_list1;
}

/*
 * is_before()
 *
 * EFFECT:
 * Determine whether a time is before the other time
 *
 * INPUT:
 * int const *time1, int const *time2
 *
 * OUTPUT:
 * bool result_is_before
 * If time1 is before or equal to time2, return true
 * Otherwise, return false
 */
bool is_before(int const *time1, int const *time2){
    for (int i = 0; i < INT_TASK_DATE_SIZE; i++){
        if (time1[i] < time2[i])
            return true;
        if (time1[i] == time2[i] && i == INT_TASK_DATE_SIZE - 1)
            return true;
    }
    return false;
}

/*
 * compare_latest_start_date()
 *
 * EFFECT:
 * Compare tasks by the latest start day for the user to complete the task
 *
 *
 * INPUT:
 * Task t1, Task t2
 *
 * OUTPUT:
 * bool is_more_urgent
 * If task1 has the latest start day closer to today, return true
 * Otherwise, return false
 */
bool compare_latest_start_date(Task t1, Task t2){
    int *temp1_latest_start_date = t1.time_subtracter();
    int *temp2_latest_start_date = t2.time_subtracter();
    return is_before(temp1_latest_start_date, temp2_latest_start_date);
}

/*
 * compare_priority()
 *
 * EFFECT:
 * Compare tasks by the priority
 *
 * INPUT:
 * Task t1, Task t2
 *
 * OUTPUT:
 * bool is_preferred
 * If task1 has the higher priority, return true
 * Otherwise, return false
 */
bool compare_priority(Task const &t1, const Task &t2){
    int temp1_priority = t1.get_priority();
    int temp2_priority = t2.get_priority();
    return temp1_priority < temp2_priority;
}
