#include <iostream>
#include <array>
#include <vector>

// Bone System
struct Transformation {
    std::array<float, 3> translation{0.0f,0.0f,0.0f};
    std::array<float, 3> rotation{0.0f,0.0f,0.0f};
    std::array<float, 3> scale{1.0f,1.0f,1.0f};

    // Setters
    void SetTranslation(std::array<float, 3> &newTranslation) {
        translation[0] = newTranslation[0];
        translation[1] = newTranslation[1];
        translation[2] = newTranslation[2];
    }
    void SetRotation(std::array<float, 3> &newRotation) {
        rotation[0] = newRotation[0];
        rotation[1] = newRotation[1];
        rotation[2] = newRotation[2];
    }
    void SetScale(std::array<float, 3> &newScale) {
        scale[0] = newScale[0];
        scale[1] = newScale[1];
        scale[2] = newScale[2];
    }
};

struct Bone {
    struct Joint {
        std::string joint_name; // Changes based on parent name, cannot be manually set!
        Transformation joint_transformation;
        Bone * parentBone;
        Bone * connectedBone;
        Joint() {}
        ~Joint() {}
    };
    std::string bone_name;
    Transformation transformation;
    int length = 1; 
    Joint * j1 = nullptr;
    Joint * j2 = nullptr;
    Bone * parent = nullptr;

    Bone(const std::string &name, int l = 1) 
        :bone_name(name), length(l)
    {
        j1->joint_name = bone_name + "_joint1";
        j2->joint_name = bone_name + "_joint2";
    }
    Bone(const std::string &name, Transformation &transform, int l = 1) 
    {
        transformation = transform; // Check!
    }
    ~Bone() {}
}; 

namespace Global {
    std::vector<Bone*> bones{};
}

void Clear() {
    for(unsigned int i = 0; i < Global::bones.size(); i++)
        delete Global::bones[i];
}

void CreateBone() {
    std::cout << "Name bone: "; 
    std::cin >> name;
    while(counter < Global::bones.size()) { // Just do a foor loop, was trying to overcomplicate
        while(name == Global::bones[counter]->bone_name) {
            std::cout << "Invalid name, already exists!";
            std::cin >> name;
        }
        counter++;
    }
    Bone newBone(name);
    Global::bones.push_back(&newBone);
}

void Interface() {
    int counter = 0;
    std::string name = "";
    char choice = ' ';
    while(1) {
        system("clear");
        if(bones.size() == 0) {
            std::cout << "You must create a bone: ";
            CreateBone();
        }
        std::cout << "Create a bone?/t";
        std::cin >> choice;
        char lChoice = std::tolower(choice);
        switch ((lChoice)) {
            case 'y': CreateBone();
            case 'n': continue;
        }
        if(Global::bones.size() > 1) {
            std::cout << "Set parent: "; // Make better, graphics can replace this
            std::cin >> name; 
            for(unsigned int i = 0; i < Global::bones.size(); i++) {
                if(name == Global::bones[i]->bone_name)
                    Global::bones.back()->parent = Global::bones[i];
            }
        }
    }
}

int main() {


    return 0;
}