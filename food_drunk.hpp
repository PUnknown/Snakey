//
//  food_drunk.hpp
//  Snake
//
//  Created by admin on 16.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#ifndef food_drunk_hpp
#define food_drunk_hpp

#include "food.hpp"

class Drunk_Food : public Food
{
public:
    Drunk_Food(int _x, int _y);
    void get_eaten(Snake* by);
};

#endif /* food_drunk_hpp */
