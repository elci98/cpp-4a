#include "Sniper.hpp"

void Sniper::hesoyam()
{
    this->health = 100;
}
void Sniper::attack(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    Soldier *enemy = nullptr;
    int max = 0;
    for (size_t i = 0; i < board.size(); i++)
        for (size_t j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == nullptr)continue;
            if (board[i][j]->getTeamId() != this->getTeamId())
            {
                int h = board[i][j]->getHealth();
                if (h > max)
                {
                    enemy = board[i][j];
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
