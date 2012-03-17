//
// food.hh for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Tue Mar 13 14:30:02 2012 yann vaillant
// Last update Sat Mar 17 18:47:32 2012 ludovic tanter
//

#ifndef _FOOD_H
#define _FOOD_H

class	Food 
{
public:
  Food();
  Food(int, int);
  ~Food() {};
  int	get_x();
  int	get_y();
  void	set_x(int val);
  void	set_y(int val);
private:
  int  	x;
  int  	y;
};

#endif
