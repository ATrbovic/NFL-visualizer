#ifndef GAMESTATE_H
#define GAMESTATE_h

#include "State.h"
#include "PauseMenuState.h"

// The GameState class is derived from the State class.

class GameState :
    public State
{
private:
    Entity player; // An instance of the Entity class representing the player.

    // Data Medium
    DataMedium intermedio; // An instance of the DataMedium class.

    // Variables
    bool start = true; // A boolean variable indicating whether the game has just started.
    sf::Font font; // A font object for text rendering.
    sf::Font NFLfont; // Another font object for text rendering (related to NFL).
    int PlayButtonState; // An integer variable representing the state of the play button.
    float buttonRatio; // A float variable representing the ratio of the button size.

    int MovingPlayGUI = 250; // An integer variable representing the position of the moving play GUI.

    // Texts
    sf::Text DisplayGameText; // A text object to display the game text.
    sf::Text DisplayPlayText; // A text object to display the play text.
    std::stringstream GameTextStream; // A string stream for game text manipulation.
    std::stringstream PlayTextStream; // A string stream for play text manipulation.

    sf::Text EndZoneTagLeft; // A text object for the left end zone tag.
    sf::Text EndZoneTagRight; // A text object for the right end zone tag.

    std::string EndZoneTagTextLeft; // A string variable for the left end zone tag text.
    std::string EndZoneTagTextRight; // A string variable for the right end zone tag text.

    // Textures
    sf::Texture gamestate_background_tex; // A texture for the background.

    // Shapes
    std::map<std::string, gui::Button*> GameStateButtons; // A map of buttons.

    sf::RectangleShape gamestate_guiBackground; // A rectangle shape for the GUI background.
    sf::RectangleShape gamestate_background; // A rectangle shape for the background.

    sf::CircleShape PlayButton; // A circle shape for the play button.
    sf::RectangleShape PlayButtonBackground; // A rectangle shape for the play button background.
    sf::RectangleShape ResumeTide1; // A rectangle shape for the first resume tide.
    sf::RectangleShape ResumeTide2; // A rectangle shape for the second resume tide.

    sf::CircleShape IncreaseSpeedButton1; // A circle shape for the first increase speed button.
    sf::CircleShape IncreaseSpeedButton2; // A circle shape for the second increase speed button.

    sf::CircleShape DecreaseSpeedButton1; // A circle shape for the first decrease speed button.
    sf::CircleShape DecreaseSpeedButton2; // A circle shape for the second decrease speed button.

    // Functions
    void initKeybinds(); // Function to initialize keybindings.

public:
    // Constructor
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);

    // Destructor
    virtual ~GameState();

    // Variables (unspecified).

    // Functions
    void endState(); // Function to end the state.
    void initFiles(); // Function to initialize files.
    void updateInput(const float& dt); // Function to update input.
    void update(const float& dt); // Function to update the state.
    void render(sf::RenderTarget* target = nullptr); // Function to render the state.

    sf::Color GetTeamColor(std::string& input); // Function to get the team color based on input.
};
#endif
