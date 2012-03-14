//
// core.hh for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 17:17:12 2012 yann vaillant
// Last update Tue Mar 13 15:02:05 2012 yann vaillant
//

#ifndef CORE_H
#define CORE_H

#include <list>
#include "map.hh"
#include "snake.hh"
#include "food.hh"
#include "ILib.hh"

class Core 
{
public:
        Core(Map*, ILib*, Snake*);
        ~Core();
  void  launch_game();
  int		move_dir();
  int		check_colli();
  bool	food_is_good();
  int   check_colli_food();
private:
  Map   *map;
  Food  *food;
  ILib  *draw;
  Snake *snake;
};

#endif
