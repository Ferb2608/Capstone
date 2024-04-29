#include <ctime>
#include "gamer.h"

// Constructor Definition
Gamer::Gamer(string name, int score)
{
    this->_name = name;
    this->_score = score;
}

// Copy Constructor
Gamer::Gamer(const Gamer &source)
{
    this->_name = source._name;
    this->_score = source._score;
}
// copy assignment overloading operator
Gamer &Gamer::operator=(const Gamer &source)
{
    if (this == &source)
        return *this;
    this->_name = source._name;
    this->_score = source._score;
    return *this;
}
// move constructor
Gamer::Gamer(Gamer &&source)
{
    // move data
    this->_name = source._name;
    this->_score = source._score;
    // delete original data
    source._name = "";
    source._score = 0;
}
// Move assignment operator overloading
Gamer &Gamer::operator=(Gamer &&source)
{
    if (this == &source)
        return *this;
    // move data
    this->_name = source._name;
    this->_score = source._score;
    // delete original data
    source._name = "";
    source._score = 0;
    return *this;
}

// Definitions of setters and Getters
void Gamer::SetName(string name)
{
    this->_name = name;
}

void Gamer::SetScore(int score)
{
    this->_score = score;
}

string Gamer::GetName() const { return _name; }
int Gamer::GetScore() const { return _score; }

// Overloading the (<) operator
bool Gamer::operator<(const Gamer &data)
{
    return this->GetScore() > data.GetScore();
}