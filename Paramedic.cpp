#include "Paramedic.hpp"

void Paramedic::hesoyam()
{
    this->health = 100;
}
void Paramedic::attack(vector<vector<Soldier*>> &board , pair<int,int> location)
{
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
