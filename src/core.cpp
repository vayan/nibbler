//
// core.cpp for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 17:17:02 2012 yann vaillant
// Last update Tue Mar 13 10:37:19 2012 yann vaillant
//

#include <unistd.h>
#include "core.hh"

Core::Core(Map* map, Draw* draw, Snake* snake)
{
  this->map = map;
  this->draw = draw;
  this->snake = snake;
}

Core::~Core()
{
  
}

bool	Core::move_dir()
{
  bool quit = false;
  int	ret = 0;
  
  ret = this->draw->handle_mvt(this->snake); 
  if (ret == -1)
    quit = true;
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
  quit = this->check_colli();
  return (quit);
}

bool	Core::check_colli()
{
  bool quit = false;
  
  if ((this->snake->get_x() <= 0) || 
      (this->snake->get_x() >= this->map->get_x()))
    quit = true;
  if ((this->snake->get_y() <= 0) ||
      (this->snake->get_y() >= this->map->get_y()))
    quit = true;
  if (this->snake->get_y() == 1 && this->snake->get_x() == 1)
    quit = false;
  return (quit);
}

void Core::launch_game()
{
  bool	quit = false;
  
  this->draw->init_lib();
  while (quit == false)
    {
      quit = this->move_dir();
      if (quit == true)
	exit (EXIT_FAILURE);
      this->draw->draw_map();
      this->draw->draw_snake(this->snake);
      //this->draw->draw_food();
      this->draw->refresh();
      usleep(300000);
    }
}



