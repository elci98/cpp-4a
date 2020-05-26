#include "Soldier.hpp"

class SniperCommander : public Soldier
{
    public:
    void hesoyam();
    SniperCommander(int team_id):Soldier(120, 100, 4, team_id){};
    void attack(vector<vector<Soldier*>> &s , pair<int,int> location);

};