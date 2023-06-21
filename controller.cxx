#include "controller.hxx"

Controller::Controller()
        : view_(model_)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

void Controller::on_mouse_down(ge211::events::Mouse_button m, View::Position
p)
{
    View::Position board_pos = view_.screen_to_board(p);
    model_.play_move(board_pos.x, board_pos.y);
}
