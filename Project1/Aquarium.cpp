# include<iostream>
#include<fstream>
#include"BeginGame.h"
#include"Aquarium.h"
using namespace std;

int VisitAquarium() {
	string Choice;
	bool HasChosen{ false };

	while (!HasChosen) {
		cout << "Would you like to \n(1) See inventory \n(2) See aquarium \n(3) Transfer fish \n(4) Return to the trainstation ";
		cin >> Choice;
		if (Choice == "1") {
			cout << "okay you look at your inventory \n \n";

			ifstream FishyFile("Fish.txt");
			string fishyfish;
			//create the variables for the file. They are empty now as they don't need to have anything in them.

			cout << "You look in your massive pockets and see a ";

			while (FishyFile >> fishyfish) {

				cout << fishyfish << ", a ";
				//this will read out this line for each filled out line in the player information file.
			}

			FishyFile.close();

		}
		if (Choice == "2") {
			cout << "okay you look at the aquarium \n \n";

			ifstream File("Aquarium.txt");
			string fish;
			//create the variables for the file. They are empty now as they don't need to have anything in them.

			cout << "You look apon your aquarium and you see the fish you have stored, ";

			while (File >> fish) {

				cout << fish << ", a ";
				//this will read out this line for each filled out line in the player information file.
			}
			File.close();

		}
		if (Choice == "3") {

			string choice2;
			bool HasChosen2{ false };

			while (!HasChosen2) {
				cout << "do you want to (1) take or (2) store fish ";
				cin >> choice2;

				if (choice2 == "1") {

					ifstream Inventory("Aquarium.txt");
					ofstream Aquarium("Fish.txt", std::ios::app);

					string heldfish;

					while (Inventory >> heldfish) {
						Aquarium << heldfish << endl;
						// This will write this line for each filled out line in the player information file.
					}

					Inventory.close();
					Aquarium.close();

					ofstream ClearInventory("Aquarium.txt", std::ofstream::out | std::ofstream::trunc);
					ClearInventory.close();
					cout << "You claim all of your well-earned fish back. \n \n";
					VisitAquarium();
				}

				if (choice2 == "2") {

					ifstream Inventory("Fish.txt");
					ofstream Aquarium("Aquarium.txt", std::ios::app);
					
					string heldfish;

					while (Inventory >> heldfish) {
						Aquarium << heldfish << endl;
						// This will write this line for each filled out line in the player information file.
					}

					Inventory.close();
					Aquarium.close();

					ofstream ClearInventory("Fish.txt", std::ofstream::out | std::ofstream::trunc);
					ClearInventory.close();
					cout << "You place your fish one-by-one into the pools. \n \n";
					VisitAquarium();
				}


			}
			
		}
		if (Choice == "4") {
			cout << "okay you go home now";
			BeginGame();
		}
		else {
			cout << "Invalid responce. \n";
		}

	}
	
	return 0;
}