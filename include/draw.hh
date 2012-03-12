//
// draw.hh for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 12:33:30 2012 yann vaillant
// Last update Mon Mar 12 18:15:00 2012 yann vaillant
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

class Draw 
{
public:
  Draw(Map*);
  ~Draw();  
  void		init_lib();
  void		draw_map();
  void		draw_snake(Snake*);
  void		add_cube(GLuint text);
  bool		check_exit();
  GLuint	loadTexture(const char *, bool);
  SDL_Surface*	flipSurface(SDL_Surface *);
  void		refresh();
private:
  Map *map;
  GLuint wall;
};

#endif
