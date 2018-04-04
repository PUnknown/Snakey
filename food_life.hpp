//
//  food_life.hpp
//  Snake
//
//  Created by admin on 16.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#ifndef food_life_hpp
#define food_life_hpp

#include "food.hpp"

class Food_Life : public Food
{
public:
    Food_Life(int _x, int _y);
    void get_eaten(Snake* by);
};

#endif /* food_life_hpp */
