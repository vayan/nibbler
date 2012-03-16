//
// draw_sdl.cpp for nibbler in /home/maitre_r//tek2/proj/nibbler/nibbler-2015-maitre_r
// 
// Made by robin maitre
// Login   <maitre_r@epitech.net>
// 
// Started on  Tue Mar 13 11:05:11 2012 robin maitre
// Last update Fri Mar 16 14:04:01 2012 robin maitre
//

#include <iostream>
#include <string>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "draw.hh"
#include "map.hh"
#include "snake.hh"

Draw::Draw()
{

}

Draw::~Draw()
{

}

int   Draw::get_v()
{
  return (this->v);
}

void    Draw::add_cube(rgb color)
{
}

void	Draw::init_lib(Map *map)
{
  this->v = 2;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("NOOBLEUR",NULL);
  this->ecran = SDL_SetVideoMode(map->get_x() * 32, map->get_y() * 32, 32, SDL_HWSURFACE);
  this->block = IMG_Load("sprite/brick.png");
  this->grass = IMG_Load("sprite/grass.jpg");
  this->food = IMG_Load("sprite/lapin.gif");
  this->snake_h = IMG_Load("sprite/snake_head.png");
  this->snake_b =IMG_Load("sprite/snake_body.png"); 
}

void  Draw::draw_snake(Snake *snake)
{
  SDL_Rect	possnake;
  std::list<int*> pos = snake->get_pos();
  
  for (std::list<int*>::iterator it = pos.begin(); it != pos.end(); ++it)
    {
      possnake.x = (*it)[0] * 32;
      possnake.y = (*it)[1] * 32;      
      if (it == pos.begin())
        SDL_BlitSurface(this->snake_h, NULL, this->ecran, &possnake);
      else
        SDL_BlitSurface(this->snake_b, NULL, this->ecran, &possnake);
    }
}

void  Draw::draw_food(Food *food)
{
  SDL_Rect	posfood;

  posfood.x = food->get_x() * 32;
  posfood.y = food->get_y() * 32;
  SDL_BlitSurface(this->food, NULL, this->ecran, &posfood);
}

void    Draw::refresh()
{
  SDL_Flip(ecran);
}

void	Draw::draw_map(Map *map)
{
  int	i;
  int	j;
  SDL_Rect	posobj;

  i = 0;
  j = 0;
  while (i < map->get_x())
    {
      j = 0;
      posobj.x = i * 32;
      while (j < map->get_y())
	{
	  posobj.y = j * 32;
	  if (map->get_map()[i][j] == 'X')
	    SDL_BlitSurface(this->block, NULL, this->ecran, &posobj);
	  if (map->get_map()[i][j] == '.')
	    SDL_BlitSurface(this->grass, NULL, this->ecran, &posobj);
	  j++;	
	}
      i++;
    }
}

int     Draw::handle_mvt(Snake* snake)
{
  SDL_Event event;
  int   ret = 0;

  SDL_PollEvent(&event);
  if (event.type == SDL_QUIT)
    return (-1);
  if (event.type == SDL_KEYDOWN)
    {
      switch(event.key.keysym.sym)
        {
        case SDLK_SPACE:
          snake->set_speed(snake->get_speed() + 30);
          break;
        case SDLK_LEFT:
	  snake->set_dir(Right);
          break;
	case SDLK_RIGHT:
	  snake->set_dir(Left);
          break;
        case SDLK_UP:
	  snake->set_dir(Down);
          break;
	case SDLK_DOWN:
	  snake->set_dir(Up);
          break;
	case SDLK_ESCAPE:
          return (-1);
          break;
	default:
          break;
	}
    }
  if (event.type == SDL_KEYUP)
    if (event.key.keysym.sym == SDLK_SPACE)
      snake->set_speed(snake->get_speed() - 30);
  return (ret);
}

void	Draw::end_surface()
{
  SDL_FreeSurface(this->block);
  SDL_FreeSurface(this->grass);
  SDL_FreeSurface(this->lapin);
  SDL_FreeSurface(this->snake_h);
  SDL_FreeSurface(this->snake_b);
}

extern "C" ILib* create_draw()
{
  return (new Draw());
}

__attribute__((destructor))  void  end()
{

}
