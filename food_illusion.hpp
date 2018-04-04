//
//  food_illusion.hpp
//  Snake
//
//  Created by admin on 16.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#ifndef food_illusion_hpp
#define food_illusion_hpp

#include "food.hpp"

class Illusion_Food : public Food
{
public:
    Illusion_Food(int _x, int _y);
    void get_eaten(Snake* by);
};

#endif /* food_illusion_hpp */
