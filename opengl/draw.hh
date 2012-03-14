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
  void		init_lib();
  void		draw_map(Map*);
  void		draw_snake(Snake*);
  void    draw_food(Food*);
  void		add_cube();
  int     handle_mvt(Snake*);
  void    refresh();
private:
  Map		   *map;
  GLuint	 wall;
};

#endif
