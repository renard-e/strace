/*
** print_char.c for  in /home/renard_e/2/systeme_unix_instrumentation/PSU_2016_strace/src
**
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
**
** Started on  Thu Apr 13 18:55:49 2017 Gregoire Renard
** Last update Wed Apr 19 13:44:01 2017 Gregoire Renard
*/

#include "strace.h"

static void		associate(struct user_regs_struct *regst,
				  int cpt,
				  unsigned long long int *ulli)
{
  if (cpt == 0)
    *ulli = regst->rdi;
  else if (cpt == 1)
    *ulli = regst->rsi;
  else if (cpt == 2)
    (*ulli) = regst->rdx;
  else if (cpt == 3)
    (*ulli) = regst->r10;
  else if (cpt == 4)
    (*ulli) = regst->r8;
  else if (cpt == 5)
    (*ulli) = regst->r9;
}

static void	char_star(t_info *info,
			  unsigned long long int ulli)
{
  char		msg[1024];
  char		*temp_char2;
  int		j;
  long		temp_long;

  j = 0;
  temp_char2 = msg;
  while (j < 100)
    {
      temp_long = ptrace(PTRACE_PEEKDATA, info->child, ulli + (j * 8), NULL);
      memcpy(temp_char2, &temp_long, 8);
      temp_char2 += sizeof(long);
      ++j;
    }
  msg[j] = '\0';
  string_express(msg);
}

void			print_char(struct user_regs_struct *regst,
				   t_info *info,
				   int cpt)
{
  unsigned long long int ulli;

  (void)info;
  associate(regst, cpt, &ulli);
  if (info->arg[1].on == -1)
    printf("0x%llx", ulli);
  else
    {
      if (g_tab_syscall[regst->orig_rax].param[cpt][4] == 0)
  	printf("%c", (char)ulli);
      else if (g_tab_syscall[regst->orig_rax].param[cpt][4] == '1')
	char_star(info, ulli);
      else if (g_tab_syscall[regst->orig_rax].param[cpt][4] == '2')
	{
	  printf("[");
	  char_star(info, ulli);
	  printf("]");
	}
    }
}
