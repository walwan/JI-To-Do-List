#include "file.h"

#include "cryptopp.h"

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::endl;

#include <string>
using std::string;
using std::stoi;
using std::to_string;

//Functions for initializing the to-do list from a .txt file
/*
 * list_init()
 *
 * EFFECT:
 * Initialize the vector task_list
 *
 * INPUT:
 * None
 *
 * OUTPUT:
 * None
 *
 */
void init_list(std::vector<Task> &task_list){
    ifstream fp("task_local.txt");

    if (fp.is_open()){

        //Get the initial vector for AES decryption
        getline(fp,iv);

        string taskName, taskDescription, temp;
        int Due[INT_TASK_DATE_SIZE], Priority, timeCost;

        while(getline(fp,temp))
        {
            taskName = decrypt(temp, pwdHashKey, iv);

            getline(fp,temp);
            taskDescription = decrypt(temp, pwdHashKey, iv);

            for(int i = 0; i < INT_TASK_DATE_SIZE; ++i)
            {
                fp >> temp;
                temp = decrypt(temp, pwdHashKey, iv);
                Due[i] = stoi(temp);
            }

            fp >> temp;
            Priority = stoi(decrypt(temp, pwdHashKey, iv));

            fp >> temp;
            timeCost = stoi(decrypt(temp, pwdHashKey, iv));

            new_task(task_list,
                     taskName,
                     taskDescription,
                     Due,
                     timeCost,
                     Priority);
            getline(fp,temp);
            getline(fp,temp);
        }
    }
    fp.close();
}

//Functions for storing the to-do list in a .txt file
/*
 * list_store()
 *
 * EFFECT:
 * Saving the to-do list in a .txt file
 *
 * INPUT:
 * The head reference of vector task_list
 *
 * OUTPUT:
 * None
 *
 */
void store_list(std::vector<Task> &task_list){
    if (iv.empty()) iv = randomPool();

    ofstream fout("task_local.txt");

    fout << iv << endl;

    for (auto & start : task_list)
    {
        fout << encrypt(start.get_name(), pwdHashKey, iv) << endl;
        fout << encrypt(start.get_description(), pwdHashKey, iv) << endl;
        fout << encrypt(to_string(start.get_due()[INDEX_DATE_YEAR]), pwdHashKey, iv) << " ";
        fout << encrypt(to_string(start.get_due()[INDEX_DATE_MONTH]), pwdHashKey, iv) << " ";
        fout << encrypt(to_string(start.get_due()[INDEX_DATE_DAY]), pwdHashKey, iv) << " ";
        fout << encrypt(to_string(start.get_due()[INDEX_DATE_HOUR]), pwdHashKey, iv) << " ";
        fout << encrypt(to_string(start.get_due()[INDEX_DATE_MIN]), pwdHashKey, iv) << endl;
        fout << encrypt(to_string(start.get_priority()), pwdHashKey, iv) << " ";
        fout << encrypt(to_string(start.get_time_cost()), pwdHashKey, iv) << endl;
        fout << endl;
    }
    fout.close();
}
