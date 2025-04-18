/*FileName:Chapter6Exercise24.cpp
Programmer Name:Charles Sherwood
Date:4/2025
Requirements:This Revised Branch Should Get The Users name 
And Save How Many Times They Have Won. I will also add the ability
to get their losses and ties as well and keep a record of that.
*/

#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

//Prototypes
int Menu();
int CompsChoice(int RChoice);
int RandomNum();
void Welcome();
bool Repeat();
void Winner(int choice, int ComChoice, int& Win, int& Lose, int& Tie);
string GetName();
void SaveData(const string& name, int Win, int Lose, int Tie);
void ShowSavedData();

int main()
{
    srand(time(0));
    Welcome();
    string playerName = GetName();
    int Win = 0, Lose = 0, Tie = 0;

    do {
        int ComChoice = RandomNum();
        int choice = Menu();
        if (choice == 4) {
            ShowSavedData();
            continue;
        }
        int DisplayChoice = CompsChoice(ComChoice);
        Winner(choice, ComChoice, Win, Lose, Tie);
        SaveData(playerName, Win, Lose, Tie);
    } while (Repeat());

    return 0;
}

//Gets the user to input their name
string GetName()
{
    string name;
    cout << "Please Enter Your Name: ";
    cin.ignore();
    getline(cin, name);
    return name;
}

//Displays computer's choice
int CompsChoice(int RChoice)
{
    if (RChoice == 1)
        cout << "\nThe Computer Chose Rock\n";
    else if (RChoice == 2)
        cout << "The Computer Chose Paper\n";
    else
        cout << "The Computer Chose Scissors\n";
    return RChoice;
}

//Chooses A Random Number Between 1 and 3
int RandomNum()
{
    return (rand() % 3 + 1);
}

//Displays A Welcome message
void Welcome()
{
    cout << "----------------------------------\n";
    cout << "!!Welcome To Rock, Paper, Scissors!!\n";
    cout << "----------------------------------\n";
}

//The Menu For The Users Choice
int Menu()
{
    int choice;
    cout << "\nPlease Make A Choice From Below\n";
    cout << "------------------\n";
    cout << "1 - Rock\n";
    cout << "2 - Paper\n";
    cout << "3 - Scissors\n";
    cout << "4 - View Saved Records\n";
    cout << "------------------\n";
    cin >> choice;

    while (choice < 1 || choice > 4)
    {
        cout << "Invalid Option. Please Make A Choice That's On The Menu: ";
        cin >> choice;
    }

    return choice;
}

//Checks To See Who Won And Keeps Counter For The Game 
void Winner(int choice, int ComChoice, int& Win, int& Lose, int& Tie)
{
    if (choice == 1 && ComChoice == 2 || choice == 3 && ComChoice == 1 || choice == 2 && ComChoice == 3)
    {
        cout << "\n---------------------\n";
        cout << "!!The Computer Wins!!\n";
        cout << "---------------------\n";
        Lose++;
    }
    else if (choice == 2 && ComChoice == 1 || choice == 3 && ComChoice == 2 || choice == 1 && ComChoice == 3)
    {
        cout << "\n-----------\n";
        cout << "!!YOU WIN!!\n";
        cout << "-----------\n";
        Win++;
    }
    else
    {
        cout << "\n----------------\n";
        cout << "!!It Was A Tie!!\n";
        cout << "----------------\n";
        Tie++;
    }

    cout << "Current Record - Wins: " << Win << ", Losses: " << Lose << ", Ties: " << Tie << "\n";
}

// Saves data to file With Multiple people
void SaveData(const string& name, int Win, int Lose, int Tie)
{
    ofstream File("SavedData.txt", ios::app); // append mode

    if (!File) {
        cerr << "Error: Could not open file.\n";
        return;
    }

    File << "------------------------\n";
    File << "Player: " << name << "\n";
    File << "Wins: " << Win << "\n";
    File << "Losses: " << Lose << "\n";
    File << "Ties: " << Tie << "\n";
    File << "------------------------\n\n";

    File.close();

    cout << "\nGame record saved to 'SavedData.txt'\n";
}

//Displays The Wins and losses 
void ShowSavedData()
{
    ifstream File("SavedData.txt");

    if (!File) {
        cerr << "Error: Could not open file to read.\n";
        return;
    }

    cout << "\n----- Saved Player Records -----\n";
    string line;
    while (getline(File, line)) {
        cout << line << endl;
    }
    cout << "--------------------------------\n";

    File.close();
}



//Ask The User If They Want To Play Again
bool Repeat()
{
    char repeat;
    cout << "Would You Like To Play Again (Y/N)?: ";
    cin >> repeat;
    return repeat == 'Y' || repeat == 'y';
}
