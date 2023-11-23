#include "user.hpp"
#include "task.hpp"

#include <iostream>
#include <string>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#pragma once
#pragma warning( disable : 4996 )

//Instantiating userName, taskCount, taskDetails, taskDate
const int numberOfTasks = 3;
std::vector<Task> taskArray;
int Task::taskCount = 0;
std::string userName;
std::string taskName;
std::string currentUser;
std::vector<std::string> Task::taskDetails = { "Leisure", "Work", "Health" };
time_t now = time(0);
char* dt = ctime(&now);



int main(int argc, char** argv) {

    //Start user process
    User user;
    
    //Get username from user
    std::cout << "\nWhat is your username?\n" << std::endl;
    std::getline(std::cin, currentUser);
    user.setName(currentUser);
    user.processUser();
    // Display User attributes
    std::cout << "\nUser Information:\n";
    std::cout << "Name: " << user.getName() << std::endl;
    //End user process

    //Start task process
    for (int i = 0; i < numberOfTasks; ++i) {
        Task* task = new Task;
        std::string* namePtr = new std::string;
        std::cout << "\nEnter the task name for Task\n" << i + 1 << ": " << std::endl;
        task->setTaskName();
        *namePtr = "Task" + std::to_string(i + 1);


        std::cout << "Enter task detail for Task " << i + 1 << ": " << std::endl;
        task->setTaskDetail();

        task->setTaskDate(dt);

        // Display Task attributes
        std::cout << "\nTask Information for Task " << i + 1 << ":\n" << std::endl;
        task->showTaskDetails();

        // Add the Task object to the array
        taskArray.push_back(*task);
    }

    // Display the quantity of tasks in the array
    int count = Task::getTaskCount();
    std::cout << "Total Quantity of Tasks: " << count << std::endl;

    // Access the Task objects in the array
    for (int i = 0; i < numberOfTasks; ++i) {
        std::cout << "\nTask Information for Task " << i + 1 << ":\n";
        taskArray[i].showTaskDetails();
    }
    return 0;
}
