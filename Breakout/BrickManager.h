#pragma once
#include <vector>
#include "Brick.h"
#include <SFML/Graphics.hpp>
#include "ParticleEffects.h"

class GameManager;

class BrickManager {
public:
    BrickManager(sf::RenderWindow* window, GameManager* gameManager);
    void createBricks(int rows, int cols, float brickWidth, float brickHeight, float spacing);
    void render();

    void update(float dt);  
    int checkCollision(sf::CircleShape& ball, sf::Vector2f& direction);

private:
    std::vector<Brick> _bricks;
    sf::RenderWindow* _window;
    ParticleEffects _particleEffects;

    GameManager* _gameManager;
    static constexpr float TOP_PADDING = 100.0f;
};
