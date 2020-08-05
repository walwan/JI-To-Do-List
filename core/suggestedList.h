#ifndef SUGGESTEDLIST_H
#define SUGGESTEDLIST_H

#include "task.h"

bool is_before(int const *time1, int const *time2);

bool compare_latest_start_date(Task t1, Task t2);

bool compare_priority(const Task& t1, const Task& t2);

std::vector<Task> suggested_list_generator(std::vector<Task> &v);

#endif //SUGGESTEDLIST_H
