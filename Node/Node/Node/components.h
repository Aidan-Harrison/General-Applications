//  Created by Aidan Harrison on 25/05/2022.
//  Copyright © 2022 Aidan Harrison. All rights reserved.

#ifndef components_h
#define components_h

#include <SFML/Graphics.hpp>

#define POINT_SIZE 10.0f
#define STEP_SIZE 35.0f
#define gate_SIZE 100.0f

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

enum flags{GENERIC, VECTOR, RETURN};
enum TYPE{AND, OR, NOT};

struct point {
    std::string name = "Default point";
    sf::CircleShape p;
    sf::VertexArray * connection = nullptr;
    bool connected = false;
    uint8_t flag = GENERIC;
    point() {}
    point(const int _flag)
        :flag(_flag)
    {
    }
    virtual ~point() {}
};

struct signal_generator {
    bool state = false;
    sf::RectangleShape body;
    point output;
    signal_generator()
    {
        body.setSize(sf::Vector2f(25.0f,25.0f));
        body.setOrigin(body.getSize().x/2, body.getSize().y/2);
    }
};

struct display {
    std::vector<sf::Text> digits;
    sf::RectangleShape back;
    point input;
};

struct gate {
    bool selected = false;
    bool isConnected = false;
    uint8_t type = 0;
    sf::RectangleShape rect;
    sf::RectangleShape originPoint;
    int inputC{}, outputC{};
    std::vector<bool> states{};
    std::vector<point> points{};
    gate() {}
    gate(const int type, const int numOfPoints, const int input, const int output) // Compress to just input and output
    {
        states.resize(numOfPoints);
        originPoint.setSize(sf::Vector2f(15.0f,15.0f));
        originPoint.setOrigin(originPoint.getSize().x/2, originPoint.getSize().y/2);
        if(input + output > numOfPoints) {
            std::cerr << "Created a gate with invalid input/output values!\n";
            return;
        }
        else if(input + output < numOfPoints) {
            std::cerr << "Created a gate with invalid input/output values!\n";
        }
        // Improve below
        rect.setSize(sf::Vector2f(gate_SIZE, (POINT_SIZE * std::max(input,output))*2.5)); //+ (STEP_SIZE * std::max(input,output))));
        rect.setOrigin(rect.getPosition().x+(gate_SIZE/2), rect.getPosition().y);
        rect.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        rect.setFillColor(sf::Color::White);
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
    void SIGNAL() {
        switch (type) {
            case AND: {
                if(states[0] && states[1])
                    states[2] = true;
                break;
            }
            case OR: {
                if(states[0] || states[1])
                    states[2] = true;
                break;
            }
            case NOT: {
                if(states[0])
                    states[1] = false;
                else
                    states[1] = true;
                break;
            }
        }
        std::cout << "State: " << '|' << states[0] << " " << '|' << states[1] << " " << '|' << states[2] << '\n';
    }
    
    virtual ~gate() {}
};

#endif
