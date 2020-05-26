#include "Soldier.hpp"

class FootCommander : public Soldier
{
    public:
    
    FootCommander(int team_id):Soldier(150, 20, 2, team_id){};
    void attack(vector<vector<Soldier*>> &board , pair<int,int> location);
    void hesoyam();

};