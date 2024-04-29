#include "history.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

History::History(){};

// Methods Definition
void History::SaveHistory(Gamer &gamer)
{
    // Create Output file stream
    ofstream Game_History("History.txt");

    if (Game_History.is_open())
    {
        Game_History << gamer.GetName() << " " << gamer.GetScore() << "\n"
                     << endl;
        Game_History.close();
    }
    else
    {
        cout << "ERROR: Requested file cannot be opened\n";
    }
}

vector<shared_ptr<Gamer>> History::ReadHistory()
{
    string line, name;
    int score, game_time;
    ifstream Game_History("History.txt");

    if (Game_History.is_open())
    {
        while (getline(Game_History, line))
        {
            istringstream linestream(line);
            if (linestream >> name >> score)
            {
                auto history = std::make_shared<Gamer>(name, score);
                _history.emplace_back(move(history));
            }
        }
        Game_History.close();
        return _history;
    }
}

vector<shared_ptr<Gamer>> History::SortHistory(vector<shared_ptr<Gamer>> &histories)
{
    sort(histories.begin(), histories.end(), [](const shared_ptr<Gamer> &gamer_1, shared_ptr<Gamer> &gamer_2)
         { return gamer_1->GetScore() > gamer_2->GetScore(); });
    return histories;
}

void History::DisplayHistory()
{
    if (_history.size() > 0)
    {
        cout << "/------------------ Game History -------------------/" << endl;
        int count = 1;
        for (auto i : _history)
        {
            cout << count << ". " << i->GetName() << ", Score: " << i->GetScore() << endl;
            count++;
        }
    }
    else
    {
        cout << "ERROR: No data to display\n";
    }
}
