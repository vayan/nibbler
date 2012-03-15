//
// food.cpp for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Tue Mar 13 14:29:57 2012 yann vaillant
// Last update Tue Mar 13 15:10:48 2012 yann vaillant
//

#include "food.hh"

Food::Food(int x, int y)
{
 	this->x = x;
 	this->y = y; 
}

void Food::set_x(int val)
{
	this->x = val;
}

void Food::set_y(int val)
{
	this->y = val;
}

int	Food::get_x()
{
  return (x);
}

int	Food::get_y()
{
  return (y);
}

