#ifndef SYSTEM_h
#define SYSTEM_h

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <fstream>

#include "KeyboardHandler.h"

template<typename T>
struct ErrorHandler { // Check!
    ErrorHandler() {}
    ~ErrorHandler() {}

    bool fatal = false;
    std::string ERROR_MESSAGE = "";

    void PrintError(std::string &&str) {
        ERROR_MESSAGE.append(str);
        std::cerr << ERROR_MESSAGE << '\n';
        if(!fatal)
            exit(0);
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

namespace SYSTEM {
    ErrorHandler<int> *eH;
    bool accountExist = false; // Store in file, write over
    // void AUTO_THREAD_SYSTEM();

    std::fstream FILE_HANDLER;
    // std::sstream STRING_STREAM;

    int SCREEN_WIDTH = 49;
    int SCREEN_HEIGHT = 49;

    KEYINPUT KEYBOARD; // Pointer?
}

namespace PARAMETERS {
    int MAXFILES = 31;
    int N_INPUT = -1;
    char C_INPUT = ' ';
    std::string stringInput;
    int menuWidth, menuHeight;
    char cursor = '/';
}

struct File {
    std::string fileName;

    File() {}
    File(const std::string &&name) 
        :fileName(name)
    {
    }

    // Hold file data
    inline std::string GetName() const {return fileName;}
    inline void SetName();

    ~File() {}
};

template<typename T>
class DumpStorage { // Used for dumping, temp folder | Make singleton
private:
public:
    const std::string storageName = "Dump Storage";
    DumpStorage() {}

    std::vector<File*> files; // Check!

    typename std::unordered_map<int, std::vector<File*>> DUMP_STORAGE; // Check!
    void LoadDump();

    void Dump(); // Clears map
    void Sort();

    void Print() const;
    File* Search(const std::string &&str);

    ~DumpStorage() {}
};

class PFolder {
private:
    PFolder() {}
public:
    std::string folderName = "UserFolder";
    std::vector<File*> files{}; // Stores files, convert?

    inline std::string GetName() const {return folderName;}
    inline void SetName();

    ~PFolder() {}
};

#endif