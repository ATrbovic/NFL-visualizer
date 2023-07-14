#pragma once

#include <iostream>
#include <ctime>
#include<cstdlib>
#include <sstream>
#include <map>

// The DataMedium class represents a data storage medium.

class DataMedium
{
private:
	// No private members in this class for now.

public:
	// Define static variables and functions accessible from anywhere.

	// A map to store integer keys and corresponding string values.
	static std::map<int, std::string> GameStateKeysTemporal2;

	// A boolean flag indicating whether a selection has been applied.
	static bool selection_applied;

	// A string variable to store the globally selected game.
	static std::string GameSelectedGlobal;

	// A pair to store an integer and a string.
	static std::pair<int, std::string> GameStateKeysTemporal22;

	// A pair to store two strings representing home and away teams.
	static std::pair<std::string, std::string> home_away_teams;

	// Two string variables to store the names of the left and right endzones.
	static std::string global_right_endzone;
	static std::string global_left_endzone;

	// A static function to convert a string to uppercase.
	static std::string toUpperCase(const std::string& input)
	{
		std::string result = input;
		for (char& c : result)
		{
			c = std::toupper(c);
		}
		return result;
	}

	//Variables
	
	// Default constructor for the DataMedium class.
	//Functions
	DataMedium();

};


