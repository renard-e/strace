/*
** ident_flag.c for  in /home/renard_e/poubelle_test/test_strace
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Apr  3 12:58:04 2017 Gregoire Renard
** Last update Mon Apr  3 13:00:25 2017 Gregoire Renard
*/

#include "strace.h"

int			ident_flag(char *arg)
{
  if (arg[0] == '-' && arg[1] == 'p')
    return (SUCCESS);
  return (ERROR);
}
