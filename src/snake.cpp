//
// snake.cpp for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 17:47:32 2012 yann vaillant
// Last update Mon Mar 12 18:17:51 2012 yann vaillant
//

#include "snake.hh"

Snake::Snake()
{
  pos_x = 7;
  pos_y = 15;
  lenght = 3;
  speed = 1;
}

int   Snake::get_x()
{
  return (pos_x);
}

int   Snake::get_y()
{
  return (pos_y);
}

int   Snake::get_lenght()
{
  return (lenght);
}

int   Snake::get_speed()
{
  return (speed);
}

void  Snake::move_up()
{
  this->pos_y += 1;
}

void  Snake::move_down()
{
  this->pos_y -= 1;
}

void  Snake::move_left()
{
  this->pos_x += 1;
}

void  Snake::move_right()
{
  this->pos_x -= 1;
}


