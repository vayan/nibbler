//
// snake.hh for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 17:47:38 2012 yann vaillant
// Last update Mon Mar 12 18:10:55 2012 yann vaillant
//

#ifndef _SNAKE_
#define _SNAKE_

class Snake
{
public:
	Snake();
	~Snake() {}
  void	move_up();
  void	move_down();
  void	move_left();
  void	move_right();
  int	get_x();
  int	get_y();
  int	get_lenght();
  int	get_speed();
private:
  int	pos_x;
  int	pos_y;
  int	lenght;
  int	speed;
};

#endif
