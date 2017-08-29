/*
** print_void.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_strace/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Apr 13 18:57:44 2017 Gregoire Renard
** Last update Sun Apr 16 17:15:06 2017 Gregoire Renard
*/

#include "strace.h"

static void		print_nb(long long nb, int indic, int ptr)
{
  if (indic == -1)
    {
      if (ptr == 1)
	printf("0x%lld", nb);
      else
	printf("0x%llx", nb);
    }
  else
    {
      if (ptr == 1)
	{
	  if (nb == 0)
	    printf("NULL");
	  else
	    printf("%p", (void *)nb);
	}
      else
	printf("%lld", nb);
    }
}

void			print_void(struct user_regs_struct *regst,
				   t_info *info,
				   int cpt)
{
  int			ptr;

  ptr = 0;
  if ((strstr(g_tab_syscall[regst->orig_rax].param[cpt],
	      "1")) != NULL)
    ptr = 1;
  if (cpt == 0)
    print_nb(regst->rdi, info->arg[1].on, ptr);
  if (cpt == 1)
    print_nb(regst->rsi, info->arg[1].on, ptr);
  if (cpt == 2)
    print_nb(regst->rdx, info->arg[1].on, ptr);
  if (cpt == 3)
    print_nb(regst->r10, info->arg[1].on, ptr);
  if (cpt == 4)
    print_nb(regst->r8, info->arg[1].on, ptr);
  if (cpt == 5)
    print_nb(regst->r9, info->arg[1].on, ptr);
}
