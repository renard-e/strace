/*
** print_struct.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_strace/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Apr 13 18:58:16 2017 Gregoire Renard
** Last update Sun Apr 16 12:57:00 2017 Gregoire Renard
*/

#include "strace.h"

static void		print_nb(long long int nb,
				 int ptr)
{
  if (ptr == 1)
    printf("%p", (void *)nb);
  else
    printf("0x%llx", nb);
}

void			print_struct(struct user_regs_struct *regst,
				     t_info *info,
				     int cpt)
{
  int			ptr;

  (void)info;
  ptr = 0;
  if ((strstr(g_tab_syscall[regst->orig_rax].param[cpt], "1"))
      != NULL)
    ptr = 1;
  if (cpt == 0)
    print_nb(regst->rdi, ptr);
  if (cpt == 1)
    print_nb(regst->rsi, ptr);
  if (cpt == 2)
    print_nb(regst->rdx, ptr);
  if (cpt == 3)
    print_nb(regst->r10, ptr);
  if (cpt == 4)
    print_nb(regst->r8, ptr);
  if (cpt == 5)
    print_nb(regst->r9, ptr);
}
