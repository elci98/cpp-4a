#include "FootCommander.hpp"

void FootCommander::hesoyam()
{
    this->health = 150;
}
void FootCommander::attack(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    vector<Soldier *> v;
    for (size_t i = 0; i < board.size(); i++)
        for (size_t j = 0; j < board[i].size(); j++) // arbitrary we chose id number 1 to represent FootSoldier
        {
            if (board[i][j] == nullptr)
                continue;
            if (board[i][j]->getTeamId() == this->getTeamId() && board[i][j]->getId() == 1)
                v.push_back(board[i][j]);
        }
    for (size_t i = 0; i < v.size(); i++)
    {
        (v.at(i))->attack(board, location);
    }

    Soldier **enemy = findClosest(board, location);
    if(enemy == nullptr || *enemy == nullptr)return;
    (*enemy)->setHealth((*enemy)->getHealth() - this->damage);
    if ((*enemy)->getHealth() <= 0)
    {
        cout << "player " << (*enemy)->getTeamId() << " were sorry, you have lost a soldier\n";
        *enemy = nullptr;
    }
}
