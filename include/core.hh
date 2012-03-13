//
// core.hh for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 17:17:12 2012 yann vaillant
// Last update Tue Mar 13 09:58:59 2012 yann vaillant
//

#ifndef CORE_H
#define CORE_H

#include "map.hh"
#include "draw.hh"
#include "snake.hh"

class Core 
{
public:
  Core(Map*, Draw*, Snake*);
  ~Core();
  void          launch_game();
  bool		move_dir();
  bool		check_colli();
private:
  Map *map;
  Draw *draw;
  Snake *snake;
};

#endif
