//
// snake.cpp for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 17:47:32 2012 yann vaillant
// Last update Tue Mar 13 09:57:34 2012 yann vaillant
//

#include "snake.hh"

Snake::Snake()
{
  pos_x = 5;
  pos_y = 5;
  lenght = 3;
  speed = 1;
  dir = Down;
}

Direction Snake::get_dir()
{
  return (this->dir);
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
  this->dir = Up;
  this->pos_y += 1;
}

void  Snake::move_down()
{
  this->dir = Down;
  this->pos_y -= 1;
}

void  Snake::move_left()
{
  this->dir = Left;
  this->pos_x += 1;
}

void  Snake::move_right()
{
  this->dir = Right;
  this->pos_x -= 1;
}


