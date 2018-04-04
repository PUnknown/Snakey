//
//  food_illusion.cpp
//  Snake
//
//  Created by admin on 16.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#include "food_illusion.hpp"

Illusion_Food::Illusion_Food(int _x, int _y) : Food(_x, _y)
{
    set_color_rgb(0, 0, 255);
}

void Illusion_Food::get_eaten(Snake *by)
{
    switch(rand() % 2)
    {
        case 0:
            by -> invert();
            by -> set_drunk(false);
            break;
        case 1:
            by -> set_drunk(true);
            break;
    }
}
