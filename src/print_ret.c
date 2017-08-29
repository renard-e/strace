/*
** print_ret.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_strace/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Apr 14 15:58:58 2017 Gregoire Renard
** Last update Fri Apr 14 19:39:37 2017 Gregoire Renard
*/

#include "strace.h"

static void			print_end_void(struct user_regs_struct *regst)
{
  if ((strstr(g_tab_syscall[regst->orig_rax].ret, "0")) != NULL)
    printf(" = ?");
  else
    printf(" = %p", (void *)(regst->rax));
}

static void			print_real(struct user_regs_struct *regst)
{
  if ((strstr(g_tab_syscall[regst->orig_rax].ret,
	      "int")) != NULL)
    printf(" = %lld", regst->rax);
  else if ((strstr(g_tab_syscall[regst->orig_rax].ret,
		   "void")) != NULL)
    print_end_void(regst);
  else if ((strstr(g_tab_syscall[regst->orig_rax].ret,
		   "long")) != NULL)
    printf(" = %lld", regst->rax);
  else if ((strstr(g_tab_syscall[regst->orig_rax].ret,
		   "char")) != NULL)
    printf(" = %lld", regst->rax);
  else if ((strstr(g_tab_syscall[regst->orig_rax].ret,
		   "struct")) != NULL)
    printf(" = %p", (void *)regst->rax);
}

void				print_ret(struct user_regs_struct *regst,
					  t_info *info)
{
  if (info->arg[1].on == 1)
    print_real(regst);
  else
    {
      if ((strstr(g_tab_syscall[regst->orig_rax].ret,
		  "int")) != NULL)
	printf(" = 0x%x", (int)regst->rax);
      else if ((strstr(g_tab_syscall[regst->orig_rax].ret,
		       "void")) != NULL)
	print_end_void(regst);
      else if ((strstr(g_tab_syscall[regst->orig_rax].ret,
		       "long")) != NULL)
	printf(" = 0x%llx", regst->rax);
      else if ((strstr(g_tab_syscall[regst->orig_rax].ret,
		       "char")) != NULL)
	printf(" = 0x%x", (int)regst->rax);
      else if ((strstr(g_tab_syscall[regst->orig_rax].ret,
		       "struct")) != NULL)
	printf(" = %p", (void *)regst->rax);
    }
}
