/*
** main.c for main in /home/Neferett/bin/IMPORT
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 14 14:04:13 2016 Bonaldi Jordan
** Last update Sun Dec  4 15:39:30 2016 Bonaldi Jordan
*/

#include "project.h"

int	main(int argc, char **argv)
{
  int		size;
  char		**tab;
  t_flag	*flag;
  t_l_t_l	*l;

  if (!(l = malloc(sizeof(*l))))
    my_exit(errno, 21, "main.c\0");
  l = create_t_l_t();
  flag = handle_flag(argc, argv);
  if (flag->help && help_handler(flag)) {}
  tab = my_str_to_wordtab(flag->path, ' ');
  my_sort_wordtab(tab);
  size = my_size_tab(tab);
  while (*tab)
    {
      if (flag->d && my_printf(*tab)) {}
      else if (flag->R)
	set_dir_R(*tab, flag);
      else
	disp(*tab, flag, l);
      if (flag->d && my_printf("\n")) {}
      tab++;
    }
  if (!flag->R && ls_printer(l, flag, size)) {}
  return (0);
}
