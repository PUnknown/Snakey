//
//  food_invert.cpp
//  Snake
//
//  Created by admin on 16.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#include "food_invert.hpp"

Food_Invert::Food_Invert(int _x, int _y) : Food(_x, _y)
{
    set_color_rgb(255, 255, 0);
}

void Food_Invert::get_eaten(Snake *by)
{
    by -> invert();
    by -> set_drunk(false);
}
