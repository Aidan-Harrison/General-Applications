#include <iostream>
#include <map>

std::map<bool, std::string> map{};
std::vector<std::string> alreadyPlayed{};
std::string curSong = "";

struct Queue {
    int front = -1, rear = -1;
    std::string queue[10] = {};

    inline const bool full() const { if(rear == 10 && front == 0) return true; }
    inline const bool empty() const { if(front == -1) return true; }

    void push(std::string song) {
        if(full())
            std::cout << "Queue is full!\n";
        else {
            if(front == -1)
                front++;
            rear++;
            queue[rear] = song;
        }
    }

    std::string pop() {
        if(empty())
            std::cout << "Nothing in queue. Add something\n";
        else {
            std::string song = queue[front];
            queue[front] = "";
            front++;
            return song;
        }
    }
};

// Could also do another vector of already played songs, but that is storage heavy
// Could also do a queue but again, storage expensive

namespace songs {
    std::string tS = "Test Song 1";
    std::string tS2 = "Test Song 2";
    std::string tS3 = "Test Song 3";
    std::string tS4 = "Test Song 4";
    std::string tS5 = "Test Song 5";
    std::vector<std::string> songs{tS,tS2,tS3,tS4,tS5};
}

void Shuffle() {
    std::vector<int> counted{};
    int choice = rand() % map.size();
    for(int i = 0; i < alreadyPlayed.size(); i++) {
        if(songs[choice] == alreadyPlayed[i]) {
            for(int same : counted)
                while(choice == same)
                    choice = rand() % map.size();
        }
    }
    curSong = songs[choice];
    std::cout << songs[choice];
}

void Interface() {
    Queue newQueue;
    Shuffle();
}

void Setup() {
    
}

int main() {
    Setup();
    Interface();

    return 0;
}