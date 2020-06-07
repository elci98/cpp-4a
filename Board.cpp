#include "Board.hpp"
#include "Soldier.hpp"
#include "FootSoldier.hpp"
namespace WarGame
{
    Soldier *&Board::operator[](std::pair<int, int> l)
    {
        // if (board[l.first][l.second] == nullptr)
        return board[l.first][l.second];
        // throw std::invalid_argument("this location is occupied\n");
    }

    Soldier *Board::operator[](std::pair<int, int> l) const
    {
        return board[l.first][l.second];
    }

    void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction)
    {
        std::pair<int, int> nextStep;
        if(source.first >= board.size() || source.first < 0 ||source.second >= board[0].size() || source.second < 0 )
            throw std::invalid_argument("invalid step");
        if (board[source.first][source.second] == nullptr)
            throw std::invalid_argument("there is no Soldier at this current position!");
        else if (board[source.first][source.second]->getTeamId() != player_number)
            throw std::invalid_argument("the Soldier in this current position does not belong to you!");
        switch (direction)
        {
        case Up:
        {
            if (source.first + 1 == board.size() || board[source.first + 1][source.second] != nullptr)
                throw std::invalid_argument("invalid step");
            nextStep = {source.first + 1, source.second};
            break;
        }
        case Down:
        {
            if (source.first - 1 < 0 || board[source.first - 1][source.second] != nullptr)
                throw std::invalid_argument("invalid step");
            nextStep = {source.first - 1, source.second};

            break;
        }
        case Left:
        {
            if (source.second - 1 < 0 || board[source.first][source.second - 1] != nullptr)
                throw std::invalid_argument("invalid step");
            nextStep = {source.first, source.second - 1};
            break;
        }
        case Right:
        {
            if (source.second + 1 == board[0].size() || board[source.first][source.second + 1] != nullptr)
                throw std::invalid_argument("invalid step");
            nextStep = {source.first, source.second + 1};
            break;
        }
        }

        board[nextStep.first][nextStep.second] = board[source.first][source.second];
        board[source.first][source.second] = nullptr;
        board[nextStep.first][nextStep.second]->attack(this->board, nextStep);
    }

    bool Board::has_soldiers(uint player_number) const
    {
        for (size_t i = 0; i < this->board.size(); i++)
        {
            for (size_t j = 0; j < this->board[i].size(); j++)
            {
                if (board[i][j] != nullptr && board[i][j]->getTeamId() == player_number)
                    return true;
            }
        }
        return false;
    }
} // namespace WarGame