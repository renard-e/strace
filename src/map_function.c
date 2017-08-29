/*
** map_function.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_strace/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Apr 13 12:19:26 2017 Gregoire Renard
** Last update Fri Apr 14 15:50:40 2017 Gregoire Renard
*/

#include "strace.h"

void				print_map(char **map)
{
  int				cpt;

  cpt = 0;
  while (map[cpt] != NULL)
    {
      printf("*%s*\n", map[cpt]);
      cpt++;
    }
}

void				free_map(char **map)
{
   int				cpt;

  cpt = 0;
  while (map[cpt] != NULL)
    {
      free(map[cpt]);
      cpt++;
    }
  free(map);
}

void				print_global()
{
  int				cpt;

  cpt = 0;
  while (cpt < 329)
    {
      printf("g_tab_syscall[%i].name = %s\n", g_tab_syscall[cpt].number,
	     g_tab_syscall[cpt].name);
      printf("g_tab_syscall[%i].ret = %s\n", g_tab_syscall[cpt].number,
	     g_tab_syscall[cpt].ret);
      printf("param = \n");
      print_map(g_tab_syscall[cpt].param);
      printf("-------------------------\n");
      cpt++;
    }
}
