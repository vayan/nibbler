//
// snake.hh for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 17:47:38 2012 yann vaillant
// Last update Tue Mar 13 13:04:50 2012 yann vaillant
//

#ifndef _SNAKE_
#define _SNAKE_

#include <list>
#include "map.hh"

typedef enum Direction {
  Up = 1,
  Down = -1,
  Left = 2,
  Right = -2
} Direction;

class Snake
{
public:
	                Snake(Map*);
	                ~Snake() {}
  void	          move_up();
  void	          move_down();
  void	          move_left();
  void	          move_right();
  int	            get_x();
  int	            get_y();
  Direction       get_dir();
  void            set_dir(Direction);
  int	            get_lenght();
  void            set_lenght(int val);
  int	            get_speed();
  void            set_speed(int val);
  int             get_score();
  void            set_score(int val);
  void            add_lenght(int x, int y);
  std::list<int*> get_pos();
private:
  int             score;
  int             pos_x;
  int             pos_y;
  int             lenght;
  std::list<int*> pos;
  int	            speed;
  Direction       dir;
};

#endif
