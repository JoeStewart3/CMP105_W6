#include "MovingBall.h"

MovingBall::MovingBall() {
	speed = 50.f;
	acceleration = 100.f;
}

MovingBall::~MovingBall() {}

void MovingBall::update(float dt, Input* input) {

	//get mouse position
	target = sf::Vector2f(input->getMouseX(), input->getMouseY());

	//calculate direction
	direction = target - getPosition();
	direction = Vector::normalise(direction);

	//move that direction
	velocity += (direction * acceleration) * dt;
	setPosition(getPosition() + velocity * dt);

	//if object is close enough to target
	if (Vector::magnitude(target - getPosition()) < 10.f) {
		velocity = sf::Vector2f(0, 0);
	}
}