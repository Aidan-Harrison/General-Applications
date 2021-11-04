#include "SYSTEM.h"

template<typename T>
void DumpStorage<T>::LoadDump() {
    std::cout << "\tDUMP STORAGE\n";
    for(typename std::unordered_map<int, std::vector<File*>>::iterator it = DUMP_STORAGE.begin(); it != DUMP_STORAGE.end(); it++) {
        for(unsigned int i = 0; i < it->second.size(); i++) {
            std::cout << it->second[i] << '\n';
            std::cout << "----------------------------\n";
        }
    }
}

template<typename T>
void DumpStorage<T>::Sort() {
    // Sort by bytes
    for(typename std::unordered_map<int, std::vector<File*>>::iterator it = DUMP_STORAGE.begin(); it != DUMP_STORAGE.end(); it++) {
        for(unsigned int i = 0; i < i < it->second.size()-1; i++) {
            if(sizeof(it->second[i]) > sizeof(it->second[i+1])) {
                // Sort
                    // - std::sort third parameter?
                std::cout << "Found larger!\n";
            }
        }
        std::sort(it->second.begin(), it->second.end());
    }
}

template<typename T>
void DumpStorage<T>::Print() const {
    std::cout << "--DUMP STORAGE--\n";
    for(typename std::unordered_map<int, std::vector<File*>>::iterator it = DUMP_STORAGE.begin(); it != DUMP_STORAGE.end(); it++) {
        std::cout << sizeof(it->second);
        std::cout << "========================================\n\t";
        for(unsigned int i = 0; i < it->second.size(); i++) 
            std::cout << it->second[i] << " | " << sizeof(it->second[i]) << " | " << &it->second[i] <<"\n";
        std::cout << "========================================\n\n";
    }
    std::cout << "--END--\n";
    // Get keyboard input
    std::cin >> PARAMETERS::C_INPUT;
    SYSTEM::KEYBOARD.Push(PARAMETERS::C_INPUT, true);
    // Search functionallity
for (typename std::unordered_map<int, std::vector<File *>>::iterator it = DUMP_STORAGE.begin(); it != DUMP_STORAGE.end(); it++)}

template<typename T>
void DumpStorage<T>::Dump() { // Check!
    for (typename std::unordered_map<int, std::vector<File *>>::iterator it = DUMP_STORAGE.begin(); it != DUMP_STORAGE.end(); it++)
    {
        for(unsigned int i = 0; i < it->second.size(); i++) {
            delete it->second[i];
        }
        delete it->second;
    }
}

template<typename T>
File* DumpStorage<T>::Search(const std::string &&str) { // Check l/r
    for(std::unordered_map<int, std::vector<File*>>::iterator it; it != DUMP_STORAGE.end(); it++) {
        for(unsigned int i = 0; i < it->second.size(); i++) {
            if(it->second[i]->GetName() == str) {
                putchar('F');
                return it->second[i];
            }
        }
    }
    // Map search instead!?
}