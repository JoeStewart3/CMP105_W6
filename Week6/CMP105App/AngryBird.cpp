#include "AngryBird.h"

AngryBird::AngryBird() {
	justPressedL = false;
	scale = 200.f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	sf::Vector2f firstMousePos = sf::Vector2f(0, 0); //A
	sf::Vector2f finalMousePos = sf::Vector2f(0, 0); //B
	sf::Vector2f xyDifference = sf::Vector2f(0, 0);  //C = B-A
}
AngryBird::~AngryBird() {}

void AngryBird::handleInput(Input* input) {
	//when mouse L is pressed, get that specific coordinate, vector A
	if (justPressedL == false) {
		if (input->isMouseLDown()) {
			firstMousePos.x = input->getMouseX();
			firstMousePos.y = input->getMouseY();
			justPressedL = true;
		}
	}
	if (justPressedL == true) {
		//when mouse L is not pressed, get that second specific coordinate, vector B
		if (input->isMouseLDown() == false) {
			finalMousePos.x = input->getMouseX();
			finalMousePos.y = input->getMouseY();
			justPressedL = false;

			//get the difference in these two coordinates, vector C = B-A
			xyDifference = finalMousePos - firstMousePos; //C = B-A
			//output the drag distance
			std::string xyDifferenceString = std::to_string(xyDifference.x) + ", " + std::to_string(xyDifference.y);
			std::cout << "MOUSE DRAG DISTANCE: " + xyDifferenceString + "\n";

			//launch ball in opposite direction of vector C
			velocity.x += -xyDifference.x * 5;
			velocity.y += -xyDifference.y * 5;
		}
	}
}

void AngryBird::update(float dt) {

	//Apply gravity force, increasing velocity
	//Move shape by this new velocity
	sf::Vector2f pos = velocity * dt + 0.5f * gravity * dt * dt; // ut + 1/2at^2
	velocity += gravity * dt; // v = u + at 
	setPosition(getPosition() + pos);

	//Check if ball is touching floor
	//If ball hits the floor, make it bounce in the opposite direction
	if (getPosition().y > 575) {
		setPosition(getPosition().x, 575);
		velocity.y = (-velocity.y) / 1.2f;
	}
	if (getPosition().y < 0) {
		setPosition(getPosition().x, 0);
		velocity.y = (-velocity.y) / 1.2f;
	}
	if (getPosition().x > 1200) {
		setPosition(1200, getPosition().y);
		velocity.x = (-velocity.x) / 1.2f;
	}
	if (getPosition().x < 0) {
		setPosition(0, getPosition().y);
		velocity.x = (-velocity.x) / 1.2f;
	}
}