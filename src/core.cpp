//
// core.cpp for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 17:17:02 2012 yann vaillant
// Last update Tue Mar 13 09:45:22 2012 yann vaillant
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

void	Core::move_dir()
{
  switch (this->snake->get_dir())
    {
    case Up :
      this->snake->move_up();
    case Down :
      this->snake->move_down();
    case Left :
      this->snake->move_left();
    case Right :
      this->snake->move_right();
    default :
      break;
    } 
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
      Core::move_dir();
      usleep(100000);
    }
}



