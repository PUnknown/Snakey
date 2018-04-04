//
//  food_drunk.cpp
//  Snake
//
//  Created by admin on 16.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#include "food_drunk.hpp"

Drunk_Food::Drunk_Food(int _x, int _y) : Food(_x, _y)
{
    set_color_rgb(0, 255, 0);
}

void Drunk_Food::get_eaten(Snake *by)
{
    by -> set_drunk(true);
}
