#pragma once

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Soldier
{
private:
protected:
    int health, damage, id, team_id;
    Soldier(int teamId) : team_id(teamId){};
    Soldier(){};
    Soldier(int h, int d, int _id, int team) : health(h), damage(d), id(_id), team_id(team){};
    Soldier *findClosest(vector<vector<Soldier *>> &board, pair<int, int> location)
    {
        double min = 10000000;
        Soldier *This = board[location.first][location.second];
        Soldier *closest = nullptr;
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == nullptr)
                    continue; //skip on empty places
                if (board[i][j]->getTeamId() == This->getTeamId())
                    continue; // skip on soldiers from the same team
                double t = distance(location, {i, j});
                if (t < min)
                {
                    min = t;
                    closest = board[i][j];
                }
            }
        }
        return closest;
    }
    double distance(pair<int, int> l1, pair<int, int> l2)
    {
        return sqrt(pow(l1.first - l2.first, 2) + pow(l1.second - l2.second, 2));
    }

public:
    virtual void hesoyam() = 0;
    virtual ~Soldier(){};
    virtual void attack(std::vector<std::vector<Soldier *>> &s, std::pair<int, int> location) = 0;
    int getTeamId()
    {
        return team_id;
    }
    int getHealth()
    {
        return health;
    }
    int getId()
    {
        return id;
    }
    void setHealth(int h)
    {
        this->health = h;
    }
};