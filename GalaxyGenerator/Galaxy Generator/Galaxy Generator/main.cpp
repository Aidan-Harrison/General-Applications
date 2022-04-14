#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

// Create octree system
// Generate each quadrant
    // Write directly to texture, swap from capture
// Merge stars which are too close together
// Cull quadrant when needed
// LOD quadrant on zoom out
// LOD on storage

unsigned int screenWidth = 1920, screenHeight = 1080;
sf::Color starColours[5] = {sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Cyan, sf::Color::White};

inline const float Random(float start, float end) { return rand() % (int)end; }

struct galaxy {
    struct quadrant {
        float pos[2] = {950.0f,500.0f};
        float bounds[2] = {100.0f,100.0f};
        std::vector<std::pair<int,int>> starPositions{};
        std::vector<sf::RectangleShape> tempStars{};
        sf::Texture capture;
        sf::Sprite render;
        sf::RectangleShape b_Visual;
        bool culled = false;
        quadrant()
        {
            capture.create(screenWidth, screenHeight);
            b_Visual.setSize(sf::Vector2f(bounds[0], bounds[1]));
            b_Visual.setOrigin(b_Visual.getSize().x/2, b_Visual.getSize().y/2);
        }
        void DRAW(sf::RenderWindow & win) const {
            for(int i = 0; i < tempStars.size(); i++)
                win.draw(tempStars[i]);
        }
        void CLEAR() {
            tempStars.clear();
        }
    };
    std::vector<quadrant*> tree{};
    galaxy(const int x)
    {
        for(int i = 0; i < x; i++) {
            quadrant * newQuadrant = new quadrant;
            tree.push_back(newQuadrant);
        }
    }
};

void Generate(galaxy & g, sf::RenderWindow & win) {
    for(unsigned int i = 0; i < g.tree.size(); i++) {
        g.tree[i]->pos[0] = rand() % screenWidth;
        g.tree[i]->pos[1] = rand() % screenHeight;
        for(int j = 0; j < 800; j++) { // Star generation
            sf::RectangleShape newStar;
            float r_resX = g.tree[i]->pos[0] + g.tree[i]->bounds[0];
            float l_resX = g.tree[i]->pos[0] - g.tree[i]->bounds[0];
            float d_resY = g.tree[i]->pos[1] + g.tree[i]->bounds[1];
            float u_resY = g.tree[i]->pos[1] - g.tree[i]->bounds[1];
            float x = Random(l_resX, r_resX);
            float y = Random(u_resY, d_resY);
            //g.tree[i]->starPositions.push_back({x,y});
            newStar.setSize(sf::Vector2f(12.0f,12.0f));
            newStar.setOrigin(newStar.getSize().x/2, newStar.getSize().y/2);
            newStar.setPosition(sf::Vector2f(x,y));
            x = rand() % 5;
            newStar.setFillColor(starColours[(int)x]);
            g.tree[i]->b_Visual.setPosition(g.tree[i]->pos[0],g.tree[i]->pos[1]);
            g.tree[i]->tempStars.push_back(newStar);
            g.tree[i]->starPositions.push_back({x,y});
        }
        g.tree[i]->DRAW(win);
        g.tree[i]->capture.update(win, screenWidth, screenHeight); // Only capture quadrant!!!, set to quad bounds!!! | DO!
        g.tree[i]->render.setTexture(g.tree[i]->capture);
        g.tree[i]->CLEAR();
    }
}

// If view zoomes in on a single star, replace with solar system
void SolarSystem() {
    
}

void Search() {
    
}

int main(int, char const**) {
    galaxy newGalaxy(3);
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Galaxy Generator");
    sf::View cam;
    window.setFramerateLimit(12);
    
    Generate(newGalaxy, window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        //window.clear();
        // Fix flicker
        //for(int i = 0; i < newGalaxy.tree.size(); i++) {
            //window.draw(newGalaxy.tree[i]->render);
        // window.draw(newGalaxy.tree[0]->b_Visual);
        //}
        
        window.display();
    }

    return EXIT_SUCCESS;
}
