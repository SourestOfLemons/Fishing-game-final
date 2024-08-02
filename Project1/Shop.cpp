#include <iostream>
#include <fstream>
#include <string>
#include "BeginGame.h"
#include "Shop.h"

using namespace std;

int VisitShop() {
    bool chosen{ false };
    string choice;
    if (!chosen) {
        cout << "Would you like to (1) sell all fish or (2) See shop or (3) return to trainstation? ";
        cin >> choice;

        if (choice == "1") {
    


            ifstream Inventory("Fish.txt");
            if (!Inventory) {
                cerr << "Failed to open Fish.txt" << endl;
                return -1;
            }

            string heldfish;
            int fishCount = 0;

            // Count the number of fish in the inventory
            while (Inventory >> heldfish) {
                fishCount++;
            }
            Inventory.close();

            int id;
            string name;
            double money;
            string Rod;
            int rodmin;
            int rodmax;

            ifstream invfile("CharacterInformation.txt");
            if (!invfile) {
                cerr << "Failed to open CharacterInformation.txt" << endl;
                return -1;
            }

            invfile >> id >> name >> money >> Rod >> rodmin >> rodmax;
            invfile.close();

            // Update money based on the number of fish
            money += fishCount;

            ofstream Information("CharacterInformation.txt", std::ios::trunc);
            if (!Information) {
                cerr << "Failed to open CharacterInformation.txt for writing" << endl;
                return -1;
            }

            // Write the updated character information
            Information << id << " " << name << " " << money << " " << Rod << " " << rodmin << " " << rodmax << endl;
            Information.close();

            // Clear the inventory file
            ofstream ClearInventory("Fish.txt", std::ofstream::out | std::ofstream::trunc);
            if (!ClearInventory) {
                cerr << "Failed to open Fish.txt for writing" << endl;
                return -1;
            }
            ClearInventory.close();

            cout << "You sell your garbage. \n \n";
            VisitShop();
            
        }
        else if (choice == "2") {
            string choice2;
            bool chosen2{ false };
            ifstream NewFileLi("CharacterInformation.txt");
            //define the file that the character's information is stored in.
            int idd;
            string namee;
            double moneyy;
            //create the variables for the file. They are empty now as they don't need to have anything in them.

            NewFileLi >> idd >> namee >> moneyy;
            NewFileLi.close();

            while (!chosen2) {
                cout << "Welcome to my shop! You can buy: \n \n(1) Regular fishing rod $30 \n(2) Golden fishing rod $60 \n \n(3) to exit (you have " << moneyy << " dollars.) ";
                cin >> choice2;
                if (choice2 == "1") {
                    cout << "okay \n";


                    ifstream File("CharacterInformation.txt");
                    //define the file that the character's information is stored in.
                    int id;
                    string name;
                    double money;
                    //create the variables for the file. They are empty now as they don't need to have anything in them.

                    File >> id >> name >> money;
                    File.close();

                    if (money > 30) {
                        cout << "\nyou have money \n";
                        double deductedmoney{ money - 30 };
                        cout << "now you only have " << deductedmoney << " dollars left." << endl;

                        ofstream file("CharacterInformation.txt", std::ofstream::out | std::ofstream::trunc);
                        file << id << " " << name << " " << deductedmoney << " Fishing_Rod 3 5" << std::endl;
                        file.close();
                    }
                    else {
                        cout << "\nYou have no money fool \n";
                    }
                    choice2 = { false };
                }
                else if (choice2 == "2") {
                    cout << "\nokay gfold\n";


                    ifstream GoldFile("CharacterInformation.txt");
                    //define the file that the character's information is stored in.
                    int iid;
                    string nname;
                    double mmoney;
                    //create the variables for the file. They are empty now as they don't need to have anything in them.

                    GoldFile >> iid >> nname >> mmoney;
                    GoldFile.close();

                    if (mmoney > 60) {
                        cout << "\nyou have money \n";
                        double deductedmoney2 { mmoney - 60 };
                        cout << "now you only have " << deductedmoney2 << " dollars left." << endl;

                        ofstream plfile("CharacterInformation.txt", std::ofstream::out | std::ofstream::trunc);
                        plfile << iid << " " << nname << " " << deductedmoney2 << " Block-of-gold 0 2" << std::endl;
                        plfile.close();
                    }
                    else {
                        cout << "\nYou have no money fool \n";
                    }
                    choice2 = { false };
                }
                else if (choice2 == "3") {
                    cout << "okay go home";
                    choice2 = { false };
                    BeginGame();
                }
                else {
                    cout << "Invalid option.";
                }
                VisitShop();
            }
            
        }
        else if (choice == "3") {
            BeginGame();
        }
        else {
            cout << "Invalid responce";
        }
        return 0;
    }
}
