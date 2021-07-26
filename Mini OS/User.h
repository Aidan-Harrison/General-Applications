#ifndef User_h
#define User_h

#include <iostream>
#include <cassert>

#include "SYSTEM.h"

struct user { // HEAP allocate
    std::string username = "";
    std::string password = "";

    PFolder *pF;

    user() {}
    user(const std::string &&name, const std::string &&pass) 
        :username(name), password(pass)
    {
        assert(password.length() > 3 && username.length() <= 20);
    }

    inline std::string GetName() const { return username; }
    void DeleteUser();
    void SearchFolder();
    void ChangeDetails();

    ~user() {}
};

void user::DeleteUser() {
    // Confirmation
    int attempts = 0;
    std::string confirm = "";
    std::cout << "Enter your username (Enter ^^ to back out)\n\t";
    std::cin >> confirm;
    if(confirm == "^^")
        return;
    while(confirm != username) {
        std::cout << "You have failed to match names | Attempts left: " << attempts;
        attempts++;
        if(attempts > 3)
            return;
    }
    attempts = 0;
    std::cout << "Enter your password (Enter ^^ to back out)\n\t";
    std::cin >> confirm;
    if(confirm == "^^")
        return;
    while(confirm != password) {
        std::cout << "You have failed to match names | Attempts left: " << attempts;
        attempts++;
        if(attempts > 3)
            return;
    }
    delete this; // Check! | Won't work
    // Remove from .txt file
}

void user::SearchFolder() { // Seperate from keyboard handler parsing
    std::string name = "";
    std::cin >> name;
    // Do fast search!
}

void user::ChangeDetails() { // Write to USERS.txt
    std::fstream fileHandler;
    fileHandler.open("USERS.txt");
    if(fileHandler.fail()) {
        std::cerr << "Failed to open 'USERS.txt'!\n";
        std::cin.get();
        std::cin.get();
        return;
    }
    else {
        
    }
}

#endif