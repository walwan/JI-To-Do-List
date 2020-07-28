#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

#include "task.h"

void time_modifier(int *temp);
bool is_before(int const *time1, int const *time2);
bool compare_latest_start_date(Task t1, Task t2);
bool compare_priority(const Task& t1, const Task& t2);
std::vector<Task> suggested_list_generator(std::vector<Task> &v);

//Get the latest start date for the user to finish this task
int * Task::time_subtracter(){
    int *temp = new int[INT_TASK_DUE_SIZE];
    for (int i = 0; i < INT_TASK_DUE_SIZE; i++)
        temp[i] = due[i];
    int minutes = time_cost;
    while (minutes >= 60){
        temp[INDEX_DUE_HOUR] -= 1;
        minutes -= 60;
        time_modifier(temp);
    }
    temp[INDEX_DUE_MIN] -= minutes;
    time_modifier(temp);
    return temp;
}

int main(){
    //Test cases
    std::vector<Task> vector1;
    int due1[INT_TASK_DUE_SIZE] = {2020, 7, 29, 23, 59};
    int due2[INT_TASK_DUE_SIZE] = {2020, 7, 28, 23, 59};
    int due3[INT_TASK_DUE_SIZE] = {2020, 7, 28, 15, 30};

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

//Generate a suggested list based on due date, priority and expected time cost
//Input: the address of a vector
//Output: a new vector (a suggested list)
std::vector<Task> suggested_list_generator(std::vector<Task> &v){
    std::vector<Task> result_list1;
    std::vector<Task> result_list2;
    int *temp_latest_start_date = new int[INT_TASK_DUE_SIZE];
    //Obtain the current date
    time_t it = time(NULL);
    struct tm *ptr = localtime(&it);
    int year = ptr->tm_year+1900;
    int month = ptr->tm_mon + 1;
    int day = ptr->tm_mday;
    int hour = ptr->tm_hour;
    int minute = ptr->tm_min;
    //Deal with tasks with latest start dates within one week and the other tasks respectively
    int date_7_days_later[INT_TASK_DUE_SIZE] = {year, month, day + 7, hour, minute};
    for (int i = 0; i < v.size(); i++){
        temp_latest_start_date = v[i].time_subtracter();
        if (is_before(temp_latest_start_date, date_7_days_later))
            result_list1.push_back(v[i]);
        else
            result_list2.push_back(v[i]);
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

//If time1 is before or equal to time2, return true
bool is_before(int const *time1, int const *time2){
    for (int i = 0; i < INT_TASK_DUE_SIZE; i++){
        if (time1[i] < time2[i])
            return true;
        if (time1[i] == time2[i] && i == INT_TASK_DUE_SIZE - 1)
            return true;
    }
    return false;
}

//Modify the date during subtraction
void time_modifier(int *temp){
    if (temp[INDEX_DUE_HOUR] < 0) {
        temp[INDEX_DUE_HOUR] = 23;
        temp[INDEX_DUE_DAY] -= 1;
        if (temp[INDEX_DUE_DAY] == 0 && temp[INDEX_DUE_MONTH] != 1) {
            temp[INDEX_DUE_MONTH] -= 1;
            if (temp[INDEX_DUE_MONTH] == 1 || temp[INDEX_DUE_MONTH] == 3 || temp[INDEX_DUE_MONTH] == 5 || \
                temp[INDEX_DUE_MONTH] == 7 || temp[INDEX_DUE_MONTH] == 8 || temp[INDEX_DUE_MONTH] == 10 || \
                temp[INDEX_DUE_MONTH] == 12)
                temp[INDEX_DUE_DAY] = 31;
            else if (temp[INDEX_DUE_MONTH] == 4 || temp[INDEX_DUE_MONTH] == 6 || temp[INDEX_DUE_MONTH] == 9 || \
                temp[INDEX_DUE_MONTH] == 11)
                temp[INDEX_DUE_DAY] = 30;
            else if (temp[INDEX_DUE_MONTH] == 2 && (temp[INDEX_DUE_YEAR] % 100 != 0 && temp[INDEX_DUE_YEAR] % 4 == 0) \
                || (temp[INDEX_DUE_YEAR] % 400 == 0))
                temp[INDEX_DUE_DAY] = 29;
            else if (temp[INDEX_DUE_MONTH] == 2 && !(temp[INDEX_DUE_YEAR] % 100 != 0 && temp[INDEX_DUE_YEAR] % 4 == 0) \
                || (temp[INDEX_DUE_YEAR] % 400 == 0))
                temp[INDEX_DUE_DAY] = 28;
        }
        else if (temp[INDEX_DUE_DAY] == 0 && temp[INDEX_DUE_MONTH] == 1) {
            temp[INDEX_DUE_MONTH] = 12;
            temp[INDEX_DUE_YEAR] -= 1;
            temp[INDEX_DUE_DAY] = 31;
        }
    }
}


//Compare tasks by the latest start day for the user
bool compare_latest_start_date(Task t1, Task t2){
    int *temp1_latest_start_date = t1.time_subtracter();
    int *temp2_latest_start_date = t2.time_subtracter();
    return is_before(temp1_latest_start_date, temp2_latest_start_date);
}

//Compare tasks by the priority
bool compare_priority(Task const &t1, const Task &t2){
    int temp1_priority = t1.get_priority();
    int temp2_priority = t2.get_priority();
    return temp1_priority < temp2_priority;
}
