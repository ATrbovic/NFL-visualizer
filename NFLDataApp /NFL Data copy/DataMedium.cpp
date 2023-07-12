#include "DataMedium.h"

// Define a static map to store integer keys and corresponding string values.
std::map<int, std::string> DataMedium::GameStateKeysTemporal2 = { {1, "one"} };

// Initialize a static boolean variable to false.
bool DataMedium::selection_applied = false;

// Define a static pair to store an integer and an empty string.
std::pair<int, std::string> DataMedium::GameStateKeysTemporal22 = std::make_pair(0, "");

// Initialize a static string variable.
std::string DataMedium::GameSelectedGlobal = "";

// Define a static pair to store two empty strings.
std::pair<std::string, std::string> DataMedium::home_away_teams = std::make_pair("", "");

// Initialize two static string variables.
std::string DataMedium::global_left_endzone = "";
std::string DataMedium::global_right_endzone = "";

// Define the constructor for the DataMedium class.
DataMedium::DataMedium()
{
}


