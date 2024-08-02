# include<iostream>
#include<fstream>
#include"BeginGame.h"
#include"FishingACT.h"
#include"Aquarium.h"
#include"Shop.h"
using namespace std;

int BeginGame() {

	cout << "You arrive at the trainstation. \n";
	bool DailyChoice { false };
	string ChoiseNumber;
	ifstream File("CharacterInformation.txt");
	//define the file that the character's information is stored in.
	int id;
	string name;
	double money;
	//create the variables for the file. They are empty now as they don't need to have anything in them.

	while (File >> id >> name >> money) {

		cout << "- " << name << ", you have " << money << " dollars," << " you have caught " << id << " fish." << endl;
		//this will read out this line for each filled out line in the player information file.
	}
	File.close();

	while (!DailyChoice) {

		cout << "What would you like to do today ? \n(1) Go fishing \n(2) Go out to your aquarium \n(3) Go to the shop \n";
		cin >> ChoiseNumber;

		if (ChoiseNumber == "1") {
			cout << "You take the first train to the beach. \n \n \n \n \n";
			DailyChoice = { true };
			Fish("Beach");
		}
		else if (ChoiseNumber == "2") {
			cout << "You walk back home to your aquarium. \n \n \n \n \n";
			DailyChoice = { true };
			VisitAquarium();
		}
		else if (ChoiseNumber == "3") {
			cout << "You take the first train to the shop. \n \n \n \n \n";
			DailyChoice = { true };
			VisitShop();
		}
		else {
			cout << "Invalid choise, please chose either '1', '2', or '3'. \n";
		}


	}

		

		
	return 0;
}