#include <iostream>
#include <string>
#include <fstream>
#include "Source.h"

using namespace std;
int currentNewUser = 0;
string user;
string playerOne, playerTwo, playerThree, playerFour, playerFive;
string accounts[5] = {playerOne, playerTwo, playerThree, playerFour, playerFive};

int main() {

	//WriteToFile();
	
	//ReadFile();

	NameAccept();


}

void NameAccept()
{
	cout << "Give me a name" << endl;
	cin >> user;
	cout << endl;
	cout << "You have given me the name, " << user << "." << endl;
	cout << "Is this correct?  Cool." << endl;

	ofstream MyFile("Player_Names_Test.txt");

	NewerUserCheck();

	// assign user to player slot
	accounts[currentNewUser] == user;
	MyFile << currentNewUser + 1 << ". " << user << endl;
	MyFile.close();

	ReadFile();
}

void NewerUserCheck()
{
	if (accounts[currentNewUser] == "") {
		cout << "New user being created in space "<< accounts[currentNewUser] << endl;
		system("Pause");
	}
	else{
		currentNewUser++;
		NewerUserCheck();
	}
}

// This reads the file and prints it to the screen for the user.
void ReadFile()
{
	string myText;

	// Read from the text file
	ifstream MyReadFile("Player_Names_Test.txt");

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {
		// Output the text from the file
		cout << myText << endl;
	}

	// Close the file
	MyReadFile.close();
}


void WriteToFile()
{
	// File is created here
	ofstream MyFile("Filename.txt");

	MyFile << "This is the first line of my file." << endl;
	MyFile << "This is the second line of my file." << endl;
	MyFile << "This is the third line of my file." << endl;

	MyFile.close();
}

