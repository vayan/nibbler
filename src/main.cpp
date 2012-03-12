//
// main.cpp for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 11:42:49 2012 yann vaillant
// Last update Mon Mar 12 17:54:48 2012 yann vaillant
//

#include "map.hh"
#include "draw.hh"
#include "snake.hh"
#include "core.hh"
#include <stdlib.h>
#include <string>

int	main(int ac, char **av)
{
  Map	map(atoi(av[1]), atoi(av[2])); 
  Draw  graph(&map);
  Snake new_snake;
  Core	core(&map, &graph, &new_snake);
  
  map.aff_map(); //test
  core.launch_game();

  //map.get_map();
  //  graph.init_lib();
  //graph.launch_game();
}

