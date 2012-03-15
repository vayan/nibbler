//
// ILib.hh for  in /home/vailla_y/Projet/nibler
//
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
//
// Started on  Mon Mar 12 12:33:30 2012 yann vaillant
// Last update Tue Mar 13 14:08:05 2012 yann vaillant
//

#ifndef _LIB_H
#define _LIB_H

#include "snake.hh"
#include "food.hh"
#include "map.hh"

typedef struct rgb {
  int r;
  int g;
  int b;
} rgb;

class ILib
{
public:	
  virtual void		init_lib(Map*) const = 0;
  virtual void		draw_map(Map*) const = 0;
  virtual void		draw_snake(Snake*) const = 0;
  virtual void    draw_food(Food*) const = 0;
  virtual void		add_cube(rgb) const = 0;
  virtual int     handle_mvt(Snake*) const = 0;
  virtual void    refresh() const = 0;
  virtual int     get_v() const = 0;
};

#endif