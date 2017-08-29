/*
** check_pid.c for  in /home/renard_e/poubelle_test/test_strace
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Apr  3 13:55:44 2017 Gregoire Renard
** Last update Mon Apr  3 14:07:15 2017 Gregoire Renard
*/

#include "strace.h"

int			check_pid(t_info *info)
{
  pid_t			pid;

  if (info->arg[0].on == -1)
    return (SUCCESS);
  pid =(pid_t)(atoi(info->arg[0].value));
  if ((kill(pid, 0)) == 0)
    return (SUCCESS);
  return (printf_error("strace: No such process or not permited"));
}
