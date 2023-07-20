#include "PauseMenuState.h"
#include "GameState.h"

void PauseMenuState::initFiles()
{
	//Fonts
	if (!this->font.loadFromFile("Fonts/ChakraPetch-Bold.ttf"))
	{
		throw("ERROR:MAINMENUSTATE::COULD NOT LOAD FONT");
	}

}

void PauseMenuState::initKeybinds()
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

void PauseMenuState::initGui()
{
	//Buttons
	this->buttons1["SELECTION_STATE_APPLY"] = new gui::Button(900, 460, 150, 50,
		&this->font, "Apply", 30,
		sf::Color(255, 255, 255, 150), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50), //text color (idle, hover, active)
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0), //button color
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)); //outline color

	this->buttons1["SELECTION_STATE_BACK"] = new gui::Button(1050, 460, 150, 50,
		&this->font, "Back", 30,
		sf::Color(255, 255, 255, 150), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	//Dropdown Lists

	//Games dropdown list
	
	std::string li[] = {
		"Tampa Bay Buccaneers (TB) vs Dallas Cowboys (DAL)",
		"Atlanta Falcons (ATL) vs Philadelphia Eagles (PHI)",
		"Buffalo Bills (BUF) vs Pittsburgh Steelers (PIT)",
		"Carolina Panthers (CAR) vs New York Jets (NYJ)",
		"Cincinnati Bengals (CIN) vs Minnesota Vikings (MIN)",
		"Detroit Lions (DET) vs San Francisco 49ers (SF)",
		"Houston Texans (HOU) vs Jacksonville Jaguars (JAX)",
		"Indianapolis Colts (IND) vs Seattle Seahawks (SEA)",
		"Tennessee Titans (TEN) vs Arizona Cardinals (ARI)",
		"Washington Commanders (WAS) vs Los Angeles Chargers (LAC)",
		"Kansas City Chiefs (KC) vs Cleveland Browns (CLE)",
		"New England Patriots (NE) vs Miami Dolphins (MIA)",
		"New Orleans Saints (NO) vs Green Bay Packers (GB)",
		"New York Giants (NYG) vs Denver Broncos (DEN)",
		"Los Angeles Rams (LA) vs Chicago Bears (CHI)",
		"Las Vegas Raiders (LV) vs Baltimore Ravens (BAL)",
		"Washington Commanders (WAS) vs New York Giants (NYG)",
		"Carolina Panthers (CAR) vs New Orleans Saints (NO)",
		"Chicago Bears (CHI) vs Cincinnati Bengals (CIN)",
		"Cleveland Browns (CLE) vs Houston Texans (HOU)",
		"Indianapolis Colts (IND) vs Los Angeles Rams (LA)",
		"Jacksonville Jaguars (JAX) vs Denver Broncos (DEN)",
		"Miami Dolphins (MIA) vs Buffalo Bills (BUF)",
		"New York Jets (NYJ) vs New England Patriots (NE)",
		"Philadelphia Eagles (PHI) vs San Francisco 49ers (SF)",
		"Pittsburgh Steelers (PIT) vs Las Vegas Raiders (LV)",
		"Arizona Cardinals (ARI) vs Minnesota Vikings (MIN)",
		"Tampa Bay Buccaneers (TB) vs Atlanta Falcons (ATL)",
		"Los Angeles Chargers (LAC) vs Dallas Cowboys (DAL)",
		"Seattle Seahawks (SEA) vs Tennessee Titans (TEN)",
		"Baltimore Ravens (BAL) vs Kansas City Chiefs (KC)",
		"Green Bay Packers (GB) vs Detroit Lions (DET)",
		"Houston Texans (HOU) vs Carolina Panthers (CAR)",
		"Buffalo Bills (BUF) vs Washington Commanders (WAS)",
		"Cleveland Browns (CLE) vs Chicago Bears (CHI)",
		"Detroit Lions (DET) vs Baltimore Ravens (BAL)",
		"Jacksonville Jaguars (JAX) vs Arizona Cardinals (ARI)",
		"Kansas City Chiefs (KC) vs Los Angeles Chargers (LAC)",
		"New England Patriots (NE) vs New Orleans Saints (NO)",
		"New York Giants (NYG) vs Atlanta Falcons (ATL)",
		"Pittsburgh Steelers (PIT) vs Cincinnati Bengals (CIN)",
		"Tennessee Titans (TEN) vs Indianapolis Colts (IND)",
		"Denver Broncos (DEN) vs New York Jets (NYJ)",
		"Las Vegas Raiders (LV) vs Miami Dolphins (MIA)",
		"Los Angeles Rams (LA) vs Tampa Bay Buccaneers (TB)",
		"Minnesota Vikings (MIN) vs Seattle Seahawks (SEA)",
		"San Francisco 49ers (SF) vs Green Bay Packers (GB)",
		"Dallas Cowboys (DAL) vs Philadelphia Eagles (PHI)",
		"Cincinnati Bengals (CIN) vs Jacksonville Jaguars (JAX)",
		"Atlanta Falcons (ATL) vs Washington Commanders (WAS)",
		"Buffalo Bills (BUF) vs Houston Texans (HOU)",
		"Chicago Bears (CHI) vs Detroit Lions (DET)",
		"Dallas Cowboys (DAL) vs Carolina Panthers (CAR)",
		"Miami Dolphins (MIA) vs Indianapolis Colts (IND)",
		"Minnesota Vikings (MIN) vs Cleveland Browns (CLE)",
		"New Orleans Saints (NO) vs New York Giants (NYG)",
		"New York Jets (NYJ) vs Tennessee Titans (TEN)",
		"Philadelphia Eagles (PHI) vs Kansas City Chiefs (KC)",
		"Los Angeles Rams (LA) vs Arizona Cardinals (ARI)",
		"San Francisco 49ers (SF) vs Seattle Seahawks (SEA)",
		"Denver Broncos (DEN) vs Baltimore Ravens (BAL)",
		"Green Bay Packers (GB) vs Pittsburgh Steelers (PIT)",
		"New England Patriots (NE) vs Tampa Bay Buccaneers (TB)",
		"Los Angeles Chargers (LAC) vs Las Vegas Raiders (LV)",
		"Seattle Seahawks (SEA) vs Los Angeles Rams (LA)",
		"Atlanta Falcons (ATL) vs New York Jets (NYJ)",
		"Carolina Panthers (CAR) vs Philadelphia Eagles (PHI)",
		"Cincinnati Bengals (CIN) vs Green Bay Packers (GB)",
		"Houston Texans (HOU) vs New England Patriots (NE)",
		"Jacksonville Jaguars (JAX) vs Tennessee Titans (TEN)",
		"Minnesota Vikings (MIN) vs Detroit Lions (DET)",
		"Pittsburgh Steelers (PIT) vs Denver Broncos (DEN)",
		"Tampa Bay Buccaneers (TB) vs Miami Dolphins (MIA)",
		"Washington Commanders (WAS) vs New Orleans Saints (NO)",
		"Los Angeles Chargers (LAC) vs Cleveland Browns (CLE)",
		"Las Vegas Raiders (LV) vs Chicago Bears (CHI)",
		"Arizona Cardinals (ARI) vs San Francisco 49ers (SF)",
		"Dallas Cowboys (DAL) vs New York Giants (NYG)",
		"Kansas City Chiefs (KC) vs Buffalo Bills (BUF)",
		"Baltimore Ravens (BAL) vs Indianapolis Colts (IND)",
		"Philadelphia Eagles (PHI) vs Tampa Bay Buccaneers (TB)",
		"Jacksonville Jaguars (JAX) vs Miami Dolphins (MIA)",
		"Baltimore Ravens (BAL) vs Los Angeles Chargers (LAC)",
		"Carolina Panthers (CAR) vs Minnesota Vikings (MIN)",
		"Chicago Bears (CHI) vs Green Bay Packers (GB)",
		"Detroit Lions (DET) vs Cincinnati Bengals (CIN)",
		"Indianapolis Colts (IND) vs Houston Texans (HOU)",
		"New York Giants (NYG) vs Los Angeles Rams (LA)",
		"Washington Commanders (WAS) vs Kansas City Chiefs (KC)",
		"Cleveland Browns (CLE) vs Arizona Cardinals (ARI)",
		"Denver Broncos (DEN) vs Las Vegas Raiders (LV)",
		"New England Patriots (NE) vs Dallas Cowboys (DAL)",
		"Pittsburgh Steelers (PIT) vs Seattle Seahawks (SEA)",
		"Tennessee Titans (TEN) vs Buffalo Bills (BUF)",
		"Baltimore Ravens (BAL) vs Cincinnati Bengals (CIN)",
		"Green Bay Packers (GB) vs Washington Commanders (WAS)",
		"Miami Dolphins (MIA) vs Atlanta Falcons (ATL)",
		"New England Patriots (NE) vs New York Jets (NYJ)",
		"New York Giants (NYG) vs Carolina Panthers (CAR)",
		"Tennessee Titans (TEN) vs Kansas City Chiefs (KC)",
		"Los Angeles Rams (LA) vs Detroit Lions (DET)",
		"Las Vegas Raiders (LV) vs Philadelphia Eagles (PHI)",
		"Arizona Cardinals (ARI) vs Houston Texans (HOU)",
		"Tampa Bay Buccaneers (TB) vs Chicago Bears (CHI)",
		"San Francisco 49ers (SF) vs Indianapolis Colts (IND)",
		"Seattle Seahawks (SEA) vs New Orleans Saints (NO)",
		"Arizona Cardinals (ARI) vs Green Bay Packers (GB)",
		"Atlanta Falcons (ATL) vs Carolina Panthers (CAR)",
		"Buffalo Bills (BUF) vs Miami Dolphins (MIA)",
		"Chicago Bears (CHI) vs San Francisco 49ers (SF)",
		"Cleveland Browns (CLE) vs Pittsburgh Steelers (PIT)",
		"Detroit Lions (DET) vs Philadelphia Eagles (PHI)",
		"Houston Texans (HOU) vs Los Angeles Rams (LA)",
		"Indianapolis Colts (IND) vs Tennessee Titans (TEN)",
		"New York Jets (NYJ) vs Cincinnati Bengals (CIN)",
		"Los Angeles Chargers (LAC) vs New England Patriots (NE)",
		"Seattle Seahawks (SEA) vs Jacksonville Jaguars (JAX)",
		"Denver Broncos (DEN) vs Washington Commanders (WAS)",
		"New Orleans Saints (NO) vs Tampa Bay Buccaneers (TB)",
		"Minnesota Vikings (MIN) vs Dallas Cowboys (DAL)",
		"Kansas City Chiefs (KC) vs New York Giants (NYG)"
		};

	this->games_dropdown = new gui::DropDownList(70, 115, 450, 50, font, li, 6);

	//Dropdown for BAL vs LAC plays
	std::string li2[] = { "Play 1468 - Field Goal", "Play 2898 - Punt", "Play 3184 - Punt", "Play 3802 - Kickoff" };
	this->plays_BALLAC = new gui::DropDownList(600, 115, 300, 50, font, li2, 4);

	//Dropdown for CLE vs BAL plays
	std::string li3[] = { "Play 36 - Kickoff", "Play 373 - Field Goal", "Play 392 - Kickoff", "Play 548 - extra point" };
	this->plays_CLEBAL = new gui::DropDownList(600, 115, 300, 50, font, li3, 4);

	//Dropdown for MIA vs BUF plays
	std::string li4[] = { "Play 36 - Kickoff", "Play 340 - Extra Point", "Play 1106 - Field Goal", "Play 1223 - Punt" };
	this->plays_MIABUF = new gui::DropDownList(600, 115, 300, 50, font, li4, 4);

	//Dropdown for DET vs GB plays
	std::string li5[] = { "Play 36 - Kickoff", "Play 117 - Punt", "Play 467 - Punt", "Play 841 -  Extra Point" };
	this->plays_DETGB = new gui::DropDownList(600, 115, 300, 50, font, li5, 4);

	//Dropdown for JAX vs HOU plays
	std::string li6[] = { "Play 133 - Punt", "Play 228 - Punt", "Play 370 - Field Goal", "Play 393 - Kickoff" };
	this->plays_JAXHOU = new gui::DropDownList(600, 115, 300, 50, font, li6, 4);

	//Dropdown for OAK vs KC plays
	std::string li7[] = { "Play 36 - Kickoff", "Play 227 - Extra Point", "Play 465 - Punt", "Play 2174 - Punt" };
	this->plays_OAKKC = new gui::DropDownList(600, 115, 300, 50, font, li7, 4);
}

PauseMenuState::PauseMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initFiles();
	this->initKeybinds();
	this->initGui();



	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color(41, 165, 0));

}

PauseMenuState::~PauseMenuState()
{
	auto it = this->buttons1.begin();
	for (it = this->buttons1.begin(); it != this->buttons1.end(); ++it)
	{
		delete it->second;
	}

	//auto it2 = this->dropDownLists.begin();
	//for (it2 = this->dropDownLists.begin(); it2 != this->dropDownLists.end(); ++it2)
	//{
	//	delete it2->second;
	//}

	//Deleting allocations for plays dropdwons and games dropdown
	delete this->games_dropdown;
	delete this->plays_BALLAC;
	delete this->plays_CLEBAL;
	delete this->plays_MIABUF;
	delete this->plays_DETGB;
	delete this->plays_JAXHOU;
	delete this->plays_OAKKC;


}

void PauseMenuState::endState()
{
	std::cout << "Ending PauseMenuState!" << "\n";
}

void PauseMenuState::updateInput(const float& dt)
{
	this->checkForQuitandStart();
}

void PauseMenuState::updateGui(const float& dt)
{
	/*Update all the gui elements (butttons, dorpdownlists) in the state and their functionalities*/

	//Updating Buttons
	for (auto& it : this->buttons1)
	{
		it.second->update(this->mousePosView);
	}

	//Go back to main menu
	if (this->buttons1["SELECTION_STATE_BACK"]->isPressed())
	{
		this->quit = true;
		this->gameState = new GameState(this->window, this->supportedKeys, this->states);
		this->states->push(gameState);
	}

	//How to update map of dropdownlists
	//Dropdown lists -----------------------------------
	// 
	//for (auto& it : this->dropDownLists)
	//{
	//	
	//	it.second->update(this->mousePosView, dt);
	//}

	//Updating Game dropdown and plays dropdowns
	this->games_dropdown->update(this->mousePosView, dt);
	this->plays_BALLAC->update(this->mousePosView, dt);
	this->plays_CLEBAL->update(this->mousePosView, dt);
	this->plays_MIABUF->update(this->mousePosView, dt);
	this->plays_DETGB->update(this->mousePosView, dt);
	this->plays_JAXHOU->update(this->mousePosView, dt);
	this->plays_OAKKC->update(this->mousePosView, dt);

	//Getting text of the active button and a true value if a play was selected
	this->gameTextFromDropdown = this->games_dropdown->getDropdownActiveText(this->gameTextFromDropdown);
	cout << this->gameTextFromDropdown << endl;

	this->playStatusFromDropdown = this->games_dropdown->getPlayStatus(this->playStatusFromDropdown);

	//Mapping the key of each game to its play according to the text of the active game pressed
	if (this->gameTextFromDropdown == "Cleveland Browns (CLE) vs Baltimore Ravens (BAL)")
	{
		this->playTextFromDropdown = this->plays_CLEBAL->getDropdownActiveText(this->playTextFromDropdown);
		this->GameStateKeysTemporal[2018123000] = this->playTextFromDropdown;

		this->GameStateKeysTemporal11.first = 2018123000;
		this->GameStateKeysTemporal11.second = this->playTextFromDropdown;

	}

	if (this->gameTextFromDropdown == "Baltimore Ravens (BAL) vs Los Angeles Chargers (LAC)")
	{
		this->playTextFromDropdown = this->plays_BALLAC->getDropdownActiveText(this->playTextFromDropdown);
		this->GameStateKeysTemporal[2018122201] = this->playTextFromDropdown;

		this->GameStateKeysTemporal11.first = 2018122201;
		this->GameStateKeysTemporal11.second = this->playTextFromDropdown;
	}

	if (this->gameTextFromDropdown == "Miami Dolphins (MIA) vs Buffalo Bills (BUF)")
	{
		this->playTextFromDropdown = this->plays_MIABUF->getDropdownActiveText(this->playTextFromDropdown);
		this->GameStateKeysTemporal[2018123001] = this->playTextFromDropdown;

		this->GameStateKeysTemporal11.first = 2018123001;
		this->GameStateKeysTemporal11.second = this->playTextFromDropdown;
	}

	if (this->gameTextFromDropdown == "Detroit Lions (DET) vs Green Bay Packers (GB)")
	{
		this->playTextFromDropdown = this->plays_DETGB->getDropdownActiveText(this->playTextFromDropdown);
		this->GameStateKeysTemporal[2018123002] = this->playTextFromDropdown;

		this->GameStateKeysTemporal11.first = 2018123002;
		this->GameStateKeysTemporal11.second = this->playTextFromDropdown;
	}

	if (this->gameTextFromDropdown == "Jacksonville Jaguars (JAX) vs Houston Texas (HOU)")
	{
		this->playTextFromDropdown = this->plays_JAXHOU->getDropdownActiveText(this->playTextFromDropdown);
		this->GameStateKeysTemporal[2018123003] = this->playTextFromDropdown;

		this->GameStateKeysTemporal11.first = 2018123003;
		this->GameStateKeysTemporal11.second = this->playTextFromDropdown;
	}

	if (this->gameTextFromDropdown == "Oakland Raiders (OAK) vs Kansas City (KC)")
	{
		this->playTextFromDropdown = this->plays_OAKKC->getDropdownActiveText(this->playTextFromDropdown);
		this->GameStateKeysTemporal[2018123004] = this->playTextFromDropdown;

		this->GameStateKeysTemporal11.first = 2018123004;
		this->GameStateKeysTemporal11.second = this->playTextFromDropdown;
	}


	//Setting a boolean to true that lets Entity now that a selection was applied
	if (this->buttons1["SELECTION_STATE_APPLY"]->isPressed())
	{
		this->intermedio.GameStateKeysTemporal22 = this->GameStateKeysTemporal11;

		this->intermedio.GameStateKeysTemporal2 = this->GameStateKeysTemporal;
		this->intermedio.selection_applied = true;
		this->intermedio.GameSelectedGlobal = this->gameTextFromDropdown;
	}

	//Check
	cout << this->GameStateKeysTemporal11.first;
	cout << this->GameStateKeysTemporal11.second;

	////Check 
	//for (const auto& pair : this->intermedio.GameStateKeysTemporal2) 
	//{
	//	cout << "Checking GameStateKey at SelectionState";
	//	std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
	//}
}

void PauseMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateGui(dt);

}

void PauseMenuState::renderGui(sf::RenderTarget* target)
{
	//Buttons
	for (auto& it : this->buttons1)
	{
		it.second->render(target);
	}

	//Dropdown lists

	//for (auto& it : this->dropDownLists)
	//{
	//	it.second->render(target);
	//}

	/*this->dropDownLists["Games"]->render(target);*/

	games_dropdown->render(target);

	//Displaying the plays dropdown for each game if the game is selected

	if (this->gameTextFromDropdown == "Cleveland Browns (CLE) vs Baltimore Ravens (BAL)")
	{
		this->plays_CLEBAL->render(target);
	}
	if (this->gameTextFromDropdown == "Baltimore Ravens (BAL) vs Los Angeles Chargers (LAC)")
	{
		this->plays_BALLAC->render(target);
	}

	if (this->gameTextFromDropdown == "Miami Dolphins (MIA) vs Buffalo Bills (BUF)")
	{
		this->plays_MIABUF->render(target);
	}

	if (this->gameTextFromDropdown == "Detroit Lions (DET) vs Green Bay Packers (GB)")
	{
		this->plays_DETGB->render(target);
	}

	if (this->gameTextFromDropdown == "Jacksonville Jaguars (JAX) vs Houston Texas (HOU)")
	{
		this->plays_JAXHOU->render(target);
	}

	if (this->gameTextFromDropdown == "Oakland Raiders (OAK) vs Kansas City (KC)")
	{
		this->plays_OAKKC->render(target);
	}
}

void PauseMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->renderGui(target);

	//Mouse Position
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());
	target->draw(mouseText);
}
