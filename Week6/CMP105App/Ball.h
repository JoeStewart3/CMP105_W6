#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include <string.h>
#include <iostream>

class Ball : public GameObject {
public:

	float scale;
	bool isJumping;
	sf::Vector2f jumpVector;
	sf::Vector2f gravity;


	//functions
	//constructor/deconstructor
	Ball();
	~Ball();


	void update(float dt);
	void handleInput(Input* in);
};