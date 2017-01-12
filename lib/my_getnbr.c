/*
** my_getnbr.c for my_getnbr in /home/Neferett/CPool_Day04
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Thu Oct  6 11:42:14 2016 Bonaldi Jordan
** Last update Thu Dec  1 12:13:41 2016 Bonaldi Jordan
*/

#include <stdlib.h>
#include "lib.h"

char	get_operator(char *str);
int	get_nb(char *str);

int	my_getnbr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  if (get_operator(str) == '-')
    {
      while (str[i] == '-')
	str = str + 1;
      return (- (get_nb(str)));
    }
  else if (get_operator(str) == '+')
    {
      while (str[i] == '+')
	str = str + 1;
      return (get_nb(str));
    }
  else
    return (get_nb(str));
}

char	get_operator(char *str)
{
  char	operator;
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '-')
	{
	  operator = '-';
	  my_getnbr(str + 1);
	}
      else if (str[i] == '+')
	{
	  my_getnbr(str + 1);
	}
      i += 1;
    }
  return operator == '-' ? '-' : '+';
}

int	get_nb(char *str)
{
  int	i;
  int	value;

  i = 0;
  value = 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      value = (value * 10) + str[i] - 48;
      i += 1;
    }
  return value;
}
