#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include <string.h>
#include <iostream>

class MovingBall : public GameObject {

public:
	//variables
	float speed;
	float acceleration;
	sf::Vector2f target;
	sf::Vector2f direction;


	//functions
	//constructors/deconstructors
	MovingBall();
	~MovingBall();

	void update(float dt, Input* input);
};