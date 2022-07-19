#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include <array>

// #include "ResourcePath.hpp"
#include "components.h"

#define MOUSE_POS (float)sf::Mouse::getPosition(*win).x, (float)sf::Mouse::getPosition(*win).y

sf::Font font;

// Do labels
// Do matching colours
// Convert to logic gate program!

struct menu {
    sf::RectangleShape m;
    std::vector<sf::Text> options{};
    menu()
    {
        m.setSize(sf::Vector2f(150.0f, 250.0f));
        m.setOrigin(m.getSize().x/2,0.0f);
        
        options.resize(4);
        for(sf::Text t : options) {
            t.setFont(font);
            t.setString("TEST");
        }
    }
};

void gate::draw(sf::RenderWindow & window) const {
    window.draw(rect);
    window.draw(originPoint);
    for(auto i : points)
        window.draw(i.p);
}

std::vector<gate> gates{};
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

std::array<sf::Vertex, 2> CreateConnection(const sf::Vector2f & p1, const sf::Vector2f & p2) {
    std::array<sf::Vertex, 2> newLine;
    newLine[0] = p1;
    newLine[1] = p2;
    return newLine;
}

void TextInput() {
    
}

void PopUp(const float zoomLevel) {
    std::cout << sf::Mouse::getPosition(*win).x << '_' << sf::Mouse::getPosition(*win).y << '\n';
    MENU.m.setSize(sf::Vector2f(200.0f * -zoomLevel, 400.0f * -zoomLevel)); // Fix!
    //sf::Vector2f worldPos = win->mapPixelToCoords(sf::Mouse::getPosition());
    MENU.m.setPosition((float)sf::Mouse::getPosition(*win).x, (float)sf::Mouse::getPosition(*win).y);
    // MENU.m.setOrigin((float)sf::Mouse::getPosition(*win).x + MENU.m.getSize().x/2, (float)sf::Mouse::getPosition(*win).y);
    // Buttons / text
    for(unsigned int i = 0; i < MENU.options.size(); i++) {
        float yOffset = 0.0f;
        MENU.options[i].setPosition(MENU.m.getPosition().x, MENU.m.getPosition().y + yOffset);
        yOffset += MENU.options[i].getLocalBounds().height + 5.0f;
    }
    std::cout << MENU.m.getOrigin().x << '_' << MENU.m.getOrigin().y << '\n';
}

void Setup() {
    // Load font
    if(!font.loadFromFile("Roboto-Light.ttf"))
        std::cerr << "Failed to load font!\n";
}

int main(int, char const**) {
    Setup();
    bool panning = false, hasLine = false, setLine = true, menuActive = false;
    bool hasNode = false;
    bool hightlightMode = false;
    float camX = SCREEN_WIDTH/2, camY = SCREEN_HEIGHT/2;
    float camSpeed = 6.5, zoomLevel = 1.0f;
    point * lastPoint = nullptr;
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "gate");
    std::vector<sf::VertexArray> connectors{};
    std::vector<sf::RectangleShape> highlights{};
    win = &window;
    sf::View cam;
    // sf::ConvexShape activeLine;
    gate * selectedNode = nullptr;
    std::pair<sf::Text, sf::Text> camPos{};
    
    window.setFramerateLimit(30);
    
    cam.setCenter(camX,camY);
    cam.setSize(SCREEN_WIDTH, SCREEN_HEIGHT); // Pointless?
    cam.zoom(zoomLevel);
    
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    background.setFillColor(sf::Color::White);
    
    gate testgate(AND, 12, 3, 6);
    gate testgate2(OR, 3, 2, 1);
    gates.push_back(testgate);
    gates.push_back(testgate2);
    
    testgate.rect.setPosition(camX, camY);
    
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
                break;
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if(hightlightMode) {
                    sf::RectangleShape newHighlight;
                    highlights.push_back(newHighlight);
                }
                // std::cout << "Mouse: " << sf::Mouse::getPosition(window).x << '|' << sf::Mouse::getPosition(window).y << '\n';
                // Do target position
                // To efficiently check collision:
                /*
                    Narrow down search to each gate
                    Then narrow down to each point
                */
                if(hasNode) {
                    selectedNode->selected = false;
                    hasNode = false;
                    selectedNode->rect.setPosition((float)sf::Mouse::getPosition(*win).x,(float)sf::Mouse::getPosition(*win).y);
                    float xOffset = 0.0f, yOffset = 0.0f;
                    for(unsigned int i = 0; i < selectedNode->points.size(); i++) {
                        selectedNode->points[i].p.setPosition(selectedNode->rect.getPosition().x + selectedNode->rect.getSize().x-POINT_SIZE, selectedNode->rect.getPosition().y+yOffset);
                        yOffset += STEP_SIZE;
                        // xOffset += STEP_SIZE;
                    }
                    continue;
                }
                for(unsigned int i = 0; i < gates.size(); i++) { // Change back to foreach
                    // std::cout << "Rect: " << i.rect.getPosition().x << '|' << i.rect.getPosition().y << '\n';
                    if(mouseCol(gates[i].rect.getPosition(), gates[i].rect.getSize())) {
                        //gates[i].rect.setFillColor(sf::Color::Red);
                        // gates[i].rect.setPosition((float)sf::Mouse::getPosition().x,(float)sf::Mouse::getPosition().y);
                        for(unsigned int j = 0; j < gates[i].points.size(); j++) {
                            if(mouseCol(gates[i].points[j].p.getPosition(), sf::Vector2f(POINT_SIZE, POINT_SIZE)) && !hasLine) {
                                sf::Color newCol;
                                // std::cout << "Color:(" << gates[i].points[j].p.getFillColor().r << ',' << gates[i].points[j].p.getFillColor().g << ',' << gates[i].points[j].p.getFillColor().b << ")\n";
                                newCol.r = gates[i].points[j].p.getFillColor().r+5.0f;
                                newCol.g = gates[i].points[j].p.getFillColor().g+5.0f;
                                newCol.b = gates[i].points[j].p.getFillColor().b+5.0f;
                                gates[i].points[j].p.setFillColor(sf::Color::Green); // Get brightness increase working!
                                // std::cout << "Color:(" << gates[i].points[j].p.getFillColor().r << ',' << gates[i].points[j].p.getFillColor().g << ',' << gates[i].points[j].p.getFillColor().b << ")\n";
                                hasLine = true;
                                lastPoint = &gates[i].points[j];
                                // lastPoint->parent = &gates[i];
                                break;
                            }
                            else if(mouseCol(gates[i].points[j].p.getPosition(), sf::Vector2f(POINT_SIZE, POINT_SIZE)) && hasLine) { // Prevent from connecting to same node!
                                // connectors.push_back(CreateConnection(lastPoint, gates[i].points[j].p.getPosition()));
                                sf::VertexArray newLine(sf::Lines, 2);
                                newLine[0].position.x = lastPoint->p.getPosition().x;
                                newLine[0].position.y = lastPoint->p.getPosition().y;
                                newLine[1].position.x = gates[i].points[j].p.getPosition().x;
                                newLine[1].position.y = gates[i].points[j].p.getPosition().y;
                                gates[i].points[j].connected = true;
                                gates[i].points[j].connection = &newLine;
                                gates[i].isConnected = true;
                                lastPoint->connected = true;
                                lastPoint->connection = &newLine;
                                // lastPoint->parent->isConnected = true;
                                connectors.push_back(newLine);
                                hasLine = false;
                                setLine = true;
                                break;
                            }
                        }
                        if(hasLine || setLine) {
                            setLine = false;
                            break;
                        }
                        gates[i].selected = true;
                        selectedNode = &gates[i];
                        hasNode = true;
                        // hasLine = false;
                        break;
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
            
            // Highlight
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::LControl) {
                if(hightlightMode)
                    hightlightMode = false;
                else
                    hightlightMode = true;
            }
            
            cam.setCenter(camX, camY);
            // std::cout << "X: " << camX << " | Y: " << camY << '\n';
        }
        
        window.clear();
        
        // window.draw(background);
        
        /*
        if(hasLine) {
            activeLine.setPoint(2, sf::Vector2f((float)sf::Mouse::getPosition(*win).x,(float)sf::Mouse::getPosition(*win).y));
            activeLine.setPoint(3, sf::Vector2f((float)sf::Mouse::getPosition(*win).x,(float)sf::Mouse::getPosition(*win).y));
            window.draw(activeLine);
        }
        */
        if(menuActive) {
            window.draw(MENU.m);
        }
        
        for(gate i : gates) {
            if(i.isConnected)
                i.SIGNAL();
            if(i.selected) { // Add pixel conversion
                // i.rect.setOrigin((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y);
                // sf::vector2F pixelPos = sf::Mouse::getPosition(*win);
                i.rect.setPosition((float)sf::Mouse::getPosition(*win).x, (float)sf::Mouse::getPosition(*win).y);
                for(unsigned int j = 0; j < i.points.size(); j++) {
                    i.points[j].p.setPosition(i.rect.getPosition().x + i.rect.getSize().x, i.rect.getPosition().y + i.rect.getSize().y);
                    if(i.points[j].connection != nullptr)
                        // i.points[j].connection[0].operator[](0).position.x = i.points[j].p.getPosition().x;
                        std::cout << i.points[j].name << '\n';
                }
            }
            i.draw(window);
        }
        
        // Draw connectors
        sf::VertexArray lineTest(sf::Lines, 2);
        lineTest[0].position.x = SCREEN_WIDTH / 1.5;
        lineTest[0].position.y = 400.0f;
        lineTest[1].position.x = SCREEN_WIDTH / 2.0;
        lineTest[1].position.y = 400.0f;
        window.draw(lineTest);
        
        for(sf::VertexArray line : connectors) {
            window.draw(line);
        }
        
        for(sf::RectangleShape h : highlights) {
            window.draw(h);
        }
        
        //for(std::array<sf::Vertex, 2> c : connectors) {
          //  window.draw(c, 2, sf::Lines);
        //}
        
        window.display();
    }

    return EXIT_SUCCESS;
}
