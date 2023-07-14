
/*Stack: it is a containter that follows a last-in-first-out rule. Meaning that the last element
added to stack is the first one that goes out when calling stack.top(), then you have to call
stack.pop() to delete that top element. stack.push() saves elements into the stack*/

/*Map: it is a container that stores key-value pairs, just as a dictionary in Python. Each unike key
is mapped with a corresponding value.*/




#include "Game.h"

//Initializer functions



//Initializes and sets configuration for window
void Game::initializationWindow()
{
	//Loading window configuration file
	std::ifstream ifs("Config/window.ini.txt");

	std::string title = "NFL Plays";
	sf::VideoMode window_bounds(120*field_ratio, 53.3*field_ratio);
	unsigned framerate_limit = 10;
	bool vertical_sync_enabled = false;

	//if (ifs.is_open())
	//{
	//	std::getline(ifs, title);
	//	ifs >> window_bounds.width >> window_bounds.height;
	//	ifs >> framerate_limit;
	//	ifs >> vertical_sync_enabled;
	//}

	ifs.close();

	//Allocating memory for a new window and setting the pointer to that memory
	this->window = new sf::RenderWindow(window_bounds, title); //Use (->) to acces window object methods
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

//Sets the supported keys for all the game
void Game::initKeys()
{
	//Load supported keys file
	//Configure these files with all the keys supported for the game ('Key' Code)

	std::ifstream ifs("Config/supported_keys.ini.txt");

	if (ifs.is_open())
	{
		std::string key = "";
		int key_value = 0;

		while (ifs >> key >> key_value)
		{
			this->supportedKeys[key] = key_value;
		}
	}
	ifs.close();







}

//Initializes states of the game

void Game::initStates()
{
	/*window doesn't have a "&" because it already stores the memory adress of the new window*/
	/*supportedKeys and states are passed as references to save storage*/
	/*this-> is used to refer to member variables */
	this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states)); 
	
}



//Constructors/Destructors

Game::Game()
{
	this->initializationWindow();
	this->initKeys();

	this->initStates();
}

Game::~Game()
{
	delete this->window;
	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}


}

//Functions


void Game::endApplication()
{
	std::cout << "Ending application" << "\n";

}

void Game::updateDt()
{
	/*Updates the dt variable with the time it takes to update and render one frame*/
	this->dt = this->dtClock.restart().asSeconds();

}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
		

	}
}

void Game::update()
{
	
	this->updateSFMLEvents();

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);
		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}

	}
	//Application end
	else
	{
		this->endApplication();
		this->window->close();
	}

}

void Game::render()
{
	this->window->clear();

	//Render items
	if (!this->states.empty())
		this->states.top()->render();

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		//Updating Dt
		this->updateDt();

		//Everything you want to happen before rendering shapes and objects
		this->update();

		//Rendering objects and shapes
		this->render();

	}
}

