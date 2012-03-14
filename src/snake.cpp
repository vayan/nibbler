//
// snake.cpp for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 17:47:32 2012 yann vaillant
// Last update Tue Mar 13 14:28:18 2012 yann vaillant
//

#include "snake.hh"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>

Snake::Snake()
{
  int	*xy;
  int	i = 0;
  int	j = 0;
 
  speed = 2;
  dir = Down;
  lenght = 3;

  pos_x = 5;
  pos_y = 5;

  j = pos_y + 1;

  xy = (int*)malloc (3 * sizeof (int));
  xy[0] = pos_x;
  xy[1] = pos_y;
    
  while (i < lenght)
    {
      pos.push_front(xy);
      xy[0] = pos_x;
      xy[1] = j;
      j++;
      i++;
    }
}

std::list<int*> Snake::get_pos()
{
  return(this->pos);
}

void    Snake::add_lenght(int x, int y)
{
  int *xy = (int*)malloc (3 * sizeof (int));

  xy[0] = x;
  xy[1] = y;
  this->pos.push_front(xy);
}


Direction Snake::get_dir()
{
  return (this->dir);
}

void    Snake::set_dir(Direction dir)
{
  if ((this->dir * -1) != dir)
    this->dir = dir;
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

void  Snake::set_lenght(int val)
{
  this->lenght = val;
}

int   Snake::get_speed()
{
  return (speed);
}

void  Snake::move_up()
{
  int *xy = (int*)malloc (3 * sizeof (int));
  std::list<int*>::iterator it;

  xy[0] = this->pos_x;
  xy[1] = this->pos_y + 1;
  this->pos.push_front(xy);

  it = pos.end();
  it--;
  this->pos.erase(it);

  this->dir = Up;
  this->pos_y += 1;
}

void  Snake::move_down()
{
  int *xy = (int*)malloc (3 * sizeof (int));
  std::list<int*>::iterator it;
  
  xy[0] = this->pos_x;
  xy[1] = this->pos_y - 1;
  this->pos.push_front(xy);
  
  it = pos.end();
  it--;
  this->pos.erase(it);
  
  this->dir = Down;
  this->pos_y -= 1;
}

void  Snake::move_left()
{
  int *xy = (int*)malloc (3 * sizeof (int));
  std::list<int*>::iterator it;

  xy[0] = this->pos_x + 1;
  xy[1] = this->pos_y;
  this->pos.push_front(xy);

  it = pos.end();
  it--;
  this->pos.erase(it);

  this->dir = Left;
  this->pos_x += 1;
}

void  Snake::move_right()
{
  int *xy = (int*)malloc (3 * sizeof (int));
  std::list<int*>::iterator it;

  xy[0] = this->pos_x - 1;
  xy[1] = this->pos_y;
  this->pos.push_front(xy);

  it = pos.end();
  it--;
  this->pos.erase(it);

  this->dir = Right;
  this->pos_x -= 1;
}
