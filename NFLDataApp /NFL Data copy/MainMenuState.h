#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H


#include "GameState.h"
#include "DataMedium.h"
#include "SelectionState.h"

class MainMenuState :
    public State
{
private:

    DataMedium intermedio;

    //Variables
    sf::RectangleShape background;
    sf::Font font;
    std::string temporal;
    std::map<int, std::string> pormientras;

    
    

    //Textures
    sf::Texture mainmenustate_background_tex;
    sf::Texture mainmenustate2_background_tex;
 
    

    std::map<std::string, gui::Button*> buttons;
    

    //Functions
    void initFiles();
    void initKeybinds();
    void initGui();

   
protected:

  

public:
    //Variables
    bool window_field = false;

    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~MainMenuState();

    //Functions
    void endState();

   
    void updateInput(const float& dt);
    void updateGui(const float& dt);
    void update(const float& dt);
    void renderGui(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};
#endif
