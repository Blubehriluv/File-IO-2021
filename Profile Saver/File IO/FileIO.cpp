#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include "FileIO.h"

int currentNewUser = 0;
const int maxAccountNumber = 5;
std::string user;																							// Represents the actions of the current user
std::string playerOne, playerTwo, playerThree, playerFour, playerFive;										// Holds names of players to be pulled from Array
std::string accounts[maxAccountNumber] = { playerOne, playerTwo, playerThree, playerFour, playerFive };		// Array to hold player names, account register limit

// Main function that runs the program
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
	// The program takes the user input and assigns it to user
	std::cin >> user;
	std::cout << std::endl;
	std::cout << "You have given me the name, " << user << "." << std::endl;
	std::cout << "Is this correct?  Cool." << std::endl;

	// Ofstream is creating the file Player Names Test
	std::ofstream MyFile("Player_Names_Test.txt", std::ios_base::app);

	// Calls the function that begins the process of adding a new account
	AddNewUser(MyFile);
}

// Program checks to see if the user is new, and if new, adds them to the database
void AddNewUser(std::ofstream& MyFile)
{
	// Space is available and a new account will be added (The opening is blank)
	if (accounts[currentNewUser] == "") {
		std::cout << "New user being created in space ' " << currentNewUser << " '." << std::endl;
		system("Pause");
	}
	// Space is not available because the final slot is filled (The opening is not blank)
	else if (accounts[currentNewUser] != "") {
		std::cout << "No more accounts can be created on this system." << std::endl;
		system("Pause");
	}
	// This right now just makes the program loop to keep accepting answers
	else {
		// Change this to kick back out to the main menu.
		NewUserCheck();
	}

	// Assign user to player slot
	accounts[currentNewUser] == user;
	MyFile << currentNewUser + 1 << ". " << user << "\n" << std::endl;
	currentNewUser++;
	std::cout << currentNewUser << std::endl;
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
		if (maxAccountNumber == currentNewUser) {
			std::cout << "Sorry, we aren't accepting any new accounts." << std::endl;
			system("Pause");
			ExitProgram();
		}
		else {
			NameAccept();
		}
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
	NewUserCheck();
}

void ExitProgram() {
	std::cout << "Thank you!" << std::endl;
	std::cout << "Exiting program" << std::endl;
}