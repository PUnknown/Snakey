//
//  snake.cpp
//  Snake
//
//  Created by admin on 15.06.17.
//  Copyright © 2017 admin. All rights reserved.
//

#include "snake.hpp"
#include "game.hpp"

//TODO: отображение уровня и количества жизней как текста или через картинку

const uint START_LENGTH = 4;

void Snake::reset()
{
    body.clear();
    for (int j = 0; j < START_LENGTH; ++j)
    {
        Point temp(j, 0);
        body.push_back(temp);
    }
}

Snake::Snake() : Colored(255, 255, 255)
{
    reset();
    direction = 'R';
    length = START_LENGTH;
    lives = 3;
    drunk = false;
    score = 0;
}

void Snake::draw(sf::RenderWindow *window)
{
    uint quad = 0.93 * CELL_SIZE, offset = CELL_SIZE - quad;
    for (std::vector<Point>::iterator i = body.begin(); i != body.end(); ++i)
    {
        sf::RectangleShape shape(sf::Vector2f(quad, quad));
        sf::Color shape_color(red(), green(), blue());
        shape.setFillColor(shape_color);
        shape.setPosition(i -> x * CELL_SIZE + offset, i -> y * CELL_SIZE + offset);
        window -> draw(shape);
    }
}

void Snake::move()
{
    int x = body[length - 1].x, y = body[length - 1].y;
    switch(direction)
    {
        case 'U':
            --y;
            break;
        case 'D':
            ++y;
            break;
        case 'L':
            --x;
            break;
        case 'R':
            ++x;
            break;
    }
    x = (x + BOARD_SIZE) % BOARD_SIZE;
    y = (y + BOARD_SIZE) % BOARD_SIZE;
    /*for (std::vector<Point>::iterator i = body.begin(); i != body.end(); ++i)
        std::cout << i -> x << ' ' << i -> y << "; ";
    std::cout << '\n' << x << ' ' << y << std::endl;*/
    
    //FIXME: иногда некорректно запоминается матрица поля ('S' там, где его не должно быть)
    switch(Game::board[x][y])
    {
        case 'S':
            if (--lives <= 0)
                game_over();
            Game::game_start(0);
            break;
        case 'F':
        {
            Point new_cell(x, y);
            body.push_back(new_cell);
            Game::food -> get_eaten(this);
            Game::board[x][y] = 'S';
            Game::food = Game::spawn_food();
            ++score; ++length;
            break;
        }
        case '0':
            Game::board[body[0].x][body[0].y] = '0';
            body.erase(body.begin());
            Point new_cell(x, y);
            body.push_back(new_cell);
            Game::board[x][y] = 'S';
            break;
    }
}

void Snake::set_direction(char dir)
{
    if (dir == 'U' || dir == 'D' || dir == 'L' || dir == 'R')
        direction = dir;
}

void Snake::invert()
{
    std::reverse(body.begin(), body.end());
    
    //TODO: сделать более адекватный алгоритм смены направления (может в себя врезаться при достаточной длине)
    switch(direction)
    {
        case 'U':
            direction = 'D';
            break;
        case 'D':
            direction = 'U';
            break;
        case 'L':
            direction = 'R';
            break;
        case 'R':
            direction = 'L';
            break;
    }
}

bool Snake::is_drunk()
{
    return drunk;
}

void Snake::set_drunk(bool is_drunk)
{
    drunk = is_drunk;
    if (drunk)
        set_color_rgb(0, 255, 0);
    else
        set_color_rgb(255, 255, 255);
}

void Snake::add_lives(uint _lives)
{
    lives += _lives;
    if (lives > 100)
        lives = 100;
}

void Snake::game_over()
{
    score = 0;
    lives = 3;
    Game::game_start(0);
}

std::vector<Point> Snake::get_body()
{
    return body;
}
