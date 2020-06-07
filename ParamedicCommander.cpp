#include "ParamedicCommander.hpp"

void ParamedicCommander::hesoyam()
{
    this->health = 200;
}
void ParamedicCommander::attack(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    vector<Soldier *> v;
    for (size_t i = 0; i < board.size(); i++)
        for (size_t j = 0; j < board[i].size(); j++) // arbitrary we chose id number 5 to represent Paramedic
        {
            if (board[i][j] == nullptr)
                continue;
            if (board[i][j]->getTeamId() == this->getTeamId() && board[i][j]->getId() == 5)
                v.push_back(board[i][j]);
        }
    for (size_t i = 0; i < v.size(); i++)
    {
        (v.at(i))->attack(board, location);
    }
    if (board[location.first][location.second] == nullptr)return;
    Soldier *up = location.first + 1 < board.size() ? board[location.first + 1][location.second] : nullptr;
    Soldier *down = location.first - 1 >= 0 ? board[location.first - 1][location.second] : nullptr;
    Soldier *left = location.second - 1 >= 0 ? board[location.first][location.second - 1] : nullptr;
    Soldier *right = location.second + 1 < board[0].size() ? board[location.first ][location.second + 1] : nullptr;
    if (up != nullptr && up->getTeamId() == this->getTeamId())
        up->hesoyam();
    if (down != nullptr && down->getTeamId() == this->getTeamId())
        down->hesoyam();
    if (left != nullptr && left->getTeamId() == this->getTeamId())
        left->hesoyam();
    if (right != nullptr && right->getTeamId() == this->getTeamId())
        right->hesoyam();
}
