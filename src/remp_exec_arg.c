/*
** remp_exec_arg.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_strace/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Apr 11 15:16:21 2017 Gregoire Renard
** Last update Tue Apr 11 15:27:34 2017 Gregoire Renard
*/

#include "strace.h"

int				remp_exec_arg(t_info *info, char *arg)
{
  int				cpt;

  cpt = 0;
  while (info->exec_arg[cpt] != NULL)
    cpt++;
  if ((info->exec_arg[cpt] = strdup(arg)) == NULL)
    return (ERROR);
  info->exec_arg[cpt + 1] = NULL;
  return (SUCCESS);
}
