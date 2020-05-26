#include "Soldier.hpp"

class ParamedicCommander : public Soldier
{
    public:
    void hesoyam();
    ParamedicCommander(int team_id):Soldier(200, 0, 6, team_id){};
    void attack(vector<vector<Soldier*>> &s , pair<int,int> location);

};