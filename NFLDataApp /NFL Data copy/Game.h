#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"
class Game
{
private:
	//Variables


	//Pointer to an instance of the window class
	sf::RenderWindow* window;
	int field_ratio = 10;

	sf::Event sfEvent;
	sf::Clock dtClock;
	float dt;
	

	//Pointer to an instance of the stack class that saves states
	std::stack<State*> states;	
	std::map<std::string, int> supportedKeys;
	

	//Initialization
	void initializationWindow();
	void initStates();
	void initKeys();
	
public:
	

	//Constructors/Destructors
	Game();
	virtual ~Game();

	//Functions
	// Regular
	void endApplication();
	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Core
	void run();
};

#endif
