#ifndef HISTORY_H
#define HISTORY_H

#include <fstream>
#include <iostream>
#include <vector>
#include <memory>

#include "gamer.h"

using namespace std;

class History
{
public:
    // Default Constructor
    History();
    // Methods
    void SaveHistory(Gamer &gamer);
    vector<shared_ptr<Gamer>> ReadHistory();
    vector<shared_ptr<Gamer>> SortHistory(vector<shared_ptr<Gamer>> &histories);
    void DisplayHistory();

private:
    vector<shared_ptr<Gamer>> _history;
};
#endif