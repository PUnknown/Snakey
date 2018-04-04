//
//  point.hpp
//  Snake
//
//  Created by admin on 15.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#ifndef point_hpp
#define point_hpp

class Point
{
public:
    int x, y;
    Point(int _x = 0, int _y = 0);
    bool operator== (Point& other);
};

#endif /* point_hpp */
