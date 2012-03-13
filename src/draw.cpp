//
// draw.cpp for  in /home/vailla_y/Projet/nibler
//
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
//
// Started on  Mon Mar 12 12:38:43 2012 yann vaillant
// Last update Tue Mar 13 10:36:24 2012 yann vaillant
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
#include "draw.hh"
#include "map.hh"
#include "snake.hh"

Draw::Draw(Map *_map)
{
  this->map = _map;
}

Draw::~Draw()
{

}

void	Draw::add_cube(GLuint text)
{
  glBindTexture(GL_TEXTURE_2D, text);
  glPushMatrix();
  glBegin(GL_POLYGON);
  
  glTexCoord2d(0,1);
  glTexCoord2d(0,0); 
  glTexCoord2d(1,0); 
  glTexCoord2d(1,1);

  /*top*/
  glColor3ub(112,128,144);
  glVertex3d(0, 0, 0);
  glVertex3d(0, 0, -1);
  glVertex3d(-1, 0, -1);
  glVertex3d(-1, 0, 0);
  
  /*front*/
  glColor3ub(185,211,238); 
  glVertex3d(0, 0, 0);
  glVertex3d(-1, 0, 0);
  glVertex3d(-1, -1, 0);
  glVertex3d(0, -1, 0);
  
  /*right*/
  glColor3ub(198,226,255);
  glVertex3d(0, 0, 0);
  glVertex3d(0, -1, 0);
  glVertex3d(0, -1, -1);
  glVertex3d(0, 0, -1);
  
  /*left*/
  glColor3ub(198, 226 ,255);
  glVertex3d(-1, 0, 0);
  glVertex3d(-1, 0, -1);
  glVertex3d(-1, -1, -1);
  glVertex3d(-1, -1, 0);
  
  /*bottom*/
  glColor3ub(112,128,144);
  glVertex3d(0, 0, 0);
  glVertex3d(0, -1, -1);
  glVertex3d(-1, -1, -1);
  glVertex3d(-1, -1, 0);
  
  /*back*/
  glColor3ub(0,125,0);
  glVertex3d(0, 0, 0);
  glVertex3d(-1, 0, -1);
  glVertex3d(-1, -1, -1);
  glVertex3d(0, -1, -1);
  
  glEnd();
  glPopMatrix();
}

SDL_Surface * Draw::flipSurface(SDL_Surface * surface)
{
  int current_line,pitch;
  SDL_Surface * fliped_surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
						      surface->w,surface->h,
						      surface->format->BitsPerPixel,
						      surface->format->Rmask,
						      surface->format->Gmask,
						      surface->format->Bmask,
						      surface->format->Amask);
  SDL_LockSurface(surface);
  SDL_LockSurface(fliped_surface);
  pitch = surface->pitch;
  for (current_line = 0; current_line < surface->h; current_line ++)
    {
      memcpy(&((unsigned char* )fliped_surface->pixels)[current_line*pitch],
	     &((unsigned char* )surface->pixels)[(surface->h - 1  -
						  current_line)*pitch], pitch);
    }
  SDL_UnlockSurface(fliped_surface);
  SDL_UnlockSurface(surface);
  return fliped_surface;
}

GLuint Draw::loadTexture(const char * filename, bool useMipMap)
{
  GLuint glID;
  SDL_Surface * picture_surface = NULL;
  SDL_Surface *gl_surface = NULL;
  SDL_Surface * gl_fliped_surface = NULL;
  Uint32 rmask, gmask, bmask, amask;
  SDL_PixelFormat format;

  picture_surface = IMG_Load(filename);
  if (picture_surface == NULL)
    return 0;
  rmask = 0xff000000;
  gmask = 0x00ff0000;
  bmask = 0x0000ff00;
  amask = 0x000000ff;
  format = *(picture_surface->format);
  format.BitsPerPixel = 32;
  format.BytesPerPixel = 4;
  format.Rmask = rmask;
  format.Gmask = gmask;
  format.Bmask = bmask;
  format.Amask = amask;
  gl_surface = SDL_ConvertSurface(picture_surface,&format,SDL_SWSURFACE);
  gl_fliped_surface = flipSurface(gl_surface);
  glGenTextures(1, &glID);
  glBindTexture(GL_TEXTURE_2D, glID);
  if (useMipMap)
    {
      gluBuild2DMipmaps(GL_TEXTURE_2D, 4, gl_fliped_surface->w,
			gl_fliped_surface->h, GL_RGBA,GL_UNSIGNED_BYTE,
			gl_fliped_surface->pixels);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,
		      GL_LINEAR_MIPMAP_LINEAR);
    }
  else
    {
      glTexImage2D(GL_TEXTURE_2D, 0, 4, gl_fliped_surface->w,
		   gl_fliped_surface->h, 0, GL_RGBA,GL_UNSIGNED_BYTE,
		   gl_fliped_surface->pixels);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    }
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  SDL_FreeSurface(gl_fliped_surface);
  SDL_FreeSurface(gl_surface);
  SDL_FreeSurface(picture_surface);
  return (glID);
}

void	Draw::init_lib()
{
  SDL_Surface* screen;
  GLuint wall;
  GLuint snake;
 
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("NOOBLEUR",NULL);
  screen = SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective(70,(double)640/480,1,1000);
  glEnable(GL_DEPTH_TEST);
//  glEnable(GL_TEXTURE_2D);
  this->wall = loadTexture("img/wall.jpg", true);;
}

void	Draw::draw_snake(Snake *snake)
{
  // glPushMatrix();
  glTranslatef(-(snake->get_x()), snake->get_y(), 0);
  Draw::add_cube(this->wall);
  //glPopMatrix();
}

void	Draw::refresh()
{
  glEnd();
  glFlush();
  SDL_GL_SwapBuffers();
}

void	Draw::draw_map()
{
  int   i = 0;
  int   j = 0;
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0,20,18, 0,0,0, 0,0,1);
  glBegin(GL_QUADS);
  while (i < this->map->get_x())
    {
      j = 0;
      while (j < this->map->get_y())
	{
	  if (this->map->get_map()[i][j] == 'X')
	    Draw::add_cube(this->wall);
	  if (this->map->get_map()[i][j] == '.')
	    {
	      glTranslatef(0.0f, 0.0f, -1.0f);	    
	      Draw::add_cube(this->wall);
	      glTranslatef(0.0f, 0.0f, 1.0f);	    
	    }
	  glTranslatef(0.0f, 1.0f, 0.0f);	    
	  j++;
	}
      glTranslatef(1.0f, -j, 0.0f);
      i++;
    }
}

int	Draw::handle_mvt(Snake* snake) 
{
  SDL_Event event;
  int	ret = 0;
  
  SDL_PollEvent(&event);
  switch(event.type)
    {
    case SDL_QUIT:
      return (-1);
    }
  switch(event.key.keysym.sym)
    {
    case SDLK_LEFT:
      snake->move_right();
      ret = 1;
      break;
    case SDLK_RIGHT:
      snake->move_left();
      ret = 1;
      break;
    case SDLK_UP:
      snake->move_down();
      ret = 1;
      break;
    case SDLK_DOWN:
      snake->move_up();
      ret = 1;
      break;
    default:
      break;
    }
  return (ret);
}

