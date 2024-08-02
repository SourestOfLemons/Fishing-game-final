# include<iostream>
#include<fstream>
#include"CreateChar.h"
#include"BeginGame.h"
using namespace std;

int main() {

	ifstream File("CharacterInformation.txt");
	//define the file that the character's information is stored in.
	int id;
	string name;
	double money;
	//create the variables for the file. They are empty now as they don't need to have anything in them.

	while(File >> id >> name >> money) {

		cout << "- " << name << ", you have " << money << " dollars," << " you have caught " << id << " fish." << endl;
		//this will read out this line for each filled out line in the player information file.
	}

	cout << "would you like to create a new character or use the one above?" << endl;

	bool playerchoice{ false };
	string playerchoice2;

	while(!playerchoice) {

		cout << "press '1' to use above character and press '2' to make another one." << endl;
		cin >> playerchoice2;

		if (playerchoice2 == "1") {

			cout << "Starting..." << endl << endl;
			playerchoice = true;
			BeginGame();

		}

		else if (playerchoice2 == "2") {

			cout << "Creating new character..." << endl << endl;
			cout << "what would you like to name this character? ";

			string newname;
			cin >> newname;
			CreateCharacter(newname);
			playerchoice = true;
		}
		else
			cout << "invalid option. Please press either '1' or '2'." << endl;
	}

	return 0;
}