#include "menu.h"
#include <iostream>
#include <string>

using namespace std;

void Menu::MainMenu()
{
    cout << "\033[2J\033[1;1H";
    cout << "/------------- Welcome to 2D Snake Game -------------/" << endl;
    cout << "/--------------------- Main Menu --------------------/" << endl;
    cout << "1. Play Game" << endl;
    cout << "2. Show Game History" << endl;
}

string Menu::InputGamerName()
{
    std::string name;
    cout << "\033[2J\033[1;1H";
    cout << "/------------------ Game Settings -------------------/" << endl;
    cout << "Please enter your name: ";
    while (!(cin >> name))
    {
        cin.clear();
        cout << "You must input string value";
    }
    return name;
}

int Menu::InputNumber()
{
    int userInput;
    while (!(cin >> userInput) || userInput < 1 || userInput > 2)
    {
        cin.clear();
        cout << "You must input integer and value is between 1 and 2!";
    }
    return userInput;
}
