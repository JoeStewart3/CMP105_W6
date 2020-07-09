#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include <string.h>
#include <iostream>

class AngryBird : public GameObject {

public:

	bool justPressedL;
	float scale;
	sf::Vector2f gravity;
	sf::Vector2f firstMousePos;
	sf::Vector2f finalMousePos;
	sf::Vector2f xyDifference;

	//functions
	//constructors/destructors
	AngryBird();
	~AngryBird();

	void handleInput(Input* input);

	void update(float dt);



};