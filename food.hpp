//
//  food.hpp
//  Snake
//
//  Created by admin on 16.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#ifndef food_hpp
#define food_hpp

#include <SFML/Graphics.hpp>

class Food;

#include "colored.hpp"
#include "snake.hpp"
#include "point.hpp"

class Food : public Colored
{
public:
    Point position;
    Food(int _x, int _y);
    virtual void get_eaten(Snake* by) = 0;
    void draw(sf::RenderWindow* window);
};

#endif /* food_hpp */
