#ifndef JI_TO_DO_LIST_SUGGESTEDLIST_H
#define JI_TO_DO_LIST_SUGGESTEDLIST_H

#include <ctime>
#include <algorithm>

#include "task.h"

bool is_before(int const *time1, int const *time2);

bool compare_latest_start_date(Task t1, Task t2);

bool compare_priority(const Task& t1, const Task& t2);

std::vector<Task> suggested_list_generator(std::vector<Task> &v);

#endif //JI_TO_DO_LIST_SUGGESTEDLIST_H
