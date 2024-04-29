#include <string>

#ifndef GAMER_H
#define GAMER_H

using namespace std;

class Gamer
{
public:
    // Constructors and Destructors
    Gamer(){};
    Gamer(string name, int score);
    ~Gamer(){};
    // Copy Semantics
    Gamer(const Gamer &source);
    Gamer &operator=(const Gamer &source);
    // Move Semantics
    Gamer(Gamer &&source);
    Gamer &operator=(Gamer &&source);

    // Setters
    void SetName(std::string name);
    void SetScore(int score);

    // Getters
    string GetName() const;
    int GetScore() const;

    bool operator<(const Gamer &data);

private:
    string _name;
    int _score;
};
#endif