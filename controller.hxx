#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller();
    View::Dimensions initial_window_dimensions() const override;
    void on_mouse_down(ge211::events::Mouse_button m, View::Position p)
    override;

protected:
    void draw(ge211::Sprite_set& set) override;

private:
    Model model_;
    View view_;
};
