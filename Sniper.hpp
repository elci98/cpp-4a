#include "Soldier.hpp"

class Sniper : public Soldier
{
    public:
    void hesoyam();
    Sniper(int team_id):Soldier(100, 50, 3, team_id){};
    void attack(vector<vector<Soldier*>> &board , pair<int,int> location);

};