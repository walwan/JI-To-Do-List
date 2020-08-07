//A test case for suggestedList.cpp
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
