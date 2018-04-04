//
//  food_invert.hpp
//  Snake
//
//  Created by admin on 16.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#ifndef food_invert_hpp
#define food_invert_hpp

#include "food.hpp"

class Food_Invert : public Food
{
public:
    Food_Invert(int _x, int _y);
    void get_eaten(Snake* by);
};

#endif /* food_invert_hpp */
