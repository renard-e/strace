/*
** main.c for  in /home/renard_e/poubelle_test/test_strace
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Apr  3 11:37:02 2017 Gregoire Renard
** Last update Sun Apr 16 12:52:15 2017 Gregoire Renard
*/

#include "strace.h"

static void				free_global()
{
  int				cpt;

  cpt = 0;
  while (cpt < 329)
    {
      free(g_tab_syscall[cpt].name);
      free(g_tab_syscall[cpt].ret);
      free_map(g_tab_syscall[cpt].param);
      cpt++;
    }
}

static void		free_all(t_info *info)
{
  int			cpt;

  cpt = 0;
  free(info->executable);
  while (info->exec_arg[cpt] != NULL)
    {
      free(info->exec_arg[cpt]);
      cpt++;
    }
  free(info->exec_arg);
  if (info->arg[0].on == 1)
    {
      free(info->arg[0].opt);
      free(info->arg[0].value);
    }
  if (info->arg[1].on == 1)
    free(info->arg[0].opt);
  free_global();
}

static void		init_all_info(t_info *info, char **env,
				      int argc)
{
  int			cpt;

  cpt = 0;
  while (cpt < MAX_ARG)
    {
      info->arg[cpt].on = -1;
      info->arg[cpt].opt = NULL;
      info->arg[cpt].value = NULL;
      cpt++;
    }
  info->executable = NULL;
  info->env = env;
  if ((info->exec_arg = malloc(sizeof(char *) * (argc + 2))) == NULL)
    exit(ERROR);
  info->exec_arg[0] = NULL;
}

int			main(int argc, char **argv, char **env)
{
  t_info		info;

  if (argc == 1)
    return (printf_error("strace: must have PROG [ARGS] or -p [PID]"));
  else
    {
      init_all_info(&info, env, argc);
      if ((init_syscall()) == ERROR)
	return (ERROR);
      if ((fill_info(&info, argv)) == ERROR)
	return (ERROR);
      if ((start_strace(&info)) == ERROR)
      	return (ERROR);
      free_all(&info);
    }
  return (SUCCESS);
}
