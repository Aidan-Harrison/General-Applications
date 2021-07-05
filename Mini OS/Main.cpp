#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <utility>

//Include forwardRef<>?
// Remove Global, convert to namespaces`
// N-Curses? or SMFL?
// MINI OS

using namespace std::filesystem; // Possibly experimental

// Error Handler
template<typename T>
struct ErrorHandler { // Check!
        ErrorHandler() {}
        ~ErrorHandler() {}

        bool fatal = false;
        std::string ERROR_MESSAGE = ""; 

        void PrintError(std::string &&str) const {
            ERROR_MESSAGE.append(str);    
            std::cerr << ERROR_MESSAGE << '\n';
            if(!fatal)
                    exit(1);
            ERROR_MESSAGE.clear();
        }

        void CheckError(T &object) {
             switch(sizeof(object))  {
                     case INT_MAX: PrintError(std::forward<std::string>("INT OVERFLOW")); break;
                     case CHAR_MAX: PrintError(std::forward<std::string>("INT OVERFLOW")); break;
                     default: PrintError("NULL"); break;
             }  
        }
};

// Function Constructors
void FileParser(const std::string &str);
void Login();

// System
namespace SYSTEM {
    ErrorHandler<int, char> *eH;    
    bool accountExist = false; // Store in file
    void AUTO_THREAD_SYSTEM() {
        std::thread *t;
    }

    std::fstream FILE_HANDLER;
    std::sstream STRING_STREAM;

    int SCREEN_WIDTH = 50;
    int SCREEN_HEIGHT = 50;
}

// Parameters
namespace PARAMETERS {
    int MAXFILES = 32; // Can display 16 files total
    int N_INPUT = 0;
    char C_INPUT = ' ';
    int menuWidth, menuHeight;
    char cursor = '/';
}

template<typename T>
struct DumpStorage { // Used for dumping, temp folder
        const std::string storageName = "Dump Storage";
        DumpStorage() {}
        ~DumpStorage() {}
       
        std::vector<T> DUMP_STORAGE{}; 

        void Dump(); // Dumps vector
};

class PFolder {
private:
        PFolder() {}
public:
        std::string folderName = "UserFolder";
        ~PFolder() {}

        std::vector<std::fstream> files{}; // Stores files, convert? 
};

struct user {
        std::string userName = "DefaultUser";
        std::string passWord = "0000";

        PFolder *pF;

        bool PassChecker();
        int index = 0;

        std::string GetUser() const {return userName;}
        std::string GetPass() const {return passWord;}

        void PersonalFiles();
        void DeleteUser(); // Wipes from user.txt

        user() {}
        ~user() {}
};

// Loads OS
void Loader() {
    FileParser("OS.txt"); // 'OS.txt' Contains main data
    DumpStorage<std::fstream> *dS; // Check!
    
    // Load users from Users.txt    
    
    void Login();
}

void DrawBorder() { // Change to take into account interface
    for(int i = 0; i < SYSTEM::SCREEN_WIDTH; i++) {
            std::cout << std::string("#", i);
            for(int j = 0; j < SYSTEM::SCREEN_HEIGHT; j++) {
                    std::cout << std::string("#", j);
            }
    }
}

void Interface() { // Move to seperate file
    system("cls");
    std::cout << "Navigate\n\t" 
              << "1) FileSearch\t" << "2) User\n";

    DrawBorder;
}

void Login() {
    if(!SYSTEM::accountExist) {
            std::cout << "Create Account\n\t";
            std::cout << "Enter Username: ";
            std::cout << "Enter Password: ";
    }
    std::cout << "Username: ";
    std::cout << "Password: ";
}

void FileParser(const std::string &str) {
    if(!SYSTEM::FILE_HANDLER.open(str)) // Fix
           SYSTEM::eH->PrintError("OS ERROR: Failed to open"); // Append!
}

void FileSearcher(const std::string &&str) {
        switch(PARAMETERS::N_INPUT) {
                case 0: break; // Search DUMP
                case 1: break; // Search User Personal
                case 2: Interface(); break;  
        }
}

int main() {
    std::thread loadThread(Loader); // Replace with custom auto thread function
    std::cout << "Loading...\n";
       
    loadThread.join();
    return 0;
}
