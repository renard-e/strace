/*
** print_char2.c for strace in /home/rodrigue.rene/Cours/Semestre_4/System_Unix/PSU_2016_strace/src
**
** Made by Rodrigue RENE
** Login   <rodrigue.rene@epitech.net>
**
** Started on  Sun Apr 16 16:06:31 2017 Rodrigue RENE
** Last update Sun Apr 16 18:26:27 2017 Rodrigue René
*/

#include "strace.h"

static int			isprintable(int c)
{
  if ((c > 127) || (c < 7) || (c < 32  && c > 13))
    return (0);
  return (1);
}

static void	elfstring(char c)
{
  if (c == 0)
    printf("\\0");
  else if (c == '\b')
    printf("\\b");
  else if (c == '\a')
    printf("\\a");
  else if (c == '\t')
    printf("\\t");
  else if (c == '\n')
    printf("\\n");
  else if (c == '\v')
    printf("\\v");
  else if (c == '\f')
    printf("\\f");
  else if (c == '\r')
    printf("\\r");
  else if (!isprintable(c))
    printf("\\%d", c);
  else
    printf("%c", c);
}

void	string_express(char *str)
{
  int	i;

  i = 0;
  printf("\"");
  while (str[i] > 0)
    {
      elfstring(str[i]);
      i++;
    }
  if (i > 0)
    printf("\\0");
  printf("\"");
}
