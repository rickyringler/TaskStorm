
#ifndef AppFunctions
#define AppFunctions

#include <chrono>
#include <ctime>
#include <string>;

using namespace std;

class task
{
	string task;
	char details[20];
	bool status;
	const string type[4] = { "Work", "Relaxing", "Learning", "Errands" };

public:

    int createTask() 
	{
		cout << "Task name : ";
		cin >> task;
		cout << "Task details : ";
		cin >> details;
		cout << "Task status : ";
		cin >> status;
		cout << "Task type : ";
	}
	void showTask()
	{
		cout << "Show : " << endl;
		cin >>

	}



	
};


#endif
