//
//  food_basic.hpp
//  Snake
//
//  Created by admin on 16.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#ifndef food_basic_hpp
#define food_basic_hpp

#include "food.hpp"

class Food_Basic : public Food
{
public:
    Food_Basic(int _x, int _y);
    void get_eaten(Snake* by);
};

#endif /* food_basic_hpp */
