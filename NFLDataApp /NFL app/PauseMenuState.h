#pragma once
#include "State.h"

class GameState;

class PauseMenuState :
    public State
{
    
    private:

        //New GameState after changing play
        GameState* gameState;

        //Medium of data
        DataMedium intermedio;

        //Variables
        sf::RectangleShape background;
        sf::Font font;


        string gameTextFromDropdown;
        string playTextFromDropdown;

        bool playStatusFromDropdown;

        std::map<int, string> GameStateKeysTemporal;


        //Texture

        //Gui
        std::map<std::string, gui::Button*> buttons1;
        std::map<std::string, gui::DropDownList*> dropDownLists;
        std::pair<int, std::string> GameStateKeysTemporal11 = std::make_pair(0, "");


        gui::DropDownList* games_dropdown;
        gui::DropDownList* plays_BALLAC;
        gui::DropDownList* plays_CLEBAL;
        gui::DropDownList* plays_MIABUF;
        gui::DropDownList* plays_DETGB;
        gui::DropDownList* plays_JAXHOU;
        gui::DropDownList* plays_OAKKC;


        //Functions
        void initFiles();
        void initKeybinds();
        void initGui();


    public:

        PauseMenuState(sf::RenderWindow * window, std::map<std::string, int>*supportedKeys, std::stack<State*>*states);
        virtual ~PauseMenuState();

        //Variables




        //Functions
        void endState();
        void updateInput(const float& dt);
        void updateGui(const float& dt);
        void update(const float& dt);
        void renderGui(sf::RenderTarget * target = nullptr);
        void render(sf::RenderTarget * target = nullptr);
    };


