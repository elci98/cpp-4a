#include "doctest.h"
#include "Board.hpp"
#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "SniperCommander.hpp"
#include "Sniper.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace std;
using namespace WarGame;

Board board(20, 20);
vector<Soldier *> soldiers;
Soldier *temp;


TEST_CASE("Create Soldiers")
{
    CHECK_NOTHROW(temp = (board[{0, 4}] = new FootCommander(1)));
    soldiers.push_back(temp);
    CHECK_NOTHROW(temp = (board[{0, 12}] = new ParamedicCommander(1)));
    soldiers.push_back(temp);
    CHECK_NOTHROW(temp = (board[{0, 1}] = new SniperCommander(1)));
    soldiers.push_back(temp);
    for (int i = 0; i < 20; ++i)
    {
        switch (i % 3)
        {
        case 0:
            CHECK_NOTHROW(temp = (board[{1, i}] = new FootSoldier(1)));
            break;
        case 1:
            CHECK_NOTHROW(temp = (board[{2, i}] = new Paramedic(1)));
            break;
        case 2:
            CHECK_NOTHROW(temp = (board[{3, i}] = new Sniper(1)));
            break;
        }
        soldiers.push_back(temp);
    }

    CHECK_NOTHROW(temp = (board[{18, 0}] = new FootCommander(2)));
    soldiers.push_back(temp);
    CHECK_NOTHROW(temp = (board[{15, 12}] = new ParamedicCommander(2)));
    soldiers.push_back(temp);
    CHECK_NOTHROW(temp = (board[{11, 19}] = new SniperCommander(2)));
    soldiers.push_back(temp);
    for (int i = 0; i < 20; i++)
    {
        switch (i % 3)
        {
        case 0:
            CHECK_NOTHROW(temp = (board[{10, i}] = new FootSoldier(2)));
            break;
        case 1:
            CHECK_NOTHROW(temp = (board[{10, i}] = new Sniper(2)));
            break;
        case 2:
            CHECK_NOTHROW(temp = (board[{12, i}] = new FootSoldier(2)));
            break;
        }
        soldiers.push_back(temp);
    }
}

TEST_CASE("illgale moves")
{
    CHECK_THROWS(board.move(1, {18, 10}, Board::MoveDIR::Down));
    CHECK_THROWS(board.move(1, {0, 10}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2, {19, 10}, Board::MoveDIR::Down));
    CHECK_THROWS(board.move(1, {5, 10}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2, {15, 10}, Board::MoveDIR::Down));
    CHECK_THROWS(board.move(1, {0, 10}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2, {19, 10}, Board::MoveDIR::Down));
    CHECK_THROWS(board.move(2, {19, 19}, Board::MoveDIR::Right));
    CHECK_THROWS(board.move(2, {19, 0}, Board::MoveDIR::Left));
}

TEST_CASE("has soldiers test")
{
    temp = board[{2, 14}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));
    soldiers.push_back(temp);
    // CHECK_THROWS((board[{2, 14}] = new FootSoldier(2))); // trying to place soldier in occupied position

    temp = board[{5, 5}] = new FootSoldier(2);
    soldiers.push_back(temp);
    CHECK(board.has_soldiers(2));
}

TEST_CASE("Create Soldiers")
{
    CHECK_NOTHROW(temp = (board[{5, 1}] = new SniperCommander(1)));
    soldiers.push_back(temp);
    CHECK_NOTHROW(temp = (board[{5, 4}] = new FootCommander(1)));
    soldiers.push_back(temp);
    CHECK_NOTHROW(temp = (board[{5, 12}] = new ParamedicCommander(1)));
    soldiers.push_back(temp);
    for (int i = 0; i < 20; i++)
    {
        switch (i % 3)
        {
        case 0:
            CHECK_NOTHROW(temp = (board[{6, i}] = new FootSoldier(1)));
            break;
        case 1:
            CHECK_NOTHROW(temp = (board[{7, i}] = new Paramedic(1)));
            break;
        case 2:
            CHECK_NOTHROW(temp = (board[{8, i}] = new Sniper(1)));
            break;
        }
        soldiers.push_back(temp);
    }

    CHECK_NOTHROW(temp = (board[{19, 0}] = new FootCommander(2)));
    soldiers.push_back(temp);
    CHECK_NOTHROW(temp = (board[{15, 11}] = new ParamedicCommander(2)));
    soldiers.push_back(temp);
    CHECK_NOTHROW(temp = (board[{16, 12}] = new SniperCommander(2)));
    soldiers.push_back(temp);
    for (int i = 0; i < 20; i++)
    {
        switch (i % 3)
        {
        case 0:
            CHECK_NOTHROW(temp = (board[{14, i}] = new FootSoldier(2)));
            break;
        case 1:
            CHECK_NOTHROW(temp = (board[{17, i}] = new Sniper(2)));
            break;
        case 2:
            CHECK_NOTHROW(temp = (board[{9, i}] = new FootSoldier(2)));
            break;
        }
        soldiers.push_back(temp);
    }
}

TEST_CASE("DELETE ALLOC")
{
    for (Soldier *s : soldiers)
    {
        delete s;
    }
}