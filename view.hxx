#pragma once

#include "model.hxx"

class View
{
public:
    using Dimensions = ge211::Dims<int>;

    /// View positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

    Dimensions initial_window_dimensions() const;

    Position
    screen_to_board(Position screen_pos) const;

private:
    Model const& model_;

    ge211::Font sans30{"sans.ttf", 30};
    ge211::Text_sprite letter_sprites[3][3];
};
