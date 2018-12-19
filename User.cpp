#include "User.h"


User::User()
{
	std::ifstream inFile;
	inFile.open("UserLog.txt");
	if (inFile.is_open())
	{
		std::getline(inFile, username);
		if (username.empty())
		{
			do {
				std::cout << "Plese insert your username:" << std::endl;
				std::cin >> username;
			} while (!validUsername(username));
			inFile.close();
			std::ofstream outFile;
			outFile.open("UserLog.txt");
			outFile << username << std::endl << "0";
			outFile.close();
		}
		else
		{
			std::string temp;
			std::getline(inFile, temp);
			points = std::stoi(temp);
			inFile.close();
		}
	}
	else
	{
		std::cout << "File didn't open successfully" << std::endl;
	}
}

void User::setPoint(int points)
{
	this->points = points;
	std::ofstream outFile;
	outFile.open("UserLog.txt");
	outFile << this->username << std::endl << std::to_string(points);
	outFile.close();
}



bool User::validUsername(std::string& username)
{
	if (username.length() > 20 || std::isdigit(username.at(0)) || hasSpecialChar(username))
	{
		std::cout << "Your username is not valid, try replacing the first character with a letter, or reducing the size of the name or dropping special characters." << std::endl;
		return false;
	}
	return true;
}


bool User::hasSpecialChar(std::string const &str) {
	return std::find_if(str.begin(), str.end(), [](char ch) { return !(isalnum(ch) || ch == '_'); }) != str.end();
}

User::~User()
{
}
