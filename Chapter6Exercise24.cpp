/*FileName:Chapter6Exercise24.cpp
Programmer Name:Charles Sherwood
Date:4/2025
Requirements:This Program shoudl act
like a game of rock paper scissors.
*/

#include<string>
#include<cstdlib>
#include<ctime>
#include <iostream>

using namespace std;


void Menu();
int CompsChoice();
void Welcome();
bool Repeat();

int main()
{
    srand(time(NULL));
    
    



}

int CompsChoice()
{
    return (rand() % 3 + 1);
}
void Welcome()
{

}
//Displays The Choices Of The Game
void Menu()
{
    int choice;
    do
    {
        cout << "1-Rock\n";
        cout << "2-Paper\n";
        cout << "3-Scissors\n";
        cout << "4-Exit The Game\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {

        }
            break;
        case 2:
        {

        }
            break;

        case 3:
        {

        }
            break;

        case 4:
        {

        }
            break;

        default:
            cout << "Invalid Option Please Make A choice Thats On The Menu:";
            cin >> choice;
        }

    } while (choice != 4);

}











//Ask The USer If They Want To Play Again
bool Repeat()
{
    char repeat;
    cout << "Would You Like To Play Again Y/N?:";
    cin >> repeat;
    return repeat == 'Y' || repeat == 'y';
}
