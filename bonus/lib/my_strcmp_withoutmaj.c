/*
** my_strcmp.c for my_strcmp in /home/Neferett/CPool_Day06
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Oct 10 10:25:18 2016 Bonaldi Jordan
** Last update Wed Nov 30 12:29:14 2016 Bonaldi Jordan
*/

#include "lib.h"

int	replace_maj(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    if ((str[i] >= 'A' && str[i] <= 'Z') && (str[i] += 32)) {}
  return (1);
}

int	my_strcmp_withoutmaj(char *s1, char *s2)
{
  char	*s1_s;
  char	*s2_s;
  int	i;

  i = 0;
  s1_s = my_strdup(s1);
  s2_s = my_strdup(s2);
  replace_maj(s1_s);
  replace_maj(s2_s);
  while (s1_s[i] == s2_s[i] && s1_s[i] && s2_s[i] && ++i);
  i = s1_s[i] - s2_s[i];
  free(s1_s);
  free(s2_s);
  return (i);
}
