//
//  game.cpp
//  Snake
//
//  Created by admin on 15.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#include "game.hpp"
#include "food_life.hpp"
#include "food_basic.hpp"
#include "food_drunk.hpp"
#include "food_illusion.hpp"
#include "food_invert.hpp"

char Game::board[BOARD_SIZE][BOARD_SIZE];
Snake* Game::player;
Food* Game::food;
uint Game::current_level;

void key_callback()
{
    while (1)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            Game::player -> invert();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (Game::player -> is_drunk())
                Game::player -> set_direction('D');
            else
                Game::player -> set_direction('U');
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (Game::player -> is_drunk())
                Game::player -> set_direction('U');
            else
                Game::player -> set_direction('D');
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (Game::player -> is_drunk())
                Game::player -> set_direction('R');
            else
                Game::player -> set_direction('L');
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (Game::player -> is_drunk())
                Game::player -> set_direction('L');
            else
                Game::player -> set_direction('R');
        }
        usleep(1000);
    }
}

Game::Game()
{
    std::thread key_manager(key_callback);
    key_manager.detach();
}

void Game::game_start(uint level)
{
    current_level = level;
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
            board[i][j] = '0';
    }
    player = new Snake();
    food = spawn_food();
}

void Game::game_loop(sf::RenderWindow* window)
{
    player -> move();
    player -> draw(window);
    food -> draw(window);
    
    /*for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
            std::cout << board[i][j] << ' ';
        std::cout << '\n';
    }
    std::cout << "\n\n";*/
    usleep(ITERATION_TIME);
}

Food* Game::spawn_food()
{
    int x, y;
    do
    {
        x = rand() % BOARD_SIZE;
        y = rand() % BOARD_SIZE;
    } while (board[x][y] != '0');
    board[x][y] = 'F';
    if (rand() % 100 < 3)
    {
        return (new Food_Life(x, y));
    }
    switch(rand() % 5)
    {
        case 0: case 1:
            return (new Food_Basic(x, y));
        case 2:
            return (new Food_Invert(x, y));
        case 3:
            return (new Drunk_Food(x, y));
        default:
            return (new Illusion_Food(x, y));
    }
}
