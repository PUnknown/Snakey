//
//  point.cpp
//  Snake
//
//  Created by admin on 15.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#include "point.hpp"

Point::Point(int _x, int _y)
{
    x = _x; y = _y;
}

bool Point::operator==(Point& other)
{
    return x == other.x && y == other.y;
}
