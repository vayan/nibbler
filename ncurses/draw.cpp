//
// drawNcurses.cpp for nibbler in /home/tanter_l//local/Semestre_04/nibbler
// 
// Made by ludovic tanter
// Login   <tanter_l@epitech.net>
// 
// Started on  Wed Mar 14 11:48:26 2012 ludovic tanter
// Last update Fri Mar 16 13:59:36 2012 robin maitre
//

#include	<curses.h>
#include	<ncurses.h>
#include	<list>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>

#include	"draw.hh"
#include	"map.hh"
#include	"snake.hh"

Draw::Draw()
{
}

Draw::~Draw()
{
}

int		Draw::handle_mvt(Snake *snake)
{
  int		key;

  key = getch();
  if (key == 27)
    return (-1);
  else
    {
      if (key == KEY_RIGHT)
	snake->set_dir(Up);
      else if (key == KEY_LEFT)
	snake->set_dir(Down);
      else if (key == KEY_UP)
	snake->set_dir(Right);
      else if (key == KEY_DOWN)
	snake->set_dir(Left);
    }
  return (0);
}

void		Draw::draw_map(Map *map)
{
  int		x = 0;
  int		y = 0;

  while (y < map->get_y())
    {
      x = 0;
      while (x < map->get_x())
    	{
    	  move(x, y);
    	  if (map->get_map()[x][y] == 'X')
    	    {
    	      attron(COLOR_PAIR(1));
    	      printw(" ");
    	      attroff(COLOR_PAIR(1));
    	    }
    	  else if (map->get_map()[x][y] == '.')
    	    {
    	      attron(COLOR_PAIR(2));
    	      printw(" ");
    	      attroff(COLOR_PAIR(2));
    	    }
    	  x++;
    	}
      y++;
    }
}

void		Draw::draw_snake(Snake *snake)
{
  std::list<int*> pos = snake->get_pos();

  for (std::list<int*>::iterator it = pos.begin(); it != pos.end(); ++it)
    {
      move((*it)[0], (*it)[1]);
      if (it == pos.begin())
	{
	  attron(COLOR_PAIR(4));
	  printw(" ");
	  attroff(COLOR_PAIR(4));
	}
      else
	{
	  attron(COLOR_PAIR(6));
	  printw(" ");
	  attroff(COLOR_PAIR(6));
	}
    }
}

void		Draw::draw_food(Food *food)
{
  move(food->get_x(), food->get_y());
  attron(COLOR_PAIR(5));
  printw(" ");
  attroff(COLOR_PAIR(5));
}

void		Draw::init_lib(Map *map)
{  
  initscr();
  start_color();
  this->v = 2;
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  init_pair(2, COLOR_BLACK, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_RED);
  init_pair(4, COLOR_BLUE, COLOR_BLUE);
  init_pair(5, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(6, COLOR_GREEN, COLOR_GREEN);
  curs_set(0);
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  noecho();
}

int		Draw::get_v()
{
  return (this->v);
}

__attribute__((destructor)) void end()
{
  curs_set(1);  
  clear();
  refresh();
  endwin();  
}

void		Draw::refresh()
{
}

void		Draw::add_cube(rgb color)
{
}

void    Draw::end_surface()
{
}

extern "C" ILib* create_draw()
  {
    return (new Draw());
  }
