#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class ParticleEffects
{
public:

	// Constructor and Deconstructor
	ParticleEffects();
	~ParticleEffects();

	// Functions
	void update(float dt);
	void render(sf::RenderWindow& window);
	void CreateParticles(sf::Vector2f& position, int numOfParticles);

private:

	// Struct for variables for each particle
	struct Particle
	{
		//Variables
		sf::CircleShape circle;	// Particle Shape
		sf::Vector2f speed; // Particle Speed
		float duration; // Particle Lifetime
	};

	std::vector<Particle> VFX;

};

