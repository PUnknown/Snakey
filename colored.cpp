//
//  colored.cpp
//  Snake
//
//  Created by admin on 15.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#include "colored.hpp"

Colored::Colored(uint red, uint green, uint blue)
{
    set_color_rgb(red, green, blue);
}

void Colored::set_color_rgb(uint red, uint green, uint blue)
{
    color[0] = red > 255 ? 255 : red;
    color[1] = green > 255 ? 255 : green;
    color[2] = blue > 255 ? 255 : blue;
}

uint Colored::red()
{
    return color[0];
}

uint Colored::green()
{
    return color[1];
}

uint Colored::blue()
{
    return color[2];
}
