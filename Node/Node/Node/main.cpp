#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>

// #include "ResourcePath.hpp"

#define POINT_SIZE 10.0f
#define STEP_SIZE 35.0f
#define NODE_SIZE 100.0f

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define MOUSE_POS (float)sf::Mouse::getPosition(*win).x, (float)sf::Mouse::getPosition(*win).y

sf::Font font;

// Do labels
// Do matching colours

enum flags{GENERIC, VECTOR, RETURN};

struct node {
    struct point {
        std::string name = "Default point";
        sf::CircleShape p;
        uint8_t flag = GENERIC;
        point() {}
        point(const int _flag)
            :flag(_flag)
        {
        }
        virtual ~point() {}
    };
    bool selected = false;
    sf::RectangleShape rect;
    sf::RectangleShape originPoint;
    std::vector<point> points{};
    node() {}
    node(const int numOfPoints, const int input, const int output)
    {
        originPoint.setSize(sf::Vector2f(15.0f,15.0f));
        originPoint.setOrigin(originPoint.getSize().x/2, originPoint.getSize().y/2);
        if(input + output > numOfPoints) {
            std::cerr << "Created a node with invalid input/output values!\n";
            return;
        }
        else if(input + output < numOfPoints) {
            std::cerr << "Created a node with invalid input/output values!\n";
        }
        // Improve below
        rect.setSize(sf::Vector2f(NODE_SIZE, (POINT_SIZE * std::max(input,output))*2.5)); //+ (STEP_SIZE * std::max(input,output))));
        rect.setOrigin(rect.getPosition().x+(NODE_SIZE/2), rect.getPosition().y);
        rect.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        originPoint.setPosition(rect.getOrigin().x, rect.getOrigin().y);
        originPoint.setFillColor(sf::Color::Red);
        float yOffset = POINT_SIZE + STEP_SIZE;
        points.resize(numOfPoints);
        for(uint8_t i = 0; i < input; i++) {
            points[i].p.setRadius(POINT_SIZE);
            points[i].p.setFillColor(sf::Color::Blue);
            points[i].p.setOrigin(POINT_SIZE/2, POINT_SIZE/2);
            points[i].p.setPosition(rect.getPosition().x-POINT_SIZE, rect.getPosition().y+yOffset);
            yOffset += STEP_SIZE;
        }
        yOffset = 0.0f;
        for(uint8_t i = input; i < output; i++) {
            points[i].p.setRadius(POINT_SIZE);
            points[i].p.setFillColor(sf::Color::Blue);
            points[i].p.setOrigin(POINT_SIZE/2, POINT_SIZE/2);
            points[i].p.setPosition(rect.getPosition().x+rect.getSize().x-POINT_SIZE, rect.getPosition().y+yOffset);
            yOffset += STEP_SIZE;
        }
    }
    void draw(sf::RenderWindow & window) const;
    
    virtual ~node() {}
};

struct menu {
    sf::RectangleShape m;
};

void node::draw(sf::RenderWindow & window) const {
    window.draw(rect);
    window.draw(originPoint);
    for(auto i : points)
        window.draw(i.p);
}

std::vector<node> nodes{};
sf::RenderWindow * win;
menu MENU;

const bool mouseCol(const sf::Vector2f & targetPos, const sf::Vector2f & targetSize) {
    sf::Vector2i mPos = sf::Mouse::getPosition(*win);
    return mPos.x > targetPos.x - targetSize.x && mPos.x < targetPos.x + targetSize.x && mPos.y < targetPos.y + targetSize.y && mPos.y > targetPos.y - targetSize.y;
}

sf::ConvexShape CreateLine(sf::Color col) {
    std::cout << "LINE!\n";
    sf::ConvexShape line;
    line.setPointCount(4);
    line.setFillColor(col);
    return line;
}

void TextInput() {
    
}

void PopUp(const float zoomLevel) {
    std::cout << sf::Mouse::getPosition(*win).x << '_' << sf::Mouse::getPosition(*win).y << '\n';
    MENU.m.setSize(sf::Vector2f(200.0f * -zoomLevel, 400.0f * -zoomLevel)); // Fix!
    sf::Vector2f worldPos = win->mapPixelToCoords(sf::Mouse::getPosition());
    MENU.m.setOrigin(worldPos.x+MENU.m.getSize().x/2, worldPos.y);
    MENU.m.setPosition(worldPos);
    std::cout << MENU.m.getOrigin().x << '_' << MENU.m.getOrigin().y << '\n';
}

int main(int, char const**) {
    bool panning = false, hasLine = false, menuActive = false;
    float camX = SCREEN_WIDTH/2, camY = SCREEN_HEIGHT/2;
    float camSpeed = 6.5, zoomLevel = 1.0f;
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Node");
    win = &window;
    sf::View cam;
    sf::ConvexShape activeLine;
    std::pair<sf::Text, sf::Text> camPos{};
    
    window.setFramerateLimit(30);
    
    cam.setCenter(camX,camY);
    cam.setSize(SCREEN_WIDTH, SCREEN_HEIGHT); // Pointless?
    cam.zoom(zoomLevel);
    
    node testNode(12, 3, 6);
    //node testNode2(10, 4, 6);
    //node testNode3(8, 0, 6);
    nodes.push_back(testNode);
    //nodes.push_back(testNode2);
    //nodes.push_back(testNode3);
    
    testNode.rect.setPosition(camX, camY);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            // Cam movement and mouse input
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) { // Force single input
                if(menuActive)
                    menuActive = false;
                else {
                    PopUp(zoomLevel);
                    menuActive = true;
                }
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                // std::cout << "Mouse: " << sf::Mouse::getPosition(window).x << '|' << sf::Mouse::getPosition(window).y << '\n';
                // Do target position
                // To efficiently check collision:
                /*
                    Narrow down search to each node
                    Then narrow down to each point
                */
                for(unsigned int i = 0; i < nodes.size(); i++) { // Change back to foreach
                    // std::cout << "Rect: " << i.rect.getPosition().x << '|' << i.rect.getPosition().y << '\n';
                    if(mouseCol(nodes[i].rect.getPosition(), nodes[i].rect.getSize())) {
                        //nodes[i].rect.setFillColor(sf::Color::Red);
                        // nodes[i].rect.setPosition((float)sf::Mouse::getPosition().x,(float)sf::Mouse::getPosition().y);
                        nodes[i].selected = true;
                        for(unsigned int j = 0; j < nodes[i].points.size(); j++) {
                            if(mouseCol(nodes[i].points[j].p.getPosition(), sf::Vector2f(POINT_SIZE, POINT_SIZE))) {
                                sf::Color newCol;
                                std::cout << "Color:(" << nodes[i].points[j].p.getFillColor().r << ',' << nodes[i].points[j].p.getFillColor().g << ',' << nodes[i].points[j].p.getFillColor().b << ")\n";
                                newCol.r = nodes[i].points[j].p.getFillColor().r+5.0f;
                                newCol.g = nodes[i].points[j].p.getFillColor().g+5.0f;
                                newCol.b = nodes[i].points[j].p.getFillColor().b+5.0f;
                                nodes[i].points[j].p.setFillColor(sf::Color::Green); // Get brightness increase working!
                                std::cout << "Color:(" << nodes[i].points[j].p.getFillColor().r << ',' << nodes[i].points[j].p.getFillColor().g << ',' << nodes[i].points[j].p.getFillColor().b << ")\n";
                                activeLine = CreateLine(nodes[i].points[j].p.getFillColor());
                            }
                        }
                    }
                }
            }
            // Keyboard input
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
                camX-=camSpeed;
                window.setView(cam);
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
                camX+=camSpeed;
                window.setView(cam);
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
                camY+=camSpeed;
                window.setView(cam);
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W) {
                camY-=camSpeed;
                window.setView(cam);
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
                cam.zoom(zoomLevel-=0.5f);
                window.setView(cam);
            }
            else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
                cam.zoom(zoomLevel+=0.5f);
                window.setView(cam);
            }
            cam.setCenter(camX, camY);
            // std::cout << "X: " << camX << " | Y: " << camY << '\n';
        }
        
        window.clear();
        
        if(hasLine) {
            activeLine.setPoint(2, sf::Vector2f((float)sf::Mouse::getPosition(*win).x,(float)sf::Mouse::getPosition(*win).y));
            activeLine.setPoint(3, sf::Vector2f((float)sf::Mouse::getPosition(*win).x,(float)sf::Mouse::getPosition(*win).y));
            window.draw(activeLine);
        }
        if(menuActive) {
            window.draw(MENU.m);
        }
        
        for(node i : nodes) {
            if(i.selected) {
                // i.rect.setOrigin((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y);
                i.rect.setPosition((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y);
            }
            i.draw(window);
        }
        
        window.display();
    }

    return EXIT_SUCCESS;
}
