#pragma warning(disable : 4996)

#include <iostream>
#include "AppFunctions.hpp"
#include <ctime>

using namespace std;

int main()
{
	time_t timetoday;
	time(&timetoday);
	cout << "Today's date : " << asctime(localtime(&timetoday)) << endl;
	return 0;
}