//
//  game.hpp
//  Snake
//
//  Created by admin on 15.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include "snake.hpp"
#include "food.hpp"
#include "unistd.h"
#include <thread>

typedef unsigned int uint;

const uint BOARD_SIZE = 20;
const uint CELL_SIZE = 32;
const uint ITERATION_TIME = 500000;

class Game
{
private:
    static uint current_level;
    //sf::Thread key_manager(&key_callback);
public:
    static char board[BOARD_SIZE][BOARD_SIZE];
    static Snake* player;
    static Food* food;
    Game();
    void game_loop(sf::RenderWindow* window);
    static void game_start(uint level = 0);
    static Food* spawn_food();
};

#endif /* game_hpp */
