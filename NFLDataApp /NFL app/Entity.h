#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <algorithm>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML\Network.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include "DataMedium.h"

using namespace std;

/*Everything starts here. An entity is an object (player, shape,etc) with a specific movement 
and that will be updated according to something*/

    class Entity
    {
private:

    DataMedium intermedio;

protected:

    //Tracking file management
    string DefaultName;
    string DefaultPlayType;
    string activePlay;
    int activeGameKey;
    string activeFileName;
    string activePlayType;

    //Shapes
    sf::Vector2f TempBallPosition;

    //Textures
    sf::Texture playerartHome_tex;
    sf::Texture playerartAway_tex;
    sf::Texture ball_tex;
    sf::Texture OrientationMarker_tex;

    //Variables
    int frame_index;
    int j;
    int k;
    int frame_limit;
    float playerDotRadius;


    std::string home_team;
    std::string away_team;

    //Fonts
    sf::Font font;
    
    
    //Object created (a rectangle)
    vector<sf::Sprite> playersArt;
    vector<sf::Sprite> playersMarkers;
    vector<sf::CircleShape> playersCircle;
    vector<sf::Text> playersJersey;
    vector<sf::RectangleShape> playersSpeed;
    vector<sf::CircleShape>arrowsSpeed;

    sf::RectangleShape shape;
    sf::CircleShape test;

    sf::Sprite orientationTest;

    //Orientation marker
    sf::RectangleShape UpperLine;
    sf::RectangleShape LowerLine;

    
    
    //Speed for this object
    float movementSpeed;

    //Data
    //Struct for tracking data

    struct TrackingData {
    public:
        TrackingData(

            string time,
            double x_position,
            double y_position,
            double speed,
            double acceleration,
            double distance,
            double orientation,
            double direction,
            string event,
            int nfl_id,
            string name,
            string jersey_number,
            string position,
            string home_away,
            int frameId,
            int gameId,
            int playId,
            string play_direction,
            double x_velocity,
            double y_velocity

        ) {
            Time = time;
            x = x_position;
            y = y_position;
            s = speed;
            a = acceleration;
            dis = distance;
            o = orientation;
            dir = direction;
            Event = event;
            NFL_id = nfl_id;
            Name = name;
            Jersey_Number = jersey_number;
            Position = position;
            Home_Away = home_away;
            FrameId = frameId;
            GameId = gameId;
            PlayId = playId;
            Play_direction = play_direction;
            X_velocity = x_velocity;
            Y_velocity = y_velocity;


        }



        string Time;
        double x;
        double y;
        double s;
        double a;
        double dis;
        double o;
        double dir;
        string Event;
        int NFL_id;
        string Name;
        string Jersey_Number;
        string Position;
        string Home_Away;
        int FrameId;
        int GameId;
        int PlayId;
        string Play_direction;
        double X_velocity;
        double Y_velocity;


    };
    vector<TrackingData> tracking_vector;

    map<int, string> gameID_game_map;

    //Tracking files
    ifstream tracking_file;


    public:


    //Variables

    //Constructor
    Entity();

    //Deconstructor
    virtual ~Entity();


    //Functions

    //Initializers
    void setActivePlayFile();
    void initFiles();
    void initData();
    void initTrackingFileKey();

    //Function to move our object
    void move(const float& dt, const float x, const float y);

    //Update and rendering
	void update(const float& dt, int sign) ;
	void render(sf::RenderTarget* target) ;
    
    sf::Color GetTeamColor(std::string& input);
};
#endif

