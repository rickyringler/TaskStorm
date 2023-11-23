#include "user.hpp"
#include <fstream>

bool User::readUserData(const std::string& fileName) {
    std::ifstream inputFile(fileName);

    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            if (line == name) {
                fileExists = true;
                break;
            }
        }

        inputFile.close();
    }
    else {
        std::cerr << "Unable to open file: " << fileName << std::endl;
    }

    return userExists;
}

void User::displayUserDetails() const {
    if (fileExists) {
        std::cout << "User " << name << " found in the file." << std::endl;
    }
    else {
        std::cout << "User " << name << " not found in the file." << std::endl;
        std::cout << "Would you like to register?" << std::endl;
        std::string registerUserResponse;
        std::cin >> registerUserResponse;
        if(registerUserResponse == "Yes")
        {
            std::ofstream inputFile;
            inputFile.open("users.txt");
            inputFile << name;
            inputFile.close();
            std::cout << "You have been registered. Welcome.";
        }
        else
        {
            std::cout << "Please enter a valid username or contact an administrator." << std::endl;
            exit(0);
        }
    }
}
