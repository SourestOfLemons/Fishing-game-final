# include<iostream>
#include<fstream>
#include"CreateChar.h"
#include"BeginGame.h"
using namespace std;

int CreateCharacter(string name) {
	ofstream file("CharacterInformation.txt", std::ofstream::out | std::ofstream::trunc);
	file << "0 " << name << " 0.30 Wooden_Pole 6 9" << std::endl;
	// Close the file
	file.close();

	ofstream FishFile("Fish.txt", std::ofstream::out | std::ofstream::trunc);
	// Close the file
	FishFile.close();

	ofstream FishierFile("Aquarium.txt", std::ofstream::out | std::ofstream::trunc);
	// Close the file
	FishierFile.close();


	BeginGame();
	return 0;
}