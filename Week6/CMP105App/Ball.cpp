#include "Ball.h"
#include <string.h>
#include <iostream>


Ball::Ball() {
	scale = 200.f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = false;
}

Ball::~Ball() {}

void Ball::update(float dt) {

	//Apply gravity force, increasing velocity
	//Move shape by this new velocity
	sf::Vector2f pos = velocity * dt + 0.5f * gravity * dt * dt; // ut + 1/2at^2
	velocity += gravity *dt; // v = u + at 
	setPosition(getPosition() + pos);

	//Check if ball is touching floor
	//If ball hits the floor, make it bounce in the opposite direction
	if (getPosition().y > 575) {
		setPosition(getPosition().x, 575); 
		velocity = (-velocity) / 1.2f;
		isJumping = false;
	}
}

void Ball::handleInput(Input* input) {
	if (input->isKeyDown(sf::Keyboard::J)){
		if (!isJumping) {
			velocity = jumpVector;
			isJumping = true;
			std::cout << "JUMP";
		}
	}
	if (input->isMouseRDown()) {
		setPosition(input->getMouseX(), input->getMouseY());
	}
}