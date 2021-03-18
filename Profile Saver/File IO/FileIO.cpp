#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include "FileIO.h"

int currentNewUser = 0;
std::string user;
std::string playerOne, playerTwo, playerThree, playerFour, playerFive;
std::string accounts[5] = { playerOne, playerTwo, playerThree, playerFour, playerFive };


int main() {

	Introduction();

	NewUserCheck();

}

// Introduces the user to the program and tells them what is going to happen
void Introduction()
{
	std::cout << "Welcome to Kodopetto!" << std::endl;
	std::cout << "You will be registering an account" << std::endl;
	std::cout << "ahead of time for the official release!" << std::endl;
	std::cout << "Your code pet can't wait to meet you!" << std::endl;
}

// Requests and accepts a name from the player to be added to the list
void NameAccept()
{
	std::cout << "Give me a name" << std::endl;
	std::cin >> user;
	std::cout << std::endl;
	std::cout << "You have given me the name, " << user << "." << std::endl;
	std::cout << "Is this correct?  Cool." << std::endl;

	std::ofstream MyFile("Player_Names_Test.txt");

	AddNewUser(MyFile);
}

// This is the process of the program adding the name to the 
void AddNewUser(std::ofstream& MyFile)
{
	if (accounts[currentNewUser] == "") {
		std::cout << "New user being created in space ' " << currentNewUser << " '." << std::endl;
		system("Pause");
	}
	else {
		currentNewUser++;
		NewUserCheck();
	}

	// assign user to player slot
	accounts[currentNewUser] == user;
	MyFile << currentNewUser + 1 << ". " << user << std::endl;
	MyFile.close();

	ReadFile();
}

void NewUserCheck()
{
	std::string userInput;
	std::cout << "Are you new?" << std::endl;
	std::cout << "'y' or 'n'?" << std::endl;
	std::cin >> userInput;
	std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

	if (userInput == "N" || userInput == "NO") {
		ExitProgram();
	}
	else if (userInput == "Y" || userInput == "YES") {
		NameAccept();
	}
	else {
		std::cout << "Please enter yes or no." << std::endl;
		NewUserCheck();
	}
}

void ReadFile()
{
	std::string myText;

	// Read from the text file
	std::ifstream MyReadFile("Player_Names_Test.txt");

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {
		// Output the text from the file
		std::cout << myText << std::endl;
	}

	// Close the file
	MyReadFile.close();
}

void ExitProgram() {
	std::cout << "Thank you!" << std::endl;
	std::cout << "Exiting program" << std::endl;
}