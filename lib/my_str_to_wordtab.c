/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/Neferett/CPool_Day08/task04
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Wed Oct 12 10:53:16 2016 Bonaldi Jordan
** Last update Sun Dec  4 15:52:47 2016 Bonaldi Jordan
*/

#include "project.h"

Boolean	char_isnum(char);
char	**tab_complete(char **, char *, char, int *);

char	**my_str_to_wordtab(char *str, char c)
{
  char	**tab;
  int	j;

  j = -1;
  if (!(tab = malloc(sizeof(char *) * (my_strlen(str) * 10))))
    my_exit(errno, 23, "my_str_to_wordtab.c\0");
  if ((tab = tab_complete(tab, str, c, &j)) && (tab[++j] = NULL)) {}
  return (tab);
}

char	**tab_complete(char **tab, char *str, char c, int *j)
{
  int	i;
  char	*arr;

  arr = malloc(my_strlen(str) + 1);
  while (*str && !(i = 0) && (!++(*j) ? 1 : 1))
    {
      while (*str == c && (++str));
      while (*str != c && *str)
	if ((arr[i] = *str) && (++str) && ++i) {}
      if (arr && !(arr[i] = 0) && (tab[*j] = my_strdup(arr)))
	while (*++arr);
    }
  return (tab);
}

Boolean		char_isnum(char c)
{
  return ((c >= 'a' && c <= 'z') ||
	  (c >= 'A' && c <= 'Z') ||
	  (c >= '0' && c <= '9') || c == '.'
	  || c == '/' || c == '_' || c == '~' || c == '#');
}
