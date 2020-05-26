#include "Board.hpp"
#include "Soldier.hpp"
#include "FootSoldier.hpp"
namespace WarGame
{
    Soldier *&Board::operator[](std::pair<int, int> l)
    {
        if (board[l.first][l.second] == nullptr)
            return board[l.first][l.second];
        throw std::invalid_argument( "this location is occupied\n");
    }

    Soldier *Board::operator[](std::pair<int, int> l) const
    {
        return board[l.first][l.second];
    }

    void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction)
    {
        Soldier *current = board[source.first][source.second];
        std::pair<int, int> nextStep;
        if (current == nullptr)
            throw std::invalid_argument("there is no Soldier at this current position!");
        else if (current->getTeamId() != player_number)
            throw std::invalid_argument("the Soldier in this current position does not belong to you!");
        switch (direction)
        {
        case Up:
        {
            if (board[source.first + 1][source.second] != nullptr)
                throw std::invalid_argument("invalid step");
            nextStep = {source.first + 1, source.second};
            break;
        }
        case Down:
        {
            if (board[source.first - 1][source.second] != nullptr)
                throw std::invalid_argument("invalid step");
            nextStep = {source.first - 1, source.second};

            break;
        }
        case Left:
        {
            if (board[source.first][source.second - 1] != nullptr)
                throw std::invalid_argument("invalid step");
            nextStep = {source.first - 1, source.second};
            break;
        }
        case Right:
        {
            if (board[source.first][source.second + 1] != nullptr)
                throw std::invalid_argument("invalid step");
            nextStep = {source.first, source.second + 1};
            break;
        }
        }
        if (nextStep.first < 0 || nextStep.first >= board.size() ||
            nextStep.second < 0 || nextStep.second >= board[0].size())
            throw std::invalid_argument("invalid step");

        board[nextStep.first][nextStep.second] = current;
        current = nullptr;
        board[nextStep.first][nextStep.second]->attack(this->board, nextStep);
    }

    //vector<std::vector<Soldier*>> board;
    bool Board::has_soldiers(uint player_number) const
    {
        for (size_t i = 0; i < this->board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != nullptr && board[i][j]->getTeamId() == player_number)
                    return true;
            }
        }
        return false;
    }
} // namespace WarGame