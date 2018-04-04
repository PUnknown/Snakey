//
//  colored.hpp
//  Snake
//
//  Created by admin on 15.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#ifndef colored_hpp
#define colored_hpp

typedef unsigned int uint;

class Colored
{
private:
    int color[3];
public:
    Colored(uint red, uint green, uint blue);
    void set_color_rgb(uint red, uint green, uint blue);
    uint red();
    uint green();
    uint blue();
};

#endif /* colored_hpp */
