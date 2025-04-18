/*FileName:Chapter6Exercise24.cpp
Programmer Name:Charles Sherwood
Date:4/2025
Requirements:This Program shoudl act
like a game of rock paper scissors.
*/

//#include<string>
#include<cstdlib>
#include<ctime>
#include <iostream>

using namespace std;


//Prototypes
int Menu();
int CompsChoice(int RChoice);
int RandomNum();
void Welcome();
bool Repeat();
void Winner(int choice,int ComChoice);



int main(int choice)
{
    srand(time(0));
   Welcome();
   do
   {
       int ComChoice = RandomNum();
       int choice = Menu();
       int DisplayChoice=CompsChoice(ComChoice);
       Winner(choice, ComChoice);
   } while (Repeat());

}


//Takes Computer Choice And Displays What It Chose
int CompsChoice(int RChoice)
{
    if (RChoice == 1)
    {
        cout << "\nThe Computer Chose Rock\n";
    }
    else if (RChoice == 2)
    {
        cout << "The Computer Chose Paper\n";
    }
    else
    {
        cout << "The Computer Chose Scissors\n";
    }
    return RChoice;
}

 
//Generates A Random Num Between 1 and 3
int RandomNum()
{
     return (rand() % 3 + 1);
}


 
//Displays A Welcome Message
void Welcome()
{
    cout << "----------------------------------\n";
    cout << "!!Welcome To Rock,Paper,Scissors!!\n";
    cout << "----------------------------------\n";
}



//Displays The Choices Of The Game
int Menu()
{
    int choice;
        cout << "\nPlease Make A Choice From Below\n";
        cout << "------------------\n";
        cout << "1-Rock\n";
        cout << "2-Paper\n";
        cout << "3-Scissors\n";
        cout << "------------------\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "You Have Chosen Rock\n";
        }
        break;
        case 2:
        {
            cout << "You Have Chosen Paper\n";

        }
        break;

        case 3:
        {
            cout << "You Have Chosen Scissors\n";
        }
        break;

        //Checks If The User Enters A Number Thats not On The List
        default:
        {
            while (choice > 3)
            {
                cout << "Invalid Option Please Make A choice Thats On The Menu:";
                cin >> choice;
            }
        }


        }
        return choice;

}


//Checks The User Choice Vs The Computers Choice
void Winner(int choice,int ComChoice)
{
    if (choice == 1 && ComChoice == 2 || choice == 3 && ComChoice == 1 || choice == 2 && ComChoice == 3)
    {
        cout << "\n---------------------\n";
        cout << "!!The Computer Wins!!\n";
        cout << "---------------------\n";
    }
    else if (choice == 2 && ComChoice == 1 || choice == 3 && ComChoice == 2 || choice == 1 && ComChoice == 3)
    {
        cout << "\n-----------\n";
        cout << "!!YOU WIN!!\n";
        cout << "-----------\n";
    }
    else
    {
        cout << "\n----------------\n";
        cout << "!!It Was A Tie!!\n";
        cout << "----------------\n";
    }
}



//Ask The USer If They Want To Play Again
bool Repeat()
{
    char repeat;
    cout << "Would You Like To Play Again Y/N?:";
    cin >> repeat;
    return repeat == 'Y' || repeat == 'y';
}
