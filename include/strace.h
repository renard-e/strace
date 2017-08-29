/*
** strace.h for  in /home/renard_e/poubelle_test/test_strace/include
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Apr  3 11:37:38 2017 Gregoire Renard
** Last update Sun Apr 16 16:20:38 2017 Rodrigue RENE
*/

#ifndef STRACE_H_
# define STRACE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <fcntl.h>

# define SUCCESS 0
# define ERROR -1
# define MAX_ARG 2
# define LEN 329

typedef struct	s_all
{
  int		s;
  int		e;
  int		dif;
  int		remp;
  int		i;
  int		dimen;
}		t_all;

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

typedef struct		s_my_syscall
{
  char			*name;
  int			number;
  char			**param;
  char			*ret;
}			t_my_syscall;

typedef struct		s_func
{
  
}			t_func;

typedef struct		s_arg
{
  int			on;
  char			*opt;
  char			*value;
}			t_arg;

typedef struct		s_info
{
  t_arg			arg[MAX_ARG];
  char			*executable;
  char			**exec_arg;
  char			**env;
  pid_t			child;
  pid_t			parent;
}			t_info;

typedef struct		s_getline
{
  size_t		size;
  char			*line;
  FILE			*file;
}			t_getline;

t_my_syscall		g_tab_syscall[LEN];

char			**my_str_to_word_tab(char *str);
void			free_map(char **map);
int			child_proccess(t_info *info);
int			child_pid(t_info *info);
int			father_proccess(t_info *info);
void			print_map(char **map);
int			printf_error(char *str);
int			fill_info(t_info *info, char **argv);
int			ident_flag(char *arg);
int			check_pid(t_info *info);
int			start_strace(t_info *info);
int			remp_exec_arg(t_info *info, char *arg);
int			init_syscall();
void			print_global();
void			print_ret(struct user_regs_struct *regst,
				  t_info *info);
void			print_int(struct user_regs_struct *regst,
				  t_info *info,
				  int cpt);
void			print_char(struct user_regs_struct *regst,
				   t_info *info,
				   int cpt);
void			print_long(struct user_regs_struct *regst,
				   t_info *info,
				   int cpt);
void			print_void(struct user_regs_struct *regst,
				   t_info *info,
				   int cpt);
void			print_struct(struct user_regs_struct *regst,
				     t_info *info,
				     int cpt);
void			end_print(struct user_regs_struct *regst,
				  t_info *info);

void			string_express(char *str);
#endif /* !STRACE_H_ */
