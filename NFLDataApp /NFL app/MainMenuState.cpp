#include "MainMenuState.h"

void MainMenuState::initFiles()
{
	//Textures
	if (!this->mainmenustate_background_tex.loadFromFile("Textures/NFL PLAYS.png"))
	{
		throw("ERROR:MAINMENUSTATE::COULD NOT LOAD TEXTURE");
	}
	if (!this->mainmenustate2_background_tex.loadFromFile("Textures/mainmenustate2_background.jpg"))
	{
		throw("ERROR:MAINMENUSTATE::COULD NOT LOAD TEXTURE");
	}

	
	
	//Fonts
	if (!this->font.loadFromFile("Fonts/ChakraPetch-Bold.ttf"))
	{
		throw("ERROR:MAINMENUSTATE::COULD NOT LOAD FONT");
	}


}

void MainMenuState::initKeybinds()
{
	std::ifstream ifs("Config/mainmenustate_keybinds.ini.txt");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}
	ifs.close();


}

void MainMenuState::initGui()
{
	//Adding year to main menu option
	this->buttons["MENU_STATE_YEAR"] = new gui::Button(195, 150, 150, 50,
		&this->font, "Year", 20,
		sf::Color(255, 255, 255, 150), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50), //text color (idle, hover, active)
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0), //button color
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)); //outline color

	//Select Play
	this->buttons["MENU_STATE_SELECT"] = new gui::Button(195, 200, 150, 50,
		&this->font, "Select Play", 20,
		sf::Color(255, 255, 255, 150), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50), //text color (idle, hover, active)
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0), //button color
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)); //outline color

	//Load Play
	this->buttons["GAME_STATE_LOAD"] = new gui::Button(195, 250, 150, 50,
		&this->font, "Load Play", 20,
		sf::Color(255, 255, 255, 150), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	//Quit the game
	this->buttons["EXIT_STATE"] = new gui::Button(195, 300, 150, 50,
		&this->font, "Quit Game", 20,
		sf::Color(255, 255, 255, 150), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));


		
}


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initFiles();
	this->initKeybinds();
	this->initGui();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setTexture(&this->mainmenustate_background_tex);




	//this->background_sprite.setScale(window->getSize().x / background_sprite.getLocalBounds().width,
	//	window->getSize().y / background_sprite.getLocalBounds().height);
	/*this->background_sprite.setScale(1.875,1.48);*/
	/*this->background_sprite.setTexture(this->mainmenustate2_background_tex);*/

}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second; 
	}

}



void MainMenuState::endState()
{
	std::cout << "Ending MainMenuState!" << "\n";
}


void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuitandStart();
}

void MainMenuState::updateGui(const float& dt)
{
	
	/*Update all the gui elements (butttons, dorpdownlists) in the state and their functionalities*/

	//Buttons
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//Button functionality

	//New game
	if (this->buttons["MENU_STATE_SELECT"]->isPressed())
	{
		this->states->push(new SelectionState(this->window, this->supportedKeys, this->states));
		
	}

	if (this->buttons["GAME_STATE_LOAD"]->isPressed())
	{
		//if (currentGameState)
		//{
		//	this->states->push(currentGameState);
		//	currentGameState = nullptr;
		//}
		
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}

	//Quit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->quit = true;
	}

	

		for (const auto& pair : this->intermedio.GameStateKeysTemporal2) {
			std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
		}

}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateGui(dt);


	
}

void MainMenuState::renderGui(sf::RenderTarget* target)
{

	//Buttons
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}


}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->renderGui(target);




	//View mouse position live (use when needed)
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());
	target->draw(mouseText);

}

	
