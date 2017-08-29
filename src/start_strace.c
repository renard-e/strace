/*
** start_strace.c for  in /home/renard_e/poubelle_test/test_strace
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Apr  3 14:15:17 2017 Gregoire Renard
** Last update Sun Apr 16 15:53:26 2017 Gregoire Renard
*/

#include "strace.h"

int				start_strace(t_info *info)
{
  if (info->arg[0].on == -1)
    {
      if ((info->child = fork()) == -1)
	return (ERROR);
      if (info->child == 0)
	{
	  if ((child_proccess(info)) == ERROR)
	    return (ERROR);
	}
      else
	if ((father_proccess(info)) == ERROR)
	  return (ERROR);
    }
  else
    {
      if ((child_pid(info)) == ERROR)
	return (ERROR);
      if ((ptrace(PTRACE_DETACH, atoi(info->arg[0].value),
		  NULL, NULL)) == -1)
	return (-1);
    }
  return (SUCCESS);
}
