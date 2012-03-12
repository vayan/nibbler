//
// map.cpp for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 11:40:49 2012 yann vaillant
// Last update Mon Mar 12 14:22:58 2012 yann vaillant
//


#include <iostream>
#include <string>
#include "map.hh"


Map::Map(int x, int y)
{
  std::vector< std::vector<char> > _map;
  
  _map.resize(y);
  for (int i = 0; i < y; ++i)
    _map[i].resize(x);
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
