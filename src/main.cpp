//
// main.cpp for  in /home/vailla_y/Projet/nibler
// 
// Made by yann vaillant
// Login   <vailla_y@epitech.net>
// 
// Started on  Mon Mar 12 11:42:49 2012 yann vaillant
// Last update Sat Mar 17 18:59:33 2012 ludovic tanter
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>	
#include <string>
#include <dlfcn.h>
#include <stdio.h>
#include <errno.h>

#include "map.hh"
#include "snake.hh"
#include "core.hh"
#include "ILib.hh"

int	main(int ac, char **av)
{
  if (ac != 4)
    {
      std::cout << "Usage : " << av[0] << " size_x size_y <lib_.so>" << std::endl;
      return (-1);
    }
  srand(time(NULL));
  Map	*map = new Map(atoi(av[1]), atoi(av[2])); 
  ILib* (*external_creator)();
  void* dlhandle;

  dlhandle = dlopen(av[3], RTLD_LAZY);
  if (dlhandle == NULL)
    {
      std::cout << dlerror() << std::endl;
      return (-1);
    }
  external_creator = reinterpret_cast<ILib* (*)()>(dlsym(dlhandle, "create_draw"));
  ILib* graph = external_creator();
  Snake *new_snake = new Snake(map);
  Core	core(map, graph, new_snake);

  core.launch_game();
  while (dlclose(dlhandle) != 0) { }
  return (0);
}
