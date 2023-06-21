#pragma once

#include <ge211.hxx>

class Model
{
public:
    Model();

    char squares_at(int i, int j) const {
        return board_[i][j];
    }

    void play_move(int x, int y);

    void change_turn();

    bool check_winner();

private:
    char board_[3][3];

    char turn_;

    int scores_[2]; //0th index is 'X', 1st index is 'O'

    char winner_;
};
