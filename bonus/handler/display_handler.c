/*
** display_handler.c for display_handler in /home/Neferett/PSU_2016_my_ls
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 28 15:55:14 2016 Bonaldi Jordan
** Last update Sun Dec  4 15:42:21 2016 Bonaldi Jordan
*/

#include "project.h"

Boolean		set_file(char *path, t_list *l, unsigned int *a)
{
  DIR		*dir;
  struct stat	s;

  if (!(dir = opendir(path)))
    if (errno == 20)
      {
	stat(path, &s);
	if (*path != '.' && (*a += s.st_blocks)) {}
	my_put_fil(l, path);
	return (true);
      }
  return (false);
}

int		set_dir_list(char *path, t_list *l, Boolean *checked)
{
  char		*arr;
  unsigned int	a;
  DIR		*dir;
  struct dirent	*d;
  struct stat	s;

  if (!(a = 0) && !(arr = malloc(my_strlen(path) + 1)))
    my_exit(errno, 39, "display_handler.c\0");
  if (!(*checked = set_file(path, l, &a)) && !(dir = opendir(path)))
    handle_error(errno, path);
  else if (!*checked)
    while ((d = readdir(dir)))
      {
	my_strcpy(arr, path);
	if ((arr = my_strcat(arr, "/\0")) && (arr = my_strcat(arr, d->d_name))) {}
	stat(arr, &s);
	if (*(d->d_name) != '.')
	  a += s.st_blocks;
	my_put_first_in_list(l, d, arr);
      }
  free(arr);
  if (!*checked)
    closedir(dir);
  return (a);
}

Boolean		print_dir(char *path, t_flag *flag)
{
  t_l_t_l	*l;

  if (!(l = malloc(sizeof(*l))))
    my_exit(errno, 64, "display_handler.c\0");
  l = create_t_l_t();
  disp(path, flag, l);
  ls_printer(l, flag, 1);
  return (true);
}

void		set_dir_R(char *path, t_flag *flag)
{
  struct dirent	*d;
  DIR		*dir;
  DIR		*d2;
  char		*nd;
  char		*cp;

  cp = my_strdup(path);
  if (!(nd = malloc(my_strlen(path))))
    my_exit(errno, 81, "display_handler.c\0");
  my_printf("%s:\n", path);
  print_dir(path, flag);
  if (!(dir = opendir(path)))
    return;
  while ((d = readdir(dir)))
    if (my_strncmp(d->d_name, ".", 1) && d->d_type == 4)
      {
	if (path[my_strlen(path) - 1] != '/' && (nd = my_strcat(cp, "/\0"))) {}
	nd = my_strcat(path[my_strlen(path) - 1] != '/' ? nd : cp, d->d_name);
	if ((d2 = opendir(nd)) && (my_printf("\n")))
	  closedir(d2);
	set_dir_R(nd, flag);
	cp = my_strdup(path);
      }
  closedir(dir);
}
