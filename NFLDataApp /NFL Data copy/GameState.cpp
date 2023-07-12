#include "GameState.h"

void GameState::initKeybinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini.txt");

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

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	//Initialize stuff that you don't need to change every iteration

	this->initFiles();
	this->initKeybinds();
	this->buttonRatio = 0.5;

	this->gamestate_background.setSize(sf::Vector2f(1200, 426.4));
	this->gamestate_background.setPosition(sf::Vector2f(0, 106.6));
	this->gamestate_background.setTexture(&this->gamestate_background_tex);

	this->gamestate_guiBackground.setSize(sf::Vector2f(1200, 106.6));
	this->gamestate_guiBackground.setFillColor(sf::Color(1,63,0,255));

	this->PlayButton.setPointCount(3);
	this->PlayButton.setRadius(10);
	this->PlayButton.setPosition(sf::Vector2f(600.5 + this->MovingPlayGUI, 50));
	this->PlayButton.setRotation(90);

	this->ResumeTide1.setSize(sf::Vector2f(2.5, 20));
	this->ResumeTide1.setPosition(sf::Vector2f(605.5 + this->MovingPlayGUI, 50));

	this->ResumeTide2.setSize(sf::Vector2f(2.5, 20));
	this->ResumeTide2.setPosition(sf::Vector2f(611 + this->MovingPlayGUI, 50));

	this->GameStateButtons["PlayButton"] = new gui::Button(577.5 + this->MovingPlayGUI, 45, 45, 30,
		&this->font, "", 30,
		sf::Color(255, 255, 255, 150), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50), //text color (idle, hover, active)
		sf::Color(70, 70, 70, 100), sf::Color(150, 150, 150, 50), sf::Color(20, 20, 20, 50), //button color (idle, hover, active)
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)); //outline color (idle, hover, active)

	this->IncreaseSpeedButton1.setPointCount(3);
	this->IncreaseSpeedButton1.setRadius(20 * buttonRatio);
	this->IncreaseSpeedButton1.setPosition(sf::Vector2f(657.5 + this->MovingPlayGUI, 50));
	this->IncreaseSpeedButton1.setRotation(90);

	this->IncreaseSpeedButton2.setPointCount(3);
	this->IncreaseSpeedButton2.setRadius(20 * buttonRatio);
	this->IncreaseSpeedButton2.setPosition(sf::Vector2f(680 + this->MovingPlayGUI, 50));
	this->IncreaseSpeedButton2.setRotation(90);

	this->GameStateButtons["ForwardButton"] = new gui::Button(632.5 + this->MovingPlayGUI, 45, 52, 30,
		&this->font, "", 30,
		sf::Color(255, 255, 255, 150), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50), //text color (idle, hover, active)
		sf::Color(70, 70, 70, 100), sf::Color(150, 150, 150, 50), sf::Color(20, 20, 20, 50), //button color (idle, hover, active)
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)); //outline color (idle, hover, active)

	this->DecreaseSpeedButton1.setPointCount(3);
	this->DecreaseSpeedButton1.setRadius(20 * buttonRatio);
	this->DecreaseSpeedButton1.setPosition(sf::Vector2f(522.5 + this->MovingPlayGUI, 70));
	this->DecreaseSpeedButton1.setRotation(-90);

	this->DecreaseSpeedButton2.setPointCount(3);
	this->DecreaseSpeedButton2.setRadius(20 * buttonRatio);
	this->DecreaseSpeedButton2.setPosition(sf::Vector2f(542.5 + this->MovingPlayGUI, 70));
	this->DecreaseSpeedButton2.setRotation(-90);

	this->GameStateButtons["BackwardButton"] = new gui::Button(517.5 + this->MovingPlayGUI, 45, 50, 30,
		&this->font, "", 30,
		sf::Color(255, 255, 255, 150), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50), //text color (idle, hover, active)
		sf::Color(70, 70, 70, 100), sf::Color(150, 150, 150, 50), sf::Color(20, 20, 20, 50), //button color (idle, hover, active)
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)); //outline color (idle, hover, active)

	this->PlayButtonState = 0;

	//Displaying text for game, play, and endzones
	this->DisplayGameText.setFont(font);
	this->DisplayPlayText.setFont(font);
	this->EndZoneTagLeft.setFont(NFLfont);
	this->EndZoneTagRight.setFont(NFLfont);

	this->DisplayGameText.setCharacterSize(12);
	this->DisplayPlayText.setCharacterSize(12);
	this->EndZoneTagLeft.setCharacterSize(20);
	this->EndZoneTagRight.setCharacterSize(20);

	this->DisplayGameText.setPosition(sf::Vector2f(60, 30));
	this->DisplayPlayText.setPosition(sf::Vector2f(60, 60));
	this->EndZoneTagLeft.setPosition(sf::Vector2f(40, 382));
	this->EndZoneTagRight.setPosition(sf::Vector2f(1160, 258));

	this->EndZoneTagLeft.setRotation(-90);
	this->EndZoneTagRight.setRotation(90);

	this->GameStateButtons["ChangePlay"] = new gui::Button(1000, 40, 120, 40,
		&this->font, "Change Play", 16,
		sf::Color(255, 255, 255, 150), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50), //text color (idle, hover, active)
		sf::Color(70, 70, 70, 100), sf::Color(150, 150, 150, 50), sf::Color(20, 20, 20, 50), //button color (idle, hover, active)
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)); //outline color (idle, hover, active)

	//Displating the names of the default game and play
	this->DisplayGameText.setString("Game: Cleveland Browns (CLE) vs Baltimore Ravens (BAL)");
	this->DisplayPlayText.setString("Play: Play 36 - Kickoff");

	this->EndZoneTagLeft.setString("CLEVELAND");
	this->EndZoneTagRight.setString("BALTIMORE");
	this->EndZoneTagLeft.setFillColor(sf::Color(255, 60, 0));
	this->EndZoneTagRight.setFillColor(sf::Color(36, 23, 115));

	

	//Updading texts of play and game selections
	if (intermedio.selection_applied)
	{
		this->GameTextStream << "Game: " << intermedio.GameSelectedGlobal;
		this->PlayTextStream << "Play: " << intermedio.GameStateKeysTemporal22.second;

		this->DisplayGameText.setString(GameTextStream.str());
		this->DisplayPlayText.setString(PlayTextStream.str());

		//Updating endzone tags

		this->EndZoneTagTextLeft = intermedio.toUpperCase(intermedio.global_left_endzone);
		this->EndZoneTagTextRight = intermedio.toUpperCase(intermedio.global_right_endzone);

		this->EndZoneTagLeft.setString(this->EndZoneTagTextLeft);
		this->EndZoneTagRight.setString(this->EndZoneTagTextRight);

		this->EndZoneTagLeft.setFillColor(GetTeamColor(intermedio.global_left_endzone));
		this->EndZoneTagRight.setFillColor(GetTeamColor(intermedio.global_right_endzone));

	}

	cout << endl << "hi" << endl;


}

GameState::~GameState()
{
	auto it = this->GameStateButtons.begin();
	for (it = this->GameStateButtons.begin(); it != this->GameStateButtons.end(); ++it)
	{
		delete it->second;
	}
}

sf::Color GameState::GetTeamColor(std::string& input)
{
	if (input == "Browns")
	{
		return sf::Color(255, 60, 0);
	}
	if (input == "Ravens")
	{
		return sf::Color(26, 25, 95);
	}
	if (input == "Chargers")
	{
		return sf::Color(0, 128, 198);
	}
	if (input == "Dolphins")
	{
		return sf::Color(0, 142, 151);
	}
	if (input == "Bills")
	{
		return sf::Color(0, 51, 141);
	}
	if (input == "Lions")
	{
		return sf::Color(176, 183, 188);
	}
	if (input == "Packers")
	{
		return sf::Color(24, 48, 40);
	}
	if (input == "Jaguars")
	{
		return sf::Color(159, 121, 44);
	}
	if (input == "Texas")
	{
		return sf::Color(191, 87, 0);
	}
	if (input == "Raiders")
	{
		return sf::Color(165, 172, 175);
	}
	if (input == "Kansas City")
	{
		return sf::Color(227, 24, 55);
	}
}

void GameState::endState()
{
	std::cout << "Ending GameState!" << "\n";
}

void GameState::initFiles()
{
	if (!this->gamestate_background_tex.loadFromFile("Textures/football_field.png"))
	{
		throw("ERROR:GAMESTATE::COULD NOT LOAD TEXTURE");
	}

	//Fonts
	if (!this->font.loadFromFile("Fonts/ChakraPetch-Bold.ttf"))
	{
		throw("ERROR:MAINMENUSTATE::COULD NOT LOAD FONT");
	}
	if (!this->NFLfont.loadFromFile("Fonts/Freshman.ttf"))
	{
		throw("ERROR:MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}



void GameState::updateInput(const float& dt)
{
	this->checkForQuitandStart();


	//Update player input
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
	//	this->player.move(dt, -1.f, 0.f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
	//	this->player.move(dt, 1.f, 0.f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
	//	this->player.move(dt, 0.f, -1.f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
	//	this->player.move(dt, 0.f, 1.f);
}

void GameState::update(const float& dt)
{

	this->updateMousePositions();
	this->updateInput(dt);
	this->checkForQuitandStart();

	//Updating Buttons
	for (auto& it : this->GameStateButtons)
	{
		it.second->update(this->mousePosView);
	}

	//Updating Players
	int forward_sign = 1;
	int backward_sign = -1;

	if (this->GameStateButtons["PlayButton"]->isPressed())
	{
		this->PlayButtonState = this->PlayButtonState + 1;
		/*cout << this->PlayButtonState;*/
		
	}

	if (this->PlayButtonState % 2 != 0)
	{
		this->player.update(dt, forward_sign);
	}

	if (this->GameStateButtons["ForwardButton"]->isPressed())
	{
		this->player.update(dt, forward_sign);
	}

	if (this->GameStateButtons["BackwardButton"]->isPressed())
	{
		this->player.update(dt, backward_sign);
	}

	if (this->GameStateButtons["ChangePlay"]->isPressed())
	{
		this->states->push(new PauseMenuState(this->window, this->supportedKeys, this->states));
		this->quit = true;
	}

	

	//Updading texts of play and game selections
	//if (intermedio.selection_applied)
	//{
	//	this->GameTextStream << "Game: " << intermedio.GameSelectedGlobal;
	//	this->PlayTextStream << "Play: " << intermedio.GameStateKeysTemporal22.second;

	//	this->DisplayGameText.setString(GameTextStream.str());
	//	this->DisplayPlayText.setString(PlayTextStream.str());
	//}
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->gamestate_guiBackground);
	target->draw(this->gamestate_background);
	target->draw(this->EndZoneTagLeft);
	target->draw(this->EndZoneTagRight);

	//Rendering Buttons
	for (auto& it : this->GameStateButtons)
	{
		it.second->render(target);
	}

	target->draw(this->PlayButton);
	target->draw(this->ResumeTide1);
	target->draw(this->ResumeTide2);
	target->draw(this->IncreaseSpeedButton1);
	target->draw(this->IncreaseSpeedButton2);
	target->draw(this->DecreaseSpeedButton1);
	target->draw(this->DecreaseSpeedButton2);
	target->draw(this->DisplayGameText);
	target->draw(this->DisplayPlayText);


	//Rendering players
	player.render(target);
	
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
