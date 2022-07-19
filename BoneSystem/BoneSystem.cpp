#include <iostream>
#include <vector>
#include <map>
#include <memory>

enum MODIFIERS{DEFAULT = 1, LOCKED};

// Bone System
struct Transformation {
    float translation[3]{0.0f,0.0f,0.0f};
    float rotation[3]{0.0f,0.0f,0.0f};
    float scale[3]{1.0f,1.0f,1.0f};

    // Setters
    void SetTranslation(float newTranslation[3]) {
        translation[0] = newTranslation[0];
        translation[1] = newTranslation[1];
        translation[2] = newTranslation[2];
    }
    void SetRotation(float newRotation[3]) {
        rotation[0] = newRotation[0];
        rotation[1] = newRotation[1];
        rotation[2] = newRotation[2];
    }
    void SetScale(float newScale[3]) {
        scale[0] = newScale[0];
        scale[1] = newScale[1];
        scale[2] = newScale[2];
    }
};

void PrintTransformation(float set[3]) {
    std::cout << set[0] << ", " << set[1] << ", " << set[2] << '\n';
}

struct Bone { // Doubly linked list with non linked parent reference
    struct Joint {
        std::string joint_name; // Changes based on parent name, cannot be manually set!
        Transformation joint_transformation;
        Bone * parentBone;
        Bone * connectedBone;
        Joint() {}
        Joint(std::string name) 
            :joint_name(name)
        {
        }
        ~Joint() {}
    };
    std::string bone_name = "";
    Transformation transformation;
    int length = 1; // Change? Incorporate joints distance!
    int modifier{};
    Joint * j1 = nullptr;
    Joint * j2 = nullptr;
    Bone * parent = nullptr;
    Bone * child = nullptr;

    Bone(){}
    Bone(const std::string &name, int l = 1) 
        :bone_name(name), length(l)
    {
        Joint * newFJoint = new Joint(bone_name + "_joint1");
        j1 = newFJoint;
        Joint * newSJoint = new Joint(bone_name + "_joint2");
        j2 = newSJoint;
    }
    Bone(const std::string &name, Transformation &transform, int l = 1) 
    {
        transformation = transform; // Check!
    }
    ~Bone() {}
}; 

struct Skeleton {
    std::string skeletonName = "Default Skeleton";
    std::vector<std::shared_ptr<Bone>> bones{};
    Skeleton() {}
    ~Skeleton() {}
};

void TraverseBoneChain(Bone & b) {
    Bone * traversal_pointer = &b;
    int counter = 0;
    while(traversal_pointer != nullptr) {
        std::cout << counter << ')\n';
        std::cout << b.parent->bone_name << b.bone_name << b.child->bone_name << '\n';
        std::cout << b.j1->joint_name << " | " << b.j2->joint_name << '\n';
        std::cout << std::string(15, '=');
        traversal_pointer = b.child;
        counter++;
    }
}

// Do chain system
std::map<std::string, std::shared_ptr<Bone>> bones{};
int lastBone{}; // Refers to last bone in chain

inline void Clear() {
    bones.clear();
}

void Transform(Bone * b = nullptr) {
    if(b == nullptr)
        return;
    // Traverse bone chain
    Bone* travBone = new Bone;
    travBone = b;
    float newTransform[3] ={0.0f,0.0f,0.0f};
    while(travBone != nullptr) {
        travBone = b->child;
        travBone->transformation.SetTranslation(newTransform);
    }
}

void CreateBone() {
    std::cout << "\n===CREATE BONE===\n";
    std::cout << "\nName bone: "; 
    std::string name = "";
    std::cin >> name;
    /*
    if(bones.size() != 0) {
        auto result = bones.find(name);
        while(result->first != name) {
            std::cin >> name;
        }
    }
    */
    // Bone * newBone = new Bone(name);
    std::shared_ptr<Bone> newBone = std::make_shared<Bone>();
    newBone->bone_name = name;
    std::cout << newBone->bone_name << '\n';
    bones[name] = newBone;
}

void EditBone(Bone * b = nullptr) {
    if(b == nullptr)
        return;
    int input{};
    std::cout << b->bone_name << '\n';
    std::cout << "What would you like to change: ";
    std::cout << "1) Edit name\n";
    std::cout << "2) Change parent\n";
    std::cout << "3) Edit transform\n";
    std::cout << "4) Add modifier\n";
    std::cin >> input;
    while(input < 1 || input > 4)
        std::cin >> input;
    switch(input) {
        case 1: 
            std::cin >> b->bone_name;
            break;
        case 2: {
            
            std::cin >> input;
            break;
        }
        case 3: {
            if(b->modifier == 1)
                EditBone(b);
            std::cout << "==Transform==\n";
            std::cout << "Translation| "; PrintTransformation(b->transformation.translation);
            std::cout << "Rotation| "; PrintTransformation(b->transformation.rotation);
            std::cout << "Scale| "; PrintTransformation(b->transformation.scale);
            Transform(b);
            break;
        }
        case 4: {
            std::cin >> b->modifier;
            while(b->modifier < 1 || b->modifier > 2)
                std::cin >> b->modifier;
            break;
        }
    }
}

void Options() {
    std::cout << "===BONE SYSTEM===\n";
    std::cout << "1) Create Bone\n";
    std::cout << "2) Edit Bone\n";
    std::cout << "3) Delete Bone\n";
    std::cout << "4) Clear\n";
    std::cout << "=================\n";
}

void Interface() {
    int counter{};
    std::string name = "";
    char choice = ' ';
    while(1) {
        system("clear");
        Options();
        if(bones.size() == 0) {
            std::cout << "You must create a bone: ";
            CreateBone();
        }
        std::cin >> choice;
        while(choice < 1 || choice > 4) {
            std::cin >> choice;
            switch (choice) {
                case '1': CreateBone(); break;
                case '2': EditBone(); break;
                case '3': continue; break;
                case '4': Clear(); break;
            }
        }
        /*
        if(bones.size() > 1) {
            std::cout << "Set parent: "; // Make better, graphics can replace this
            std::cin >> name; 
            for(auto it = bones.begin(); it != bones.end(); it++) {
                if(name == it->second->bone_name)
                    bones.end()->second->parent = bones[i]; 
            }
        }
        */
    }
}

int main() {
    Interface();

    return 0;
}
