//
// core.cpp for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 17:17:02 2012 yann vaillant
// Last update Mon Mar 12 19:37:04 2012 yann vaillant
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

void Core::launch_game()
{
  bool	quit = false;
  
  this->draw->init_lib();
  while (quit == false)
    {
      quit = this->draw->handle_mvt(this->snake);
      this->draw->draw_map();
      this->draw->draw_snake(this->snake);
      //this->draw->draw_food();
      this->draw->refresh();
      usleep(100000);
      this->snake->move_up();
    }
}



