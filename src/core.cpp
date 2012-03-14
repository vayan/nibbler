//
// core.cpp for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 17:17:02 2012 yann vaillant
// Last update Tue Mar 13 17:03:44 2012 yann vaillant
//

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "core.hh"
#include "food.hh"

Core::Core(Map* map, ILib* draw, Snake* snake)
{
  Food *food = new Food(10, 10);

  this->map = map;
  this->draw = draw;
  this->snake = snake;
  this->food = food;
}

Core::~Core()
{
  
}

int	Core::move_dir()
{
  int quit = 0;
  int ret = 0;
  
  ret = this->draw->handle_mvt(this->snake); 
  if (ret == -1)
    quit = -1;
  if (ret == 1)
    quit = 1;
  if (ret == 0)
    { 
      if ((this->snake->get_dir()) == Up)
	this->snake->move_up();
      else if ((this->snake->get_dir()) == Down)
	this->snake->move_down();
      else if ((this->snake->get_dir()) == Left)
	this->snake->move_left();
      else if ((this->snake->get_dir()) == Right)
	this->snake->move_right();
    }
  if ((this->check_colli()) == -1)
    return (-1);
  this->check_colli_food();
  return (quit);
}

bool	Core::food_is_good()
{
  std::list<int*> pos = this->snake->get_pos();
  std::list<int*>::iterator it = pos.begin();
  
  if ((this->food->get_x() <= 0) || 
      (this->food->get_x() >= this->map->get_x()))
    return (false);
  if ((this->food->get_y() <= 0) ||
      (this->food->get_y() >= this->map->get_y() - 1))
    return (false);
  if (this->food->get_x() <= 1)
    return (false);
  for (it++; it != pos.end(); ++it)
    if ((this->food->get_x() == (*it)[0]) && (this->food->get_y() == (*it)[1]))
      return (false);
  return (true);
}

int	Core::check_colli()
{
  std::list<int*> pos = this->snake->get_pos();
  std::list<int*>::iterator it = pos.begin();
  
  if ((this->snake->get_x() <= 0) || 
      (this->snake->get_x() >= this->map->get_x()))
    return (-1);
  if ((this->snake->get_y() <= 0) ||
      (this->snake->get_y() >= this->map->get_y() - 1))
    return (-1);
  if (this->snake->get_x() <= 1)
    return (-1);
  for (it++; it != pos.end(); ++it)
    if ((this->snake->get_x() == (*it)[0]) && (this->snake->get_y() == (*it)[1]))
      return (-1);
  return (0);
}

int Core::check_colli_food()
{ 
  if ((this->snake->get_x() == this->food->get_x()) && (this->snake->get_y() == this->food->get_y()))
  {
    this->snake->set_lenght((this->snake->get_lenght()) + 1);
    this->snake->add_lenght(this->food->get_x(), this->food->get_y());
    this->food->set_x(rand() % this->map->get_x());
    this->food->set_y(rand() % this->map->get_y());
    while (food_is_good() == false)
    {
      this->food->set_x(rand() % this->map->get_x());
      this->food->set_y(rand() % this->map->get_y());
    }
    return (-1);    
  }
  return (0); 
}

void Core::launch_game()
{
  int	quit = 0;
  
  this->draw->init_lib();
  while (quit >= 0)
    {
      quit = this->move_dir();
      if (quit == -1)
	     exit (EXIT_FAILURE);
      this->draw->draw_map(this->map);
      this->draw->draw_snake(this->snake);
      this->draw->draw_food(this->food);
      this->draw->refresh();
      usleep(200000);
    }
}



