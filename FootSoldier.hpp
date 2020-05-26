#include "Soldier.hpp"

class FootSoldier : public Soldier
{
    public:
    void hesoyam();
    ~FootSoldier(){};
    FootSoldier(int team_id):Soldier::Soldier(100, 10, 1, team_id){};
    void attack(vector<vector<Soldier*>> &board, pair<int,int> location);

};