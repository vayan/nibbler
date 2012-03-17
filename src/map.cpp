//
// map.cpp for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 11:40:49 2012 yann vaillant
// Last update Sat Mar 17 18:44:04 2012 ludovic tanter
//


#include <iostream>
#include <string>
#include <stdlib.h>

#include "map.hh"

Map::Map(int x, int y)
{
  std::vector< std::vector<char> > _map;
  
  if (x < 10 || y < 10)
    {
      std::cout << "Error : size lower than 10x10" << std::endl;
      exit (11);
    }
  _map.resize(x);
  for (int i = 0; i < x; ++i)
    _map[i].resize(y);
  this->map = _map;
  this->x = x;
  this->y = y;
  init_map();
}

Map::~Map()
{
}

void	Map::init_map()
{
  int	i = 0;
  int	j;

  while (i < this->x)
    {
      j = 0;
      while (j < this->y)
      	{
      	  if (i == 0 || j == 0 || i == (this->x - 1) || j == (this->y - 1))
      	    this->map[i][j] = 'X';
      	  else
      	    this->map[i][j] = '.';
      	  j++;
      	}
      i++;
    }
}

void	Map::aff_map()
{
  int	i = 0;
  int	j;
  
  while (i < this->x)
    {
      j = 0;
      while (j < this->y)
      	{
      	  std::cout << this->map[i][j];
      	  j++;
      	}
      std::cout << std::endl;
      i++;
    }
}

std::vector< std::vector<char> >  Map::get_map()
{
  return (this->map);
}

int	Map::get_x() 
{
  return (this->x);
}

int	Map::get_y()
{
  return (this->y);
}
