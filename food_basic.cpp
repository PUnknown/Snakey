//
//  food_basic.cpp
//  Snake
//
//  Created by admin on 16.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#include "food_basic.hpp"

Food_Basic::Food_Basic(int _x, int _y) : Food(_x, _y)
{
    set_color_rgb(0, 255, 255);
}

void Food_Basic::get_eaten(Snake* by)
{
    by -> set_drunk(false);
}
