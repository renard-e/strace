/*
** printf_error.c for  in /home/renard_e/poubelle_test/test_strace
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Apr  3 11:39:11 2017 Gregoire Renard
** Last update Mon Apr  3 11:39:55 2017 Gregoire Renard
*/

#include "strace.h"

int				printf_error(char *str)
{
  printf("%s\n", str);
  return (ERROR);
}
