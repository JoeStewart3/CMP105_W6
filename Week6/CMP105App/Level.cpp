#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	Ball.setSize(sf::Vector2f(100, 100));
	Ball.setPosition(600, 300);
	Ball.setFillColor(sf::Color::Red);

	MovingBall.setSize(sf::Vector2f(100, 100));
	MovingBall.setPosition(100, 100);
	MovingBall.setFillColor(sf::Color::Blue);

	AngryBird.setSize(sf::Vector2f(100, 100));
	AngryBird.setPosition(300, 400);
	AngryBird.setFillColor(sf::Color::Green);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	Ball.handleInput(input);
	AngryBird.handleInput(input);
}

// Update game objects
void Level::update(float dt)
{
	Ball.update(dt);
	MovingBall.update(dt, input);
	AngryBird.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(Ball);
	window->draw(MovingBall);
	window->draw(AngryBird);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}