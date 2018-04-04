//
//  snake.hpp
//  Snake
//
//  Created by admin on 15.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#ifndef snake_hpp
#define snake_hpp

class Snake;

#include <vector>
#include <iostream>
#include "point.hpp"
#include "colored.hpp"
#include "food.hpp"
#include <SFML/Graphics.hpp>

class Snake : public Colored
{
private:
    char direction;
    uint length, lives, score;
    std::vector<Point> body;
    bool drunk;
public:
    Snake();
    void draw(sf::RenderWindow* window);
    void move();
    void set_direction(char dir);
    void invert();
    bool is_drunk();
    void set_drunk(bool);
    void add_lives(uint _lives = 1);
    void eat(Food* food);
    void reset();
    void game_over();
    std::vector<Point> get_body();
};

#endif /* snake_hpp */
