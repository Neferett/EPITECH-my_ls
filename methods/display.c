/*
** display.c for display in /home/Neferett/PSU_2016_my_ls
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Tue Nov 22 18:03:38 2016 Bonaldi Jordan
** Last update Sun Dec  4 14:21:07 2016 Bonaldi Jordan
*/

#include "project.h"

Boolean		disp(char *path, t_flag	*flag, t_l_t_l *li)
{
  char		*arr;
  Boolean	checked;
  int		a;
  t_list	*l;

  if (!(arr = malloc(my_strlen(path) + 1)))
    my_exit(errno, 21, "display.c\0");
  checked = true;
  if (!(l = malloc(sizeof(t_list))))
    handle_error(errno, path);
  l = create();
  a = set_dir_list(path, l, &checked);
  if (flag->t && my_sort_list_time(l)) {}
  else if (my_sort_list(l)) {}
  arr = my_strcat(checked ? my_strdup("1\0") : my_strdup("2\0"), path);
  my_put_l(li, l, arr, (a / 2));
  return (true);
}
