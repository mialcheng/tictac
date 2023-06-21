#include "view.hxx"

const int grid_size = 50;

View::View(Model const& model)
        : model_(model)
{ }

void
View::draw(ge211::Sprite_set& set)
{
    // This needs to do something!

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char piece = model_.squares_at(i, j);

            ge211::Text_sprite::Builder letter_builder(sans30);
            letter_builder << piece;
            letter_sprites[i][j].reconfigure(letter_builder);

            set.add_sprite(letter_sprites[i][j], Position{i*grid_size,
                                                       j*grid_size});

        }
    }
}

View::Dimensions
View::initial_window_dimensions() const
{
    // You can change this if you want:
    return grid_size * Dimensions{3, 3};
}

View::Position
View::screen_to_board(View::Position pos) const
{
    return {pos.x / grid_size, pos.y / grid_size};
}