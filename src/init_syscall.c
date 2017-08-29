/*
** init_syscall.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_strace/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Apr 13 10:19:20 2017 Gregoire Renard
** Last update Sun Apr 16 12:56:24 2017 Gregoire Renard
*/

#include "strace.h"

static int			assign_value_global(char **tab, int case_g)
{
  int				cpt;

  cpt = 1;
  g_tab_syscall[case_g].number = case_g;
  if ((g_tab_syscall[case_g].name = strdup(tab[0]))
      == NULL)
    return (ERROR);
  if ((g_tab_syscall[case_g].param = malloc(sizeof(char *) * 10))
      == NULL)
    return (ERROR);
  while (tab[cpt + 2] != NULL)
    {
      if ((g_tab_syscall[case_g].param[cpt - 1] = strdup(tab[cpt]))
	  == NULL)
	return (ERROR);
      cpt++;
    }
  g_tab_syscall[case_g].param[cpt] = NULL;
  if ((g_tab_syscall[case_g].ret = strdup(tab[cpt + 1])) == NULL)
    return (ERROR);
  return (SUCCESS);
}

static int			grep_number(char **tab)
{
  int				cpt;

  cpt = 0;
  while (tab[cpt] != NULL)
    cpt++;
  cpt = cpt - 2;
  return (atoi(tab[cpt]));
}

static int			search_file()
{
  t_getline			proto;
  char				**tab;
  int				number;

  if ((proto.file = fopen("src/config.txt", "r")) == NULL)
    return (ERROR);
  proto.size = 0;
  proto.line = NULL;
  while ((getline(&proto.line, &proto.size, proto.file)) > 0)
    {
      if ((tab = my_str_to_word_tab(proto.line)) == NULL)
	return (ERROR);
      number = grep_number(tab);
      if ((assign_value_global(tab, number)) == ERROR)
	return (ERROR);
      proto.size = 0;
      free_map(tab);
      free(proto.line);
    }
  return (SUCCESS);
}

int				init_syscall()
{
  if ((search_file()) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
