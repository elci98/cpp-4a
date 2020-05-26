#include "Soldier.hpp"
class Paramedic : public Soldier
{
    public:
    Paramedic(int team_id):Soldier(100, 0, 5, team_id){};
    void hesoyam();
    void attack(vector<vector<Soldier*>> &board, pair<int,int> location);

};