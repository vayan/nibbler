//
// core.cpp for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 17:17:02 2012 yann vaillant
// Last update Mon Mar 12 18:15:29 2012 yann vaillant
//

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
      quit = this->draw->check_exit();
      this->draw->draw_map();
      this->draw->draw_snake(this->snake);
      //this->draw->draw_food();

      this->draw->refresh();
    }
}



