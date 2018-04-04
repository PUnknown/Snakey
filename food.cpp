//
//  food.cpp
//  Snake
//
//  Created by admin on 16.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#include "food.hpp"
#include "game.hpp"

Food::Food(int _x, int _y) : Colored(255, 255, 255)
{
    position.x = _x;
    position.y = _y;
}

void Food::draw(sf::RenderWindow *window)
{
    uint radius = 0.465 * CELL_SIZE, offset = (CELL_SIZE - 2 * radius) / 2;//CELL_SIZE - radius;
    sf::CircleShape shape(radius);
    sf::Color shape_color(red(), green(), blue());
    shape.setFillColor(shape_color);
    shape.setPosition(position.x * CELL_SIZE + offset, position.y * CELL_SIZE + offset);
    window -> draw(shape);
}
