#include "ParticleEffects.h"

ParticleEffects::ParticleEffects()
{
}

ParticleEffects::~ParticleEffects()
{
}

void ParticleEffects::update(float dt)
{
	//Move particle and count down its duration
	for (size_t i = 0; i < VFX.size(); ++i) {
		VFX[i].circle.move(VFX[i].speed * dt);
		VFX[i].duration -= dt;
	}

	// Remove expired particles
	for (int i = VFX.size() - 1; i >= 0; --i) {
		if (VFX[i].duration <= 0) {
			VFX.erase(VFX.begin() + i); 
		}
	}

	
}

void ParticleEffects::render(sf::RenderWindow& window)
{
	for (auto& particle : VFX)
	{
		window.draw(particle.circle);
	}
}

void ParticleEffects::CreateParticles(sf::Vector2f& position, int numOfParticles)
{

	for (int i = 0; i < numOfParticles; i++)
	{
		Particle particle;
		
		particle.circle.setRadius(2); // Circle Size
		particle.circle.setPosition(position); // Circle position
		particle.circle.setFillColor(sf::Color::White); // Circle Colour
		particle.speed = sf::Vector2f(static_cast<float>(rand() % 100), static_cast<float>(rand() % 100)); // Circle Speed
		particle.duration = 1.f; // Circle lifetime

		VFX.push_back(particle);
	}
}
