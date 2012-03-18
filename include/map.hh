//
// map.hh for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 11:33:07 2012 yann vaillant
// Last update Sun Mar 18 23:08:39 2012 robin maitre
//

#ifndef MAP_HH
#define MAP_HH

#include <vector>

class	Map 
{
public :
  Map();
  Map(int x, int y);
  ~Map();
  void	init_map();
  void	aff_map() const;
  std::vector< std::vector<char> > get_map();
  int	get_x();
  int	get_y();

private:
  int	x;
  int	y;
  std::vector< std::vector<char> > map;
};

#endif
