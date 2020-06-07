#include "FootSoldier.hpp"

void FootSoldier::hesoyam()
{
    this->health = 100;
}
void FootSoldier::attack(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    Soldier **enemy = findClosest(board, location);
    if(enemy == nullptr || *enemy == nullptr)return;
    (*enemy)->setHealth((*enemy)->getHealth() - this->damage);
    if ((*enemy)->getHealth() <= 0)
    {
        cout << "player " << (*enemy)->getTeamId() << " were sorry, you have lost a soldier\n";
        *enemy = nullptr;
    }
}
