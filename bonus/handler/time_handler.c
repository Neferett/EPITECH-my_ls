/*
** handle_time.c for handle_time in /home/Neferett/PSU_2016_my_ls
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Nov 28 22:03:06 2016 Bonaldi Jordan
** Last update Sun Dec  4 20:24:06 2016 Bonaldi Jordan
*/

#include "project.h"

char	*get_mounts(char *str)
{
  if (!my_strcmp(str, "Jan\0"))
    return (my_strdup("0\0"));
  if (!my_strcmp(str, "Feb\0"))
    return (my_strdup("1\0"));
  if (!my_strcmp(str, "Mar\0"))
    return (my_strdup("2\0"));
  if (!my_strcmp(str, "Apr\0"))
    return (my_strdup("3\0"));
  if (!my_strcmp(str, "May\0"))
    return (my_strdup("4\0"));
  if (!my_strcmp(str, "Jun\0"))
    return (my_strdup("5\0"));
  if (!my_strcmp(str, "Jul\0"))
    return (my_strdup("6\0"));
  if (!my_strcmp(str, "Aug\0"))
    return (my_strdup("7\0"));
  if (!my_strcmp(str, "Sep\0"))
    return (my_strdup("8\0"));
  if (!my_strcmp(str, "Oct\0"))
    return (my_strdup("9\0"));
  if (!my_strcmp(str, "Nov\0"))
    return (my_strdup("10\0"));
  if (!my_strcmp(str, "Dec\0"))
    return (my_strdup("11\0"));
  return (NULL);
}

void	change_str(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    if (str[i] == ':' && (str[i] = ' ')) {}
}

char	*handle_spectime(char *time)
{
  char	*arr;
  char	*str;
  char	**tab;

  if (!(arr = malloc(my_strlen(time))))
    my_exit(errno, 29, "time_handler.c\0");
  if (!(str = malloc(my_strlen(time))))
    my_exit(errno, 31, "time_handler.c\0");
  my_strcpy(str, time);
  change_str(str);
  *arr = 0;
  tab = my_str_to_wordtab(str, ' ');
  arr = my_strcat(arr, get_mounts(tab[1]));
  arr = my_strcat(arr, tab[2]);
  arr = my_strcat(arr, tab[3]);
  arr = my_strcat(arr, tab[4]);
  arr = my_strcat(arr, tab[5]);
  free(tab);
  free(str);
  return (arr);
}

char	*handle_time(char *time, char c)
{
  char	*str;
  char	**tab;

  if (!(str = malloc(my_strlen(time))))
    my_exit(errno, 45, "time_handler.c\0");
  my_strcpy(str, time);
  change_str(str);
  tab = my_str_to_wordtab(str, ' ');
  return (c == 'M' ? tab[1] : c == 'd' ?
	  tab[2] : c == 'h' ? tab[3] : c == 'm' ? tab[4] :
	  !(tab[6][my_strlen(tab[6]) - 1] = 0) ? tab[6] : tab[6]);
  free(tab);
  free(str);
  return (time);
}
