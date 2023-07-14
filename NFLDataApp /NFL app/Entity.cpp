#include "Entity.h"
#include <map>
#include <string>


// Function to initialize files (textures and fonts) for the Entity.
void Entity::initFiles()
{
    // Load player art textures for home and away.
    if (!this->playerartHome_tex.loadFromFile("Textures/playerart_home.png"))
    {
        throw("ERROR:ENTITY::COULD NOT LOAD TEXTURE");
    }
    if (!this->playerartAway_tex.loadFromFile("Textures/playerart_away.png"))
    {
        throw("ERROR:ENTITY::COULD NOT LOAD TEXTURE");
    }

    // Load ball texture.
    if (!this->ball_tex.loadFromFile("Textures/ballart.png"))
    {
        throw("ERROR:ENTITY::COULD NOT LOAD TEXTURE");
    }

    // Load font.
    if (!this->font.loadFromFile("Fonts/ChakraPetch-Bold.ttf"))
    {
        throw("ERROR:ENTITY::COULD NOT LOAD FONT");
    }

    // Load orientation marker texture.
    if (!this->OrientationMarker_tex.loadFromFile("Textures/OrientationMarker.png"))
    {
        throw("ERROR:ENTITY::COULD NOT LOAD TEXTURE");
    }
}

// Constructor for the Entity class.
Entity::Entity()
{
    // Set default values for member variables.
    this->frame_index = 11;
    this->j = 0;
    this->k = 0;
    this->playerDotRadius = 10;

    // Set position and radius for test shape (unspecified purpose).
    test.setRadius(10.f);
    test.setPosition(sf::Vector2f(1000, 60));

    // Initialize files (textures and fonts).
    this->initFiles();

    // Initialize data and tracking file key (unspecified functions).
    this->initData();
    initTrackingFileKey();
}

// Destructor for the Entity class.
Entity::~Entity()
{
    // Default destructor implementation is empty.
}


void Entity::setActivePlayFile()
{
    this->activeFileName = "Tracking Data/game 2018123000/play36kickoff.csv";
    this->activePlayType = "kickoff";

    //Preprocessing values that come from the data medium

    if (this->intermedio.selection_applied)
    {
        //for (const auto& pair : this->intermedio.GameStateKeysTemporal2)
        //{
        //    this->activeGameKey = pair.first;
        //    this->activePlay = pair.second;
        //    std::cout << "Keyetsaa: " << pair.first << ", Value: " << pair.second << std::endl;
        //}

        this->activeGameKey = this->intermedio.GameStateKeysTemporal22.first;
        this->activePlay = this->intermedio.GameStateKeysTemporal22.second;

        //Making "Play 36 - Kickoff" go to "play36kickoff" for instance
        this->activePlay.erase(std::remove_if(this->activePlay.begin(), this->activePlay.end(), [](char c) { return c == ' ' || c == '-'; }), this->activePlay.end());
        std::transform(this->activePlay.begin(), this->activePlay.end(), this->activePlay.begin(), [](unsigned char c) {return std::tolower(c); });
        cout << this->activePlay << endl;

        // Find the position of the last number in the string
        auto lastNumberPos = std::distance(this->activePlay.begin(),
            std::find_if(this->activePlay.rbegin(), this->activePlay.rend(),
                [](char c) { return std::isdigit(c); }).base()) - 1;

        // Extract the substring after the last number
        this->activePlayType = this->activePlay.substr(lastNumberPos + 1);

        cout << this->activePlayType << endl; // Prints the value of the `activePlayType` member variable.

        // Constructs the `activeFileName` string by combining the game key and play name.
        this->activeFileName = "Tracking Data/game " + std::to_string(this->activeGameKey) + "/" + this->activePlay + ".csv";
        cout << this->activeFileName;
    }

    // Opens the tracking file specified by `activeFileName`
    tracking_file.open(this->activeFileName);

if (!tracking_file.is_open())
{
    throw "Unable to open file"; // Throws an error if the tracking file fails to open.
}

string line = "";

string headline;
getline(tracking_file, headline); // Reads the headline from the tracking file.

while (getline(tracking_file, line))
{
    // Declaration of variables to store tracking data.
    string time;
    double x_position;
    double y_position;
    double speed;
    double acceleration;
    double distance;
    double orientation;
    double direction;
    string event;
    int nfl_id;
    string name;
    string jersey_number;
    string position;
    string home_away;
    int frameId;
    int gameId;
    int playId;
    string play_direction;
    double x_velocity;
    double y_velocity;

    string tempString = ""; // Temporary string variable for parsing.

    stringstream inputString(line); // Create a string stream to parse the line.

    getline(inputString, time, ','); // Parse and store the time value.

    // Parse and store the x_position, converting from string to double.
    tempString = "";
    getline(inputString, tempString, ',');
    x_position = atof(tempString.c_str());

    // Parse and store the y_position, converting from string to double.
    tempString = "";
    getline(inputString, tempString, ',');
    y_position = atof(tempString.c_str());

    // Parse and store the speed, converting from string to double.
    tempString = "";
    getline(inputString, tempString, ',');
    speed = atof(tempString.c_str());

    // Parse and store the acceleration, converting from string to double.
    tempString = "";
    getline(inputString, tempString, ',');
    acceleration = atof(tempString.c_str());

    // Parse and store the distance, converting from string to double.
    tempString = "";
    getline(inputString, tempString, ',');
    distance = atof(tempString.c_str());

    // Parse and store the orientation, converting from string to double.
    tempString = "";
    getline(inputString, tempString, ',');
    orientation = atof(tempString.c_str());

    // Parse and store the direction, converting from string to double.
    tempString = "";
    getline(inputString, tempString, ',');
    direction = atof(tempString.c_str());

    getline(inputString, event, ','); // Parse and store the event value.

    // Parse and store the nfl_id, converting from string to integer.
    tempString = "";
    getline(inputString, tempString, ',');
    nfl_id = atoi(tempString.c_str());

    getline(inputString, name, ','); // Parse and store the name value.

    getline(inputString, jersey_number, ','); // Parse and store the jersey_number value.

    getline(inputString, position, ','); // Parse and store the position value.

    getline(inputString, home_away, ','); // Parse and store the home_away value.

    // Parse and store the frameId, converting from string to integer.
    tempString = "";
    getline(inputString, tempString, ',');
    frameId = atoi(tempString.c_str());

    // Parse and store the gameId, converting from string to integer.
    tempString = "";
    getline(inputString, tempString, ',');
    gameId = atoi(tempString.c_str());

    // Parse and store the playId, converting from string to integer.
    tempString = "";
    getline(inputString, tempString, ',');
    playId = atoi(tempString.c_str());

    getline(inputString, play_direction, ','); // Parse and store the play_direction value.

    x_velocity = 0; // Set x_velocity to 0.
    y_velocity = 0; // Set Y velocity to 0.


        TrackingData tracking(time, x_position, y_position, speed, acceleration, distance, orientation, direction, event, nfl_id, name,
            jersey_number, position, home_away, frameId, gameId, playId, play_direction, x_velocity, y_velocity);

        this->tracking_vector.push_back(tracking);


        line = " ";

    }
}

sf::Color Entity::GetTeamColor(std::string& input)
{
    // Returns the corresponding SFML Color based on the input team name.

    if (input == "Browns")
    {
        return sf::Color(255, 60, 0); // Returns an SFML Color representing the Browns team color.
    }
    if (input == "Ravens")
    {
        return sf::Color(26, 25, 95); // Returns an SFML Color representing the Ravens team color.
    }
    if (input == "Chargers")
    {
        return sf::Color(0, 128, 198); // Returns an SFML Color representing the Chargers team color.
    }
    if (input == "Dolphins")
    {
        return sf::Color(0, 142, 151); // Returns an SFML Color representing the Dolphins team color.
    }
    if (input == "Bills")
    {
        return sf::Color(0, 51, 141); // Returns an SFML Color representing the Bills team color.
    }
    if (input == "Lions")
    {
        return sf::Color(176, 183, 188); // Returns an SFML Color representing the Lions team color.
    }
    if (input == "Packers")
    {
        return sf::Color(24, 48, 40); // Returns an SFML Color representing the Packers team color.
    }
    if (input == "Jaguars")
    {
        return sf::Color(159, 121, 44); // Returns an SFML Color representing the Jaguars team color.
    }
    if (input == "Texas")
    {
        return sf::Color(191, 87, 0); // Returns an SFML Color representing the Texas team color.
    }
    if (input == "Raiders")
    {
        return sf::Color(165, 172, 175); // Returns an SFML Color representing the Raiders team color.
    }
    if (input == "Kansas City")
    {
        return sf::Color(227, 24, 55); // Returns an SFML Color representing the Kansas City team color.
    }
    if (input == "Cardinals")
    {
        return sf::Color(155, 35, 63); // Approximate color for the Cardinals.
    }
    if (input == "Falcons")
    {
        return sf::Color(0, 0, 0); // Color for the Falcons.
    }
    if (input == "Panthers")
    {
        return sf::Color(0, 133, 202); // Approximate color for the Panthers.
    }
    if (input == "Bears")
    {
        return sf::Color(11, 22, 42); // Approximate color for the Bears.
    }
    if (input == "Bengals")
    {
        return sf::Color(251, 79, 20); // Approximate color for the Bengals.
    }
    if (input == "Cowboys")
    {
        return sf::Color(0, 34, 68); // Approximate color for the Cowboys.
    }
    if (input == "Broncos")
    {
        return sf::Color(0, 34, 68); // Approximate color for the Broncos.
    }
    if (input == "Colts")
    {
        return sf::Color(0, 44, 95); // Approximate color for the Colts.
    }
    if (input == "Eagles")
    {
        return sf::Color(0, 76, 84); // Approximate color for the Eagles.
    }
    if (input == "Giants")
    {
        return sf::Color(1, 35, 82); // Approximate color for the Giants.
    }
    if (input == "Jets")
    {
        return sf::Color(18, 76, 72); // Approximate color for the Jets.
    }
    if (input == "Patriots")
    {
        return sf::Color(0, 34, 68); // Approximate color for the Patriots.
    }
    if (input == "Saints")
    {
        return sf::Color(211, 188, 141); // Approximate color for the Saints.
    }
    if (input == "Seahawks")
    {
        return sf::Color(0, 21, 50); // Approximate color for the Seahawks.
    }
    if (input == "Steelers")
    {
        return sf::Color(16, 24, 32); // Approximate color for the Steelers.
    }
    if (input == "Titans")
    {
        return sf::Color(12, 35, 64); // Approximate color for the Titans.
    }
    if (input == "Vikings")
    {
        return sf::Color(79, 38, 131); // Approximate color for the Vikings.
    }
    if (input == "Washington")
    {
        return sf::Color(63, 16, 16); // Approximate color for the Washington team.
    }


    // The function may not return a value if the input does not match any of the specified team names.
    // This should be handled or checked in the calling code to ensure all possible cases are handled.
}



// Function to load CSV data into the map
void loadCSVData()
{
    {"ARI"}
}

void Entity::initData()
{
    this->setActivePlayFile();
    
    this->orientationTest.setTexture(this->OrientationMarker_tex);
    this->orientationTest.setPosition(sf::Vector2f(1000 - 5, 60 - 10));
    this->orientationTest.setRotation(10);

    //Getting home and away team
    //Prior way to get home and away team
    // if (this->intermedio.GameSelectedGlobal == "Cleveland Browns (CLE) vs Baltimore Ravens (BAL)")
    // {
    //     this->away_team = "Browns";
    //     this->home_team = "Ravens";
    // }
    // if (this->intermedio.GameSelectedGlobal == "Baltimore Ravens (BAL) vs Los Angeles Chargers (LAC)")
    // {
    //     this->away_team = "Ravens";
    //     this->home_team = "Chargers";
    // }
    // if (this->intermedio.GameSelectedGlobal == "Miami Dolphins (MIA) vs Buffalo Bills (BUF)")
    // {
    //     this->away_team = "Dolphins";
    //     this->home_team = "Bills";
    // }
    // if (this->intermedio.GameSelectedGlobal == "Detroit Lions (DET) vs Green Bay Packers (GB)")
    // {
    //     this->away_team = "Lions";
    //     this->home_team = "Packers";
    // }
    // if (this->intermedio.GameSelectedGlobal == "Jacksonville Jaguars (JAX) vs Houston Texas (HOU)")
    // {
    //     this->away_team = "Jaguars";
    //     this->home_team = "Texas";
    // }
    // if (this->intermedio.GameSelectedGlobal == "Oakland Raiders (OAK) vs Kansas City (KC)")
    // {
    //     this->away_team = "Raiders";
    //     this->home_team = "Kansas City";
    // }

    //dyanmic method to get home and away teams

    //initializing map for ohme and away teams
    std::map<std::string, std::string> teamAbbrToName = {
        {"ARI", "Arizona Cardinals"}
        {"ATL",	"Atlanta Falcons"}
        {"BAL",	"Baltimore Ravens"}
        {"BUF",	"Buffalo Bills"}
        {"CAR",	"Carolina Panthers"}
        {"CHI",	"Chicago Bears"}   
        {"CIN",	"Cincinnati Bengals"}
        {"CLE",	"Cleveland Browns"}
        {"DAL",	"Dallas Cowboys"}
        {"DEN",	"Denver Broncos"}
        {"DET",	"Detroit Lions"}
        {"GB", "Green Bay Packers"}
        {"HOU",	"Houston Texans"}
        {"IND",	"ndianapolis Colts"}
        {"JAX",	"Jacksonville Jaguars"}
        {"KC",	"Kansas City Chiefs"}
        {"MIA",	"Miami Dolphins"}
        {"MIN",	"Minnesota Vikings"}
        {"NE",	"New England Patriots"}
        {"NO",	"New Orleans Saints"}
        {"NYG",	"New York Giants"}
        {"NYJ",	"New York Jets"}
        {"LV",	"Las Vegas Raiders"}
        {"PHI",	"Philadelphia Eagles"}
        {"PIT",	"Pittsburgh Steelers"}
        {"LAC",	"Los Angeles Chargers"}
        {"SF",	"San Francisco 49ers"}
        {"SEA",	"Seattle Seahawks"}
        {"LAR",	"Los Angeles Rams"}
        {"TB",	"Tampa Bay Buccaneers"}
        {"TEN",	"Tennessee Titans"}
        {"WAS",	"Washington Commanders"}
    }



    intermedio.home_away_teams.first = home_team;
    intermedio.home_away_teams.second = away_team;
    
    //Giving each player a circle and its initial position
    for (auto& data : this->tracking_vector)
    {
        //Player Circle
        sf::CircleShape playerCircle;

        //Player Jersey Number
        sf::Text JerseyNumber;
        JerseyNumber.setFont(font);
        JerseyNumber.setFillColor(sf::Color::Black);
        
        //Player Art
        sf::Sprite playerArt;

        //Player Speed/Direction
        sf::RectangleShape playerSpeed;

        //Player Speed/Direction Arrow
        sf::CircleShape arrowSpeed(4.2, 3);

        //Displaying the default play (i.e no choice has been made by user)
        if (!intermedio.selection_applied)
        {
            //Using the tracking data to display the starting position for the default play
            if (data.FrameId == 10)
            {
                //Displaying players with an art (not activated)
                playerArt.setPosition((data.x) * 10, 106.6 + ((data.y) * 8));

                //Displaying players with a circle (activated)
                playerCircle.setPosition((data.x) * 10, 106.6 + ((data.y) * 8)); 

                //Displaying players jersey number
                JerseyNumber.setPosition(playerCircle.getPosition().x + playerCircle.getLocalBounds().width / 2, playerCircle.getPosition().y + playerCircle.getLocalBounds().height / 2);

                if (data.Home_Away == "home" || data.Home_Away == "away")
                {
                    // Player circle settings for home or away players.
                    playerCircle.setRadius(10.f);
                    // Player speed position and settings.
                    playerSpeed.setPosition(playerCircle.getPosition().x + playerCircle.getLocalBounds().width - 0.5, 
                        playerCircle.getPosition().y + playerCircle.getLocalBounds().height / 2);

                    // Arrow speed settings.
                    arrowSpeed.setRotation(90);
                    arrowSpeed.setPosition(playerSpeed.getPosition().x + playerSpeed.getLocalBounds().width + arrowSpeed.getLocalBounds().width, playerSpeed.getPosition().y - playerSpeed.getLocalBounds().height / 2 - arrowSpeed.getLocalBounds().height/2);

                    // Player speed size and rotation.
                    playerSpeed.setSize(sf::Vector2f(data.s, 3.5));
                    playerSpeed.setRotation(data.dir - 90);

                    // Jersey number settings.
                    JerseyNumber.setString(data.Jersey_Number);
                    JerseyNumber.setCharacterSize(10);
                    JerseyNumber.setPosition(
                        playerCircle.getPosition().x + (playerCircle.getGlobalBounds().width / 2.f) - JerseyNumber.getGlobalBounds().width / 2.f,
                        playerCircle.getPosition().y + (playerCircle.getGlobalBounds().height / 2.f) - JerseyNumber.getGlobalBounds().height / 2.f);
                    
                    if (data.Home_Away == "home")
                    {
                        // Player art and circle color settings for home players.
                        playerArt.setTexture(this->playerartHome_tex);
                        playerCircle.setFillColor(sf::Color(36, 23, 115));
                    }

                    else if (data.Home_Away == "away")
                    {
                        // Settings for football player.
                        playerArt.setTexture(this->playerartAway_tex);
                        playerArt.setScale(-1.f, 1.f);
                        playerCircle.setFillColor(sf::Color(255, 60, 0));
                    }
                }

                else if (data.Home_Away == "football")
                {
                    // Settings for football player.
                    playerSpeed.setSize(sf::Vector2f(0, 0));
                    arrowSpeed.setRadius(0);
                    playerArt.setTexture(this->ball_tex);
                    playerCircle.setRadius(7.f);
                    playerCircle.setFillColor(sf::Color(165, 42, 42));
                }

                else
                {
                    // Settings for non-home, non-away players.
                    playerCircle.setRadius(0);
                }

                // Add player-related objects to their respective containers.
                this->playersArt.push_back(playerArt);
                this->playersCircle.push_back(playerCircle);
                this->playersJersey.push_back(JerseyNumber);
                this->playersSpeed.push_back(playerSpeed);
                this->arrowsSpeed.push_back(arrowSpeed);

            }

        }


        else if (intermedio.selection_applied && this->activePlayType == "kickoff")
        {
            // Condition: Selection is applied and active play type is "kickoff".
            if (data.FrameId == 10)
            {
                // If the frame ID is 10, perform the following actions for the player.

                // Set player art and circle positions based on the data.
                playerArt.setPosition((data.x) * 10, 106.6 + ((data.y) * 8));
                playerCircle.setPosition((data.x) * 10, 106.6 + ((data.y) * 8));
                JerseyNumber.setPosition(playerCircle.getPosition().x + playerCircle.getLocalBounds().width / 2, playerCircle.getPosition().y + playerCircle.getLocalBounds().height / 2);

                if (data.Home_Away == "home" || data.Home_Away == "away")
                {
                    // If the player is identified as "home" or "away", perform the following actions.

                    // Set player circle radius, JerseyNumber string and position, player speed position, arrow speed position, player speed size and rotation based on the data.
                    playerCircle.setRadius(10.f);
                    JerseyNumber.setString(data.Jersey_Number);
                    JerseyNumber.setCharacterSize(10);
                    JerseyNumber.setPosition(
                        playerCircle.getPosition().x + (playerCircle.getGlobalBounds().width / 2.f) - JerseyNumber.getGlobalBounds().width / 2.f,
                        playerCircle.getPosition().y + (playerCircle.getGlobalBounds().height / 2.f) - JerseyNumber.getGlobalBounds().height / 2.f);

                    playerSpeed.setPosition(playerCircle.getPosition().x + playerCircle.getLocalBounds().width - 0.5,
                        playerCircle.getPosition().y + playerCircle.getLocalBounds().height / 2);

                    arrowSpeed.setRotation(90);
                    arrowSpeed.setPosition(playerSpeed.getPosition().x + playerSpeed.getLocalBounds().width + arrowSpeed.getLocalBounds().width, playerSpeed.getPosition().y - playerSpeed.getLocalBounds().height / 2 - arrowSpeed.getLocalBounds().height / 2);

                    playerSpeed.setSize(sf::Vector2f(data.s, 3.5));
                    playerSpeed.setRotation(data.dir - 90);

                    if (data.Home_Away == "home")
                    {
                        // If the player is identified as "home", set player art texture and circle fill color based on the home team.
                        playerArt.setTexture(this->playerartHome_tex);

                        playerCircle.setFillColor(GetTeamColor(this->home_team));
                    }
                    else if (data.Home_Away == "away")
                    {
                        // If the player is identified as "away", set player art texture, scale, and circle fill color based on the away team.
                        playerArt.setTexture(this->playerartAway_tex);
                        playerArt.setScale(-1.f, 1.f);

                        playerCircle.setFillColor(GetTeamColor(this->away_team));
                    }
                }
                else if (data.Home_Away == "football")
                {
                    // If the player is identified as "football", set player art texture, circle radius, position, and fill color.
                    playerArt.setTexture(this->ball_tex);

                    playerCircle.setRadius(7.f);
                    this->TempBallPosition = playerCircle.getPosition();

                    playerCircle.setFillColor(sf::Color(165, 42, 42));
                }
                else
                {
                    // For any other case, set player circle radius to 0 to hide it.
                    playerCircle.setRadius(0);
                }

                // Getting location of endzone based on the player's position and play direction.
                if (data.Position == "K")
                {
                    if ((data.Home_Away == "home" && data.Play_direction == "right") || (data.Home_Away == "away" && data.Play_direction == "left"))
                    {
                        intermedio.global_right_endzone = this->home_team;
                        intermedio.global_left_endzone = this->away_team;
                    }

                    else
                    {
                        intermedio.global_right_endzone = this->away_team;
                        intermedio.global_left_endzone = this->home_team;
                    }

                }

                else if (data.Position == "P")
                {
                    if ((data.Home_Away == "home" && data.Play_direction == "right") || (data.Home_Away == "away" && data.Play_direction == "left"))
                    {
                        intermedio.global_right_endzone = this->home_team;
                        intermedio.global_left_endzone = this->away_team;
                    }

                    else
                    {
                        intermedio.global_right_endzone = this->away_team;
                        intermedio.global_left_endzone = this->home_team;
                    }
                }

                this->playersArt.push_back(playerArt);
                this->playersCircle.push_back(playerCircle);
                this->playersJersey.push_back(JerseyNumber);
                this->playersSpeed.push_back(playerSpeed);
                this->arrowsSpeed.push_back(arrowSpeed);
            }

 
        }

        else if (intermedio.selection_applied && this->activePlayType == "fieldgoal")
        {
            // Condition: Selection is applied and active play type is "fieldgoal".
            if (data.FrameId == 11)
            {
                // If the frame ID is 11, perform the following actions for the player.

                // Set player art and circle positions based on the data.
                playerArt.setPosition((data.x) * 10, 106.6 + ((data.y) * 8));
                playerCircle.setPosition((data.x) * 10, 106.6 + ((data.y) * 8));
                JerseyNumber.setPosition(playerCircle.getPosition().x + playerCircle.getLocalBounds().width / 2, playerCircle.getPosition().y + playerCircle.getLocalBounds().height / 2);

                if (data.Home_Away == "home" || data.Home_Away == "away")
                {
                    playerCircle.setRadius(10.f);
                    JerseyNumber.setString(data.Jersey_Number);
                    JerseyNumber.setCharacterSize(10);
                    JerseyNumber.setPosition(
                        playerCircle.getPosition().x + (playerCircle.getGlobalBounds().width / 2.f) - JerseyNumber.getGlobalBounds().width / 2.f,
                        playerCircle.getPosition().y + (playerCircle.getGlobalBounds().height / 2.f) - JerseyNumber.getGlobalBounds().height / 2.f);

                    playerSpeed.setPosition(playerCircle.getPosition().x + playerCircle.getLocalBounds().width - 0.5,
                        playerCircle.getPosition().y + playerCircle.getLocalBounds().height / 2);

                    arrowSpeed.setRotation(90);
                    arrowSpeed.setPosition(playerSpeed.getPosition().x + playerSpeed.getLocalBounds().width + arrowSpeed.getLocalBounds().width, playerSpeed.getPosition().y - playerSpeed.getLocalBounds().height / 2 - arrowSpeed.getLocalBounds().height / 2);

                    playerSpeed.setSize(sf::Vector2f(data.s, 3.5));
                    playerSpeed.setRotation(data.dir - 90);

                    if (data.Home_Away == "home")
                    {
                        playerArt.setTexture(this->playerartHome_tex);

                        playerCircle.setFillColor(GetTeamColor(this->home_team));
                    }
                    else if (data.Home_Away == "away")
                    {
                        playerArt.setTexture(this->playerartAway_tex);
                        playerArt.setScale(-1.f, 1.f);

                        playerCircle.setFillColor(GetTeamColor(this->away_team));
                    }
                }
                else if (data.Home_Away == "football")
                {
                    playerArt.setTexture(this->ball_tex);

                    playerCircle.setRadius(7.f);
                    playerCircle.setFillColor(sf::Color(165, 42, 42));
                }
                else
                {
                    playerCircle.setRadius(0);
                }

                //Getting location of endzone
                if (data.Position == "K")
                {
                    if ((data.Home_Away == "home" && data.Play_direction == "right") || (data.Home_Away == "away" && data.Play_direction == "left"))
                    {
                        intermedio.global_right_endzone = this->home_team;
                        intermedio.global_left_endzone = this->away_team;
                    }

                    else
                    {
                        intermedio.global_right_endzone = this->away_team;
                        intermedio.global_left_endzone = this->home_team;
                    }

                }

                else if (data.Position == "P")
                {
                    if ((data.Home_Away == "home" && data.Play_direction == "right") || (data.Home_Away == "away" && data.Play_direction == "left"))
                    {
                        intermedio.global_right_endzone = this->home_team;
                        intermedio.global_left_endzone = this->away_team;
                    }

                    else
                    {
                        intermedio.global_right_endzone = this->away_team;
                        intermedio.global_left_endzone = this->home_team;
                    }
                }

                this->playersArt.push_back(playerArt);
                this->playersCircle.push_back(playerCircle);
                this->playersJersey.push_back(JerseyNumber);
                this->playersSpeed.push_back(playerSpeed);
                this->arrowsSpeed.push_back(arrowSpeed);
            }

        }

        else if (intermedio.selection_applied && this->activePlayType == "punt")
        {
            if (data.FrameId == 11)
            {
                playerArt.setPosition((data.x) * 10, 106.6 + ((data.y) * 8));
                playerCircle.setPosition((data.x) * 10, 106.6 + ((data.y) * 8));
                JerseyNumber.setPosition(playerCircle.getPosition().x + playerCircle.getLocalBounds().width / 2, playerCircle.getPosition().y + playerCircle.getLocalBounds().height / 2);

                if (data.Home_Away == "home" || data.Home_Away == "away")
                {
                    playerCircle.setRadius(10.f);
                    JerseyNumber.setString(data.Jersey_Number);
                    JerseyNumber.setCharacterSize(10);
                    JerseyNumber.setPosition(
                        playerCircle.getPosition().x + (playerCircle.getGlobalBounds().width / 2.f) - JerseyNumber.getGlobalBounds().width / 2.f,
                        playerCircle.getPosition().y + (playerCircle.getGlobalBounds().height / 2.f) - JerseyNumber.getGlobalBounds().height / 2.f);

                    playerSpeed.setPosition(playerCircle.getPosition().x + playerCircle.getLocalBounds().width - 0.5,
                        playerCircle.getPosition().y + playerCircle.getLocalBounds().height / 2);

                    arrowSpeed.setRotation(90);
                    arrowSpeed.setPosition(playerSpeed.getPosition().x + playerSpeed.getLocalBounds().width + arrowSpeed.getLocalBounds().width, playerSpeed.getPosition().y - playerSpeed.getLocalBounds().height / 2 - arrowSpeed.getLocalBounds().height / 2);

                    playerSpeed.setSize(sf::Vector2f(data.s, 3.5));
                    playerSpeed.setRotation(data.dir - 90);

                    if (data.Home_Away == "home")
                    {
                        playerArt.setTexture(this->playerartHome_tex);

                        playerCircle.setFillColor(GetTeamColor(this->home_team));
                    }
                    else if (data.Home_Away == "away")
                    {
                        playerArt.setTexture(this->playerartAway_tex);
                        playerArt.setScale(-1.f, 1.f);

                        playerCircle.setFillColor(GetTeamColor(this->away_team));
                    }
                }
                else if (data.Home_Away == "football")
                {
                    playerArt.setTexture(this->ball_tex);

                    playerCircle.setRadius(7.f);
                    playerCircle.setFillColor(sf::Color(165, 42, 42));
                }
                else
                {
                    playerCircle.setRadius(0);
                }

                //Getting location of endzone
                if (data.Position == "K")
                {
                    if ((data.Home_Away == "home" && data.Play_direction == "right") || (data.Home_Away == "away" && data.Play_direction == "left"))
                    {
                        intermedio.global_right_endzone = this->home_team;
                        intermedio.global_left_endzone = this->away_team;
                    }

                    else
                    {
                        intermedio.global_right_endzone = this->away_team;
                        intermedio.global_left_endzone = this->home_team;
                    }

                }

                else if (data.Position == "P")
                {
                    if ((data.Home_Away == "home" && data.Play_direction == "right") || (data.Home_Away == "away" && data.Play_direction == "left"))
                    {
                        intermedio.global_right_endzone = this->home_team;
                        intermedio.global_left_endzone = this->away_team;
                    }

                    else
                    {
                        intermedio.global_right_endzone = this->away_team;
                        intermedio.global_left_endzone = this->home_team;
                    }
                }

                this->playersArt.push_back(playerArt);
                this->playersCircle.push_back(playerCircle);
                this->playersJersey.push_back(JerseyNumber);
                this->playersSpeed.push_back(playerSpeed);
                this->arrowsSpeed.push_back(arrowSpeed);
            }

        }

        else if (intermedio.selection_applied && this->activePlayType == "extrapoint")
        {
            if (data.FrameId == 11)
            {
                playerArt.setPosition((data.x) * 10, 106.6 + ((data.y) * 8));
                playerCircle.setPosition((data.x) * 10, 106.6 + ((data.y) * 8));
                JerseyNumber.setPosition(playerCircle.getPosition().x + playerCircle.getLocalBounds().width / 2, playerCircle.getPosition().y + playerCircle.getLocalBounds().height / 2);

                if (data.Home_Away == "home" || data.Home_Away == "away")
                {
                    playerCircle.setRadius(10.f);
                    JerseyNumber.setString(data.Jersey_Number);
                    JerseyNumber.setCharacterSize(10);
                    JerseyNumber.setPosition(
                        playerCircle.getPosition().x + (playerCircle.getGlobalBounds().width / 2.f) - JerseyNumber.getGlobalBounds().width / 2.f,
                        playerCircle.getPosition().y + (playerCircle.getGlobalBounds().height / 2.f) - JerseyNumber.getGlobalBounds().height / 2.f);

                    playerSpeed.setPosition(playerCircle.getPosition().x + playerCircle.getLocalBounds().width - 0.5,
                        playerCircle.getPosition().y + playerCircle.getLocalBounds().height / 2);

                    arrowSpeed.setRotation(90);
                    arrowSpeed.setPosition(playerSpeed.getPosition().x + playerSpeed.getLocalBounds().width + arrowSpeed.getLocalBounds().width, playerSpeed.getPosition().y - playerSpeed.getLocalBounds().height / 2 - arrowSpeed.getLocalBounds().height / 2);

                    playerSpeed.setSize(sf::Vector2f(data.s, 3.5));
                    playerSpeed.setRotation(data.dir - 90);

                    if (data.Home_Away == "home")
                    {
                        playerArt.setTexture(this->playerartHome_tex);

                        playerCircle.setFillColor(GetTeamColor(this->home_team));
                    }
                    else if (data.Home_Away == "away")
                    {
                        playerArt.setTexture(this->playerartAway_tex);
                        playerArt.setScale(-1.f, 1.f);

                        playerCircle.setFillColor(GetTeamColor(this->away_team));
                    }
                }
                else if (data.Home_Away == "football")
                {
                    playerArt.setTexture(this->ball_tex);

                    playerCircle.setRadius(7.f);
                    playerCircle.setFillColor(sf::Color(165, 42, 42));
                }
                else
                {
                    playerCircle.setRadius(0);
                }

                //Getting location of endzone
                if (data.Position == "K")
                {
                    if ((data.Home_Away == "home" && data.Play_direction == "right") || (data.Home_Away == "away" && data.Play_direction == "left"))
                    {
                        intermedio.global_right_endzone = this->home_team;
                        intermedio.global_left_endzone = this->away_team;
                    }

                    else
                    {
                        intermedio.global_right_endzone = this->away_team;
                        intermedio.global_left_endzone = this->home_team;
                    }

                }

                else if (data.Position == "P")
                {
                    if ((data.Home_Away == "home" && data.Play_direction == "right") || (data.Home_Away == "away" && data.Play_direction == "left"))
                    {
                        intermedio.global_right_endzone = this->home_team;
                        intermedio.global_left_endzone = this->away_team;
                    }

                    else
                    {
                        intermedio.global_right_endzone = this->away_team;
                        intermedio.global_left_endzone = this->home_team;
                    }
                }

                this->playersArt.push_back(playerArt);
                this->playersCircle.push_back(playerCircle);
                this->playersJersey.push_back(JerseyNumber);
                this->playersSpeed.push_back(playerSpeed);
                this->arrowsSpeed.push_back(arrowSpeed);
            }
        }


        //Establishing the position of the players for the pass play, making "pass" a play type
        else if (intermedio.selection_applied && this ->activePlayType == "pass")
        {
            if (data.FrameId == 11)
            {
                playerArt.setPosition((data.x) * 10, 106.6 + ((data.y) * 8));
                playerCircle.setPosition((data.x) * 10, 106.6 + ((data.y) * 8));
                JerseyNumber.setPosition(playerCircle.getPosition().x + playerCircle.getLocalBounds().width / 2, playerCircle.getPosition().y + playerCircle.getLocalBounds().height / 2);

                if (data.Home_Away == "home" || data.Home_Away == "away")
                {
                    playerCircle.setRadius(10.f);
                    JerseyNumber.setString(data.Jersey_Number);
                    JerseyNumber.setCharacterSize(10);
                    JerseyNumber.setPosition(
                        playerCircle.getPosition().x + (playerCircle.getGlobalBounds().width / 2.f) - JerseyNumber.getGlobalBounds().width / 2.f,
                        playerCircle.getPosition().y + (playerCircle.getGlobalBounds().height / 2.f) - JerseyNumber.getGlobalBounds().height / 2.f);

                    playerSpeed.setPosition(playerCircle.getPosition().x + playerCircle.getLocalBounds().width - 0.5,
                        playerCircle.getPosition().y + playerCircle.getLocalBounds().height / 2);

                    arrowSpeed.setRotation(90);
                    arrowSpeed.setPosition(playerSpeed.getPosition().x + playerSpeed.getLocalBounds().width + arrowSpeed.getLocalBounds().width, playerSpeed.getPosition().y - playerSpeed.getLocalBounds().height / 2 - arrowSpeed.getLocalBounds().height / 2);

                    playerSpeed.setSize(sf::Vector2f(data.s, 3.5));
                    playerSpeed.setRotation(data.dir - 90);

                    if (data.Home_Away == "home")
                    {
                        playerArt.setTexture(this->playerartHome_tex);

                        playerCircle.setFillColor(GetTeamColor(this->home_team));
                    }
                    else if (data.Home_Away == "away")
                    {
                        playerArt.setTexture(this->playerartAway_tex);
                        playerArt.setScale(-1.f, 1.f);

                        playerCircle.setFillColor(GetTeamColor(this->away_team));
                    }
                }
                else if (data.Home_Away == "football")
                {
                    playerArt.setTexture(this->ball_tex);

                    playerCircle.setRadius(7.f);
                    playerCircle.setFillColor(sf::Color(165, 42, 42));
                }
                else
                {
                    playerCircle.setRadius(0);
                }

                //Getting location of endzone
                if(data.Position == "K")
                {
                    if ((data.Home_Away == "home" && data.Play_direction == "right") || (data.Home_Away == "away" && data.Play_direction == "left"))
                    {
                        intermedio.global_right_endzone = this->home_team;
                        intermedio.global_left_endzone = this->away_team;
                    }

                    else
                    {
                        intermedio.global_right_endzone = this->away_team;
                        intermedio.global_left_endzone = this->home_team;
                    }
                }

                
                this->playersArt.push_back(playerArt);
                this->playersCircle.push_back(playerCircle);
                this->playersJersey.push_back(JerseyNumber);
                this->playersSpeed.push_back(playerSpeed);
                this->arrowsSpeed.push_back(arrowSpeed);
            }

        }
    }

    
}


void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
	/*this->shape.move(dir_x*this->movementSpeed * dt, dir_y*this->movementSpeed * dt);*/
    
}

void Entity::update(const float& dt, int sign)
{
    //Taking the last frame of each play in the vector
    this->frame_limit = tracking_vector.back().FrameId;

    //Updating the frame and not letting it go over the frame limit. The sign is to make it go forward or backwards based on user selection
    frame_index = (frame_index + sign) % (frame_limit);

    //Running through the tracking data and change position every frame to make the play run
    for (auto& data : this->tracking_vector)
    {
        if (data.FrameId == frame_index)
        {
            //Updating player shape
            playersCircle[j].setPosition(data.x * (10), (106.6)+(data.y*8));

            //Updating player jersey
            playersJersey[j].setPosition(
                playersCircle[j].getPosition().x + (playersCircle[j].getGlobalBounds().width / 2.f) - playersJersey[j].getGlobalBounds().width / 2.f,

                playersCircle[j].getPosition().y + (playersCircle[j].getGlobalBounds().height / 2.f) - playersJersey[j].getGlobalBounds().height / 2.f);

            //Updating player speed/orientation sign
            if (playersSpeed[j].getSize() != sf::Vector2f(0, 0))
            {
                playersSpeed[j].setPosition(
                    playersCircle[j].getPosition().x + playersCircle[j].getGlobalBounds().width,
                    playersCircle[j].getPosition().y + playersCircle[j].getGlobalBounds().height / 2.f);

                playersSpeed[j].setSize(sf::Vector2f(data.s * 7, 3.5));
                playersSpeed[j].setRotation(data.dir - 90);
            }

            //Updating player speed/orientation arrow
            arrowsSpeed[j].setPosition(playersSpeed[j].getPosition().x + playersSpeed[j].getGlobalBounds().width + arrowsSpeed[j].getGlobalBounds().width, 
                playersSpeed[j].getPosition().y - playersSpeed[j].getGlobalBounds().height / 2 - arrowsSpeed[j].getGlobalBounds().height / 2);
          
            j = (j + 1) % (playersCircle.size());
            
        }
    }


}

void Entity::render(sf::RenderTarget* target)
{
    //for (const auto& JerseySpeed : this->playersSpeed)
    //{
    //    target->draw(JerseySpeed);
    //}

    for (const auto& player : this->playersCircle)
    {
        target->draw(player);
    }

    for (const auto& JerseyNumber : this->playersJersey)
    {
        target->draw(JerseyNumber);
    }

    for (const auto& arrowSpeed : this->arrowsSpeed)
    {
        /*target->draw(arrowSpeed);*/
    }

    //for (const auto& playerOrientation : this->playersMarkers)
    //{
    //    target->draw(playerOrientation);
    //}
    //target->draw(this->test);
    //target->draw(this->orientationTest);
   
}

void Entity::initTrackingFileKey()
{
 
}


