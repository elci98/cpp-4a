#include "SniperCommander.hpp"

void SniperCommander::hesoyam()
{
    this->health = 120;
}
void SniperCommander::attack(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    Soldier *enemy = nullptr;
    int max = 0;
    for (size_t i = 0; i < board.size(); i++)
        for (size_t j = 0; j < board[i].size(); j++)
        {
            Soldier* current = board[i][j];
            if(current == nullptr)continue;
            // arbitrary we chose id number 3 to represent Sniper
            if (current->getTeamId() == this->getTeamId() && current->getId() == 3)
                current->attack(board, {i, j});
            if (current->getTeamId() != this->getTeamId())
            {
                int h = current->getHealth();
                if (h > max)
                {
                    enemy = current;
                    max = h;
                }
            }
        }

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
