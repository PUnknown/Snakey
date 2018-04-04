//
//  food_life.cpp
//  Snake
//
//  Created by admin on 16.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#include "food_life.hpp"

Food_Life::Food_Life(int _x, int _y) : Food(_x, _y)
{
    set_color_rgb(255, 0, 0);
}

void Food_Life::get_eaten(Snake *by)
{
    by -> set_drunk(false);
    by -> add_lives();
}
