#include <iostream>
#include <vector>
#include <ctime>

#include "task.h"
#include "cli.h"

using namespace std;

#define WELCOME_MSG "Welcome to JI To-Do List!\nPlease enter your command.\nType \"help\" for help."

int main(int argc, char **argv){
    //Send welcome message
    cout << WELCOME_MSG << endl;

    //Initialize Task vector
    vector <Task> task_list;
    //Set seed for rand()
    srand((unsigned int) time(nullptr));

    //Get tasks from local files

    //

    return 0;
}

