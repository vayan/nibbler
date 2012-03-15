//
// draw.hh for  in /home/vailla_y/Projet/nibler
//
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
//
// Started on  Mon Mar 12 12:33:30 2012 yann vaillant
// Last update Tue Mar 13 14:08:05 2012 yann vaillant
//

#ifndef _DRAW_
#define _DRAW_

#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "map.hh"
#include "snake.hh"
#include "food.hh"
#include "ILib.hh"

class Draw : public ILib
{
public:
		      Draw();
		      ~Draw();
  void		init_lib(Map*) const;
  void		draw_map(Map*) const;
  void		draw_snake(Snake*) const;
  void    draw_food(Food*) const;
  void		add_cube(rgb) const;
  int     handle_mvt(Snake*) const;
  void    refresh() const;
  int     get_v() const;
private:
  int      v;
  Map		   *map;
  GLuint	 wall;
};

#endif
