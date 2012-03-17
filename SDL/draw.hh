//
// draw.hh for nibbler in /home/maitre_r//tek2/proj/nibbler/nibbler-2015-maitre_r/SDL
// 
// Made by robin maitre
// Login   <maitre_r@epitech.net>
// 
// Started on  Thu Mar 15 16:46:44 2012 robin maitre
// Last update Sat Mar 17 18:56:16 2012 ludovic tanter
//

#ifndef _DRAW_
#define _DRAW_

#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "map.hh"
#include "snake.hh"
#include "food.hh"
#include "ILib.hh"

class	Draw : public ILib
{
public:
  Draw();
  ~Draw();
  void	init_lib(Map*) ;
  void	draw_map(Map*) ;
  void	draw_snake(Snake*) ;
  void	draw_food(Food*);
  void	add_cube(rgb) ;
  int	handle_mvt(Snake*);
  void	refresh();
  int	get_v();
  void	end();
  void	end_surface();

private:
  int	v;
  Map	*map;
  SDL_Surface	*block;
  SDL_Surface	*grass;
  SDL_Surface	*food;
  SDL_Surface	*lapin;
  SDL_Surface	*snake_h;
  SDL_Surface   *snake_b;
  SDL_Surface	*ecran;
};

#endif
