//
// snake.cpp for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 17:47:32 2012 yann vaillant
// Last update Fri Mar 16 14:50:22 2012 ludovic tanter
//

#include "snake.hh"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>
#include <stdio.h>

Snake::Snake(Map *map)
{
  int	*xy;
  int	i = 0;
  int	j = 0;
 
  speed = 4;
  dir = Down;
  lenght = 4;
  score  = 0;

  pos_x = map->get_x() / 2;
  pos_y = map->get_y() / 2;

  j = pos_y + 1;

  xy = (int*)malloc (3 * sizeof (int));
  xy[0] = pos_x;
  xy[1] = pos_y;
    
  while (i < lenght)
    {
      pos.push_front(xy);
      xy[0] = pos_x;
      xy[1] = pos_y;
      j++;
      i++;
      xy = (int*)malloc (3 * sizeof (int));
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

void  Snake::set_speed(int val)
{
  int max = 70;

  if (val >= max)
    this->speed = max;
  else
    this->speed = val;
}

int   Snake::get_score()
{
  return (this->score);
}

void  Snake::set_score(int val)
{
  this->score = val;
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
