#include "FootCommander.hpp"

void FootCommander::hesoyam()
{
    this->health = 150;
}
void FootCommander::attack(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    for (size_t i = 0; i < board.size(); i++)
        for (size_t j = 0; j < board[i].size(); j++) // arbitrary we chose id number 1 to represent FootSoldier
        {
            if (board[i][j] == nullptr)continue;
            if (board[i][j]->getTeamId() == this->getTeamId() && board[i][j]->getId() == 1)
                board[i][j]->attack(board, {i, j});
        }
    Soldier *enemy = findClosest(board, location);
    if (enemy != nullptr)
        enemy->setHealth(enemy->getHealth() - this->damage);
    else
        return;
    if (enemy->getHealth() <= 0)
    {
        cout << "player " << enemy->getTeamId() << " were sorry, you have lost a soldier\n";
        enemy = nullptr;
    }
}
