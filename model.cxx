#include "model.hxx"

Model::Model():
        turn_('X'),
        scores_{0, 0},
        winner_(' ')
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board_[i][j] = ' ';
        }
    }
}

void Model::change_turn()
{
    if (turn_ == 'X') {
        turn_ = 'O';
    } else {
        turn_ = 'X';
    }
}

bool Model::check_winner()
{
    //check all horizontal/vertical diagonal ways of 3 in a row
    //check all rows
    for (int i = 0; i < 3; i++) {
        if (board_[i][0] != ' ' && (board_[i][0] == board_[i][1] && board_[i][0]
        ==
        board_[i][2])) {
            winner_ = board_[i][0];
            return true;
        }
    }

    //check all columns
    for (int j = 0; j < 3; j++) {
        if (board_[0][j] != ' ' && (board_[0][j] == board_[1][j] && board_[0][j]
        == board_[2][j])) {
            winner_ = board_[0][j];
            return true;
        }
    }

    //check diagonals
    if (board_[0][0] != ' ' && (board_[0][0] == board_[1][1] && board_[0][0] ==
    board_[2][2])) {
        winner_ = board_[0][0];
        return true;
    }
    if (board_[0][2] != ' ' && (board_[0][2] == board_[1][1] && board_[2][0] ==
    board_[0][2])) {
        winner_ = board_[0][2];
        return true;
    }

    //check if no empty spaces but also no winner
    return false;
}

void Model::play_move(int i, int j) {
    if (winner_ != ' ') {
        return;
    }
    if (board_[i][j] == ' ') {
        board_[i][j] = turn_;

        //update scores
        if (turn_ == 'X') {
            scores_[0]++;
        } else {
            scores_[1]++;
        }

        bool result = check_winner();

        change_turn();
    }
}