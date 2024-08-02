# include<iostream>
#include<fstream>
#include <chrono>
#include <thread>


#include"FishingACT.h"
#include"BeginGame.h"

using namespace std;

int Fish(string Location) {

	ifstream File("CharacterInformation.txt");

	int id;
	string name;
	double money;
	string Rod;
	int rodmin;
	int rodmax;

	while (File >> id >> name >> money >> Rod >> rodmin >> rodmax) {
		//the code above reads out each word as a variable but only uses the rod one unfortunately
		cout << "You cast your " << Rod << " into the " << Location << endl;
		//cout << "you are going to wait for between " << rodmin << " and " << rodmax << endl;
	}

	srand(time(0));
	int waitingtime;
	int fishtype;

	waitingtime = rand() % (rodmax - rodmin + 1) + rodmin;
	fishtype = rand() % (rodmax - rodmin + 1) + rodmin;

	this_thread::sleep_for(std::chrono::seconds(waitingtime));
	//make it wait for the random amount of time.


	string retry;
	bool chosen{false};
	string caughtfish;

	if (fishtype == 1) {
		caughtfish = { "Working-Violin" };
	}
	else if (fishtype == 2) {
		caughtfish = { "Salmon" };
	}
	else if (fishtype == 3) {
		caughtfish = { "Tuna" };
	}
	else if (fishtype == 4) {
		caughtfish = { "Tin-Can" };
	}
	else if (fishtype == 5) {
		caughtfish = { "Fish-Skeleton" };
	}
	else if (fishtype == 6) {
		caughtfish = { "Shark" };
	}
	else if (fishtype == 7) {
		caughtfish = { "flesh" };
	}
	else if (fishtype == 8) {
		caughtfish = { "bucket-of-chum" };
	}
	else if (fishtype == 9) {
		caughtfish = { "Old-Mug" };
	}
	else if (fishtype == 10) {
		caughtfish = { "old-boot" };
	}
	else if (fishtype == 0) {
		caughtfish = { "Shark" };
	}

	File.close(); //close the last file so that I can open the next

	cout << "after " << waitingtime << " seconds, you catch a " << caughtfish << " at " << Location << endl << endl;
	ofstream FishFile("Fish.txt", std::ios::app);
	FishFile << caughtfish << endl;
	FishFile.close(); //close the fish file
	


	ofstream file("CharacterInformation.txt", std::ofstream::out | std::ofstream::trunc);

	file << id + 1 << " " << name << " " << money << " " << Rod << " " << rodmin << " " << rodmax << std::endl;
	
	while (chosen == false) {
		cout << "(1) Head back home or (2) fish again? ";
		cin >> retry;
		if (retry == "1") {
			BeginGame();
		}
		else if (retry == "2") {
			Fish("Beach");
		}
	}
	BeginGame();

	return 0;
}