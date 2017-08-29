/*
** child_exec.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_strace/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun Apr 16 14:56:47 2017 Gregoire Renard
** Last update Sun Apr 16 15:51:41 2017 Gregoire Renard
*/

#include "strace.h"

int				child_proccess(t_info *info)
{
  int				fd;

  if ((ptrace(PTRACE_TRACEME, info->child, NULL, NULL)) == -1)
    return (ERROR);
  if ((fd = open("trash.txt", O_WRONLY | O_TRUNC | O_CREAT,
  		 S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
    return (ERROR);
  if ((dup2(fd, 1)) == -1)
    return (ERROR);
  if ((execvp(info->executable, info->exec_arg)) == -1)
    {
      fprintf(stderr,
	      "strace: Can-t stat '%s': No such file or directory\n",
	      info->executable);
      return (ERROR);
    }
  return (SUCCESS);
}

int				child_pid(t_info *info)
{
  if ((ptrace(PTRACE_ATTACH, atoi(info->arg[0].value),
	      NULL, NULL)) == -1)
    return (ERROR);
  ptrace(PTRACE_CONT, atoi(info->arg[0].value),
	 NULL, NULL);
  info->child = atoi(info->arg[0].value);
  if ((father_proccess(info)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
