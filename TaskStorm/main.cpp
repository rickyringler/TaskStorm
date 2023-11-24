#include "user.hpp"
#include "task.hpp"

#include <iostream>
#include <string>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include <windows.h>

#pragma once
#pragma warning( disable : 4996 )

int taskCount = 0;
std::vector<Task> taskArray;
std::string userName;
std::string taskName;
std::string currentUser;
std::string userOption = "1";
std::string titleScreen = "Main Menu";
std::vector<std::string> Task::taskDetails = { "Leisure", "Work", "Health" };
time_t now = time(0);
char* dt = ctime(&now);
std::ofstream taskDatabase;


int main(int argc, char** argv) {

    //Start user process
    for (char& c : titleScreen) {
        Sleep(120);
        std::cout << (c);
    }

    Sleep(200);

    User user;

    std::cout << "\nWhat is your username?\n" << std::endl;
    std::getline(std::cin, currentUser);
    user.setName(currentUser);
    user.processUser();
    std::cout << "\nWelcome back, " << user.getName() << std::endl;
    //End user process

    //Start task process
    while (taskCount == 0)
    {
        std::cout << "How many tasks do you want to create for today?" << std::endl;
        std::cin >> taskCount;
        user.setNumberOfTasks(taskCount);
    }

    for (int i = 0; i < taskCount; ++i) {
        Task* task = new Task;
        std::string* namePtr = new std::string;
        std::cout << "\nEnter the task name for Task\n" << i + 1 << ": " << std::endl;
        task->setTaskName();
        *namePtr = "Task" + std::to_string(i + 1);

        //Enter task information
        std::cout << "Enter task detail for Task " << i + 1 << ": " << std::endl;
        task->setTaskDetail();
        task->setTaskDate(dt);

        // Display Task attributes
        std::cout << "\nTask Information for Task " << i + 1 << ":\n" << std::endl;
        task->showTaskDetails();

        // Add the Task object to the array
        taskArray.push_back(*task);

        taskDatabase.open("taskDatabase.csv");
        taskDatabase << task;
        taskDatabase << "," << dt;
    }


    // Access the Task objects in the array
                         
    std::cout << "Main Menu" << std::endl;
    std::cout << "Press 1 to display tasks." << std::endl;
    std::cout << "Press 2 to end program." << std::endl;

    std::getline(std::cin, userOption);

    if(userOption == "1")
    {
        for (int i = 0; i < taskCount; ++i) {
            std::cout << "\nTask Information for Task " << i + 1 << ":\n";
            taskArray[i].showTaskDetails();
        }
    }

    return 0;
}
