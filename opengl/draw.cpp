//
// draw.cpp for  in /home/vailla_y/Projet/nibler
//
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
//
// Started on  Mon Mar 12 12:38:43 2012 yann vaillant
// Last update Fri Mar 16 14:37:03 2012 ludovic tanter
//

#include <iostream>
#include <string>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include <list>
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

void	Draw::add_cube(rgb color)
{
  glPushMatrix();
  glBegin(GL_POLYGON);
  
  /*top*/
  glColor3ub(color.r ,color.g,color.b);
  glVertex3d(0, 0, 0);
  glVertex3d(0, 0, -1);
  glVertex3d(-1, 0, -1);
  glVertex3d(-1, 0, 0);
  
  /*front*/
  glColor3ub(color.r * (1 - 0.5) ,color.g * (1 - 0.5),color.b * (1 - 0.5) );
  glVertex3d(0, 0, 0);
  glVertex3d(-1, 0, 0);
  glVertex3d(-1, -1, 0);
  glVertex3d(0, -1, 0);
  
  /*right*/
  glColor3ub(color.r ,color.g ,color.b);
  glVertex3d(0, 0, 0);
  glVertex3d(0, -1, 0);
  glVertex3d(0, -1, -1);
  glVertex3d(0, 0, -1);
  
  /*left*/
  glColor3ub(color.r * (1 - 0.5),color.g * (1 - 0.5),color.b * (1 - 0.5));
  glVertex3d(-1, 0, 0);
  glVertex3d(-1, 0, -1);
  glVertex3d(-1, -1, -1);
  glVertex3d(-1, -1, 0);
  
  /*bottom*/
  glColor3ub(color.r ,color.g,color.b);
  glVertex3d(0, 0, 0);
  glVertex3d(0, -1, -1);
  glVertex3d(-1, -1, -1);
  glVertex3d(-1, -1, 0);
  
  /*back*/
  glColor3ub(color.r ,color.g,color.b);
  glVertex3d(0, 0, 0);
  glVertex3d(-1, 0, -1);
  glVertex3d(-1, -1, -1);
  glVertex3d(0, -1, -1);
  
  glEnd();
  glPopMatrix();
}

void	Draw::init_lib(Map* map)
{
  SDL_Surface* screen;
  int width;
  int height;
 
  this->v = 1;
  width = map->get_x() + 800;
  height = map->get_y() + 600;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("NOOBLEUR",NULL);
  screen = SDL_SetVideoMode(width, height, 32, SDL_OPENGL);
  if (screen == NULL)
    exit (EXIT_FAILURE);
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective(70,(double)width/height,1,1000);
  glEnable(GL_DEPTH_TEST);
  //glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void  Draw::draw_snake(Snake *snake)
{
  std::list<int*> pos = snake->get_pos();
  rgb color;
  rgb color_head;

  color_head.r = 128;  
  color_head.g = 0;
  color_head.b = 0;

  color.r = 255;
  color.g = 0;
  color.b = 0;

  for (std::list<int*>::iterator it = pos.begin(); it != pos.end(); ++it)
    {
      glTranslatef(-((*it)[0]), (*it)[1], 0);
      if (it == pos.begin())
        Draw::add_cube(color_head);
      else
        Draw::add_cube(color);
      glTranslatef(((*it)[0]), -(*it)[1], 0);
    }
}

void  Draw::draw_food(Food *food)
{
  rgb color;

  color.r = 0;
  color.g = 255;
  color.b = 0;

  glTranslatef(-(food->get_x()), (food->get_y()), 0);
  Draw::add_cube(color);
}

void	Draw::refresh()
{
  //SDL_EventState(SDL_KEYDOWN, SDL_ENABLE);
  //SDL_EventState(SDL_KEYUP, SDL_ENABLE);
  glEnd();
  glFlush();
  SDL_GL_SwapBuffers();
}

void	Draw::draw_map(Map *map)
{
  int   i = 0;
  int   j = 0;
  rgb wall;
  rgb floo;


  wall.r = 139;
  wall.g = 69;
  wall.b = 19;
  floo.r = 162;
  floo.g = 205;
  floo.b = 90;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0, 0, 0);
  gluLookAt(map->get_x() / 2, map->get_y() + 5, (map->get_x() / 2) + 5 , map->get_x() / 2, map->get_y() / 2, 0, 0,0,1);
  glBegin(GL_QUADS); 
  while (i < map->get_x())
    {
      j = 0;
      while (j < map->get_y())
	     {
    	  if (map->get_map()[i][j] == 'X')
    	    Draw::add_cube(wall);
    	  if (map->get_map()[i][j] == '.')
    	    {
    	      glTranslatef(0.0f, 0.0f, -1.0f);	    
    	      Draw::add_cube(floo);
    	      glTranslatef(0.0f, 0.0f, 1.0f);	    
    	    }
    	  glTranslatef(0.0f, 1.0f, 0.0f);	    
    	  j++;
    	 }
      glTranslatef(1.0f, -map->get_y(), 0.0f);
      i++;
    }
}

int	Draw::handle_mvt(Snake* snake) 
{
  SDL_Event event;
  int	ret = 0;

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

void    Draw::end_surface()
{
}

extern "C" ILib* create_draw()
  {
    return (new Draw());
  }

__attribute__((destructor))  void  end()
{
 
}
