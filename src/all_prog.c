/*
** all_prog.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_strace/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun Apr 16 15:22:34 2017 Gregoire Renard
** Last update Sun Apr 16 15:32:17 2017 Gregoire Renard
*/

#include "strace.h"

static void			print_arguments2(struct user_regs_struct *regst,
						 int cpt,
						 t_info *info)
{
  if ((strstr(g_tab_syscall[regst->orig_rax].param[cpt],
	      "struct")) != NULL)
    print_struct(regst, info, cpt);
  else if ((strstr(g_tab_syscall[regst->orig_rax].param[cpt],
		   "void")) != NULL)
    print_void(regst, info, cpt);
}

static void			print_arguments(struct user_regs_struct *regst,
						t_info *info)
{
  int				cpt;

  cpt = 0;
  while (g_tab_syscall[regst->orig_rax].param[cpt] != NULL)
    {
      if ((strstr(g_tab_syscall[regst->orig_rax].param[cpt],
		  "int")) != NULL)
	print_int(regst, info, cpt);
      else if ((strstr(g_tab_syscall[regst->orig_rax].param[cpt],
		       "char")) != NULL)
	print_char(regst, info, cpt);
      else if ((strstr(g_tab_syscall[regst->orig_rax].param[cpt],
		       "long")) != NULL)
	print_long(regst, info, cpt);
      else
	print_arguments2(regst, cpt, info);
      if (g_tab_syscall[regst->orig_rax].param[cpt + 1] != NULL)
	printf(", ");
      cpt++;
    }
  printf(")");
}

int				father_proccess(t_info *info)
{
  int				status;
  int				pass;
  struct user_regs_struct	regst;

  waitpid(info->child, &status, 0);
  pass = 0;
  while (!WIFEXITED(status))
    {
      if ((ptrace(PTRACE_GETREGS, info->child, NULL, &regst)) == -1)
	return (ERROR);
      if (regst.orig_rax <= 328)
	{
	  pass = 1;
	  printf("%s(", g_tab_syscall[regst.orig_rax].name);
	  print_arguments(&regst, info);
	  print_ret(&regst, info);
	  printf("\n");
	}
     if ((ptrace(PTRACE_SINGLESTEP, info->child, NULL, NULL)) == -1)
	return (ERROR);
      waitpid(info->child, &status, 0);
    }
  if (pass != 0)
    end_print(&regst, info);
  return (SUCCESS);
}

