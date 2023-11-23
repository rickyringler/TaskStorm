#ifndef TASK_H
#define TASK_h

#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <stdio.h>

class Task {

private:

    std::string taskName;
    std::string taskDate;
    std::string taskDetail;
    static std::vector<std::string> taskDetails;
    static int taskCount;

public:
  
    Task(const std::string& taskName) : taskName(taskName) 
    { 
        //To increment number of tasks on instantiation of a Task object
        taskCount++; 
    }

    void setTaskName() 
    {
        std::cin >> taskName;
    }

    std::string getTaskName() const 
    {
        //Get the task name
        return taskName;
    }
    void setTaskDate(const std::string& date) 
    {
        //Set the task date
        taskDate = date; 
    }

    std::string getTaskDate() const 
    {
        //Get the task date
        return taskDate;
    }

    void setTaskDetail()
    {
        //Loop the method
        while(true)
        {
            std::cout << "Enter task detail : ";
            std::cin >> taskDetail;

            //Search if taskDetail exists within a vector of valid choices
            auto it = std::find(taskDetails.begin(), taskDetails.end(), taskDetail);

            if (it != taskDetails.end())
            {
                break;
            }
            else
            {
                std::cout << "Invalid task detail." << std::endl;
            }

        }
    }

    std::string getTaskDetail()
    {
        //Get the task detail
        return taskDetail;
    }

    static int getTaskCount()
    {
        //Get number of times Task has been instantiated
        return taskCount;
    }

    void showTaskDetails() const 
    {
        //Output the task attributes
        //Not to be confused with attribute "taskDetail"
        std::cout << "Task Name: " << getTaskName() << std::endl;
        std::cout << "Task Date: " << getTaskDate() << std::endl;
    }

    Task() = default;
};



#endif TASK_H