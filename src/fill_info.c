/*
** fill_info.c for  in /home/renard_e/poubelle_test/test_strace
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Apr  3 11:56:44 2017 Gregoire Renard
** Last update Sun Apr 16 12:56:10 2017 Gregoire Renard
*/

#include "strace.h"

static int		assign_concat(t_info *info, char *arg)
{
  int			cpt;
  int			cpt2;

  cpt = 2;
  cpt2 = 0;
  if (strlen(arg) > 12)
    return (printf_error("strace: No such process"));
  if ((info->arg[0].value = malloc(strlen(arg))) == NULL)
    return (ERROR);
  while (arg[cpt] != '\0')
    {
      if (arg[cpt] < '0' || arg[cpt] > '9')
	return (printf_error("strace: No such process"));
      info->arg[0].value[cpt2] = arg[cpt];
      cpt++;
      cpt2++;
    }
  info->arg[0].value[cpt2] = '\0';
  return (SUCCESS);
}

static int		test_valid_file(t_info *info, char *arg)
{
  if (info->executable != NULL)
    {
      if ((remp_exec_arg(info, arg)) == ERROR)
	return (ERROR);
    }
  else
    {
      if ((info->executable = strdup(arg)) == NULL)
	return (ERROR);
      if ((info->exec_arg[0] = strdup(arg)) == NULL)
	return (ERROR);
      info->exec_arg[1] = NULL;
    }
  return (SUCCESS);
}

static int		set_value(t_info *info, char **argv, int *cpt)
{
  if (argv[*cpt][2] == '\0')
    {
      (*cpt)++;
      if ((info->arg[0].value = strdup(argv[*cpt])) == NULL)
	return (ERROR);
    }
  else
    if ((assign_concat(info, argv[*cpt])) == ERROR)
      return (ERROR);
  return (SUCCESS);
}

static int		test_command(t_info *info, char **argv, int *cpt)
{
  if ((ident_flag(argv[*cpt])) == SUCCESS &&
      info->executable == NULL)
    {
      if (info->executable != NULL)
	return (SUCCESS);
      info->arg[0].on = 1;
      if ((info->arg[0].opt = strdup("-p")) == NULL)
	return (ERROR);
      if ((set_value(info, argv, cpt)) == ERROR)
	return (ERROR);
    }
  else if ((strcmp(argv[*cpt], "-s")) == 0 && info->executable == NULL)
    {
      info->arg[1].on = 1;
      if ((info->arg[1].opt = strdup(argv[*cpt])) == NULL)
	return (ERROR);
    }
  else
    if ((test_valid_file(info, argv[*cpt])) == ERROR)
      return (ERROR);
  return (SUCCESS);
}

int			fill_info(t_info *info, char **argv)
{
  int			cpt;

  cpt = 1;
  while (argv[cpt] != NULL)
    {
      if ((test_command(info, argv, &cpt)) == ERROR)
	return (ERROR);
      cpt++;
    }
  if ((check_pid(info)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
