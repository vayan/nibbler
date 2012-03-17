//
// core.hh for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 17:17:12 2012 yann vaillant
// Last update Sat Mar 17 18:47:10 2012 ludovic tanter
//

#ifndef CORE_H
#define CORE_H

#include <list>

#include "map.hh"
#include "snake.hh"
#include "food.hh"
#include "ILib.hh"

class	Core 
{
public:
  Core(Map*, ILib*, Snake*);
  ~Core();
  int   launch_game() const;
  int	move_dir() const;
  int	check_colli() const;
  bool	food_is_good() const;
  int   check_colli_food() const;
private:
  Map   *map;
  Food  *food;
  ILib  *draw;
  Snake *snake;
};

#endif
