/*
** print_end.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_strace/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Apr 14 13:48:03 2017 Gregoire Renard
** Last update Sun Apr 16 14:49:37 2017 Gregoire Renard
*/

#include "strace.h"

void				end_print(struct user_regs_struct *regst,
					  t_info *info)
{
  if (info->arg[1].on == -1)
    printf("%s(0x%llx) = ?\n", g_tab_syscall[regst->rax].name, regst->rdi);
  else
    printf("%s(%lld) = ?\n", g_tab_syscall[regst->rax].name, regst->rdi);
  printf("+++ exited with %lld +++\n", regst->rdi);
}
