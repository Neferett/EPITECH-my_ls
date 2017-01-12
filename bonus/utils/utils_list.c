/*
** utils_list.c for utils_list in /home/Neferett/PSU_2016_my_ls
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 28 11:50:30 2016 Bonaldi Jordan
** Last update Sun Dec  4 20:21:40 2016 Bonaldi Jordan
*/

#include "project.h"

t_list  *create()
{
  t_list        *c;

  if ((c = malloc(sizeof(*c)))
      && (c->n = c) && (c->p = c)) {}
  return (c);
}

void		my_put_first_in_list(t_list *list, struct dirent *d, char *path)
{
  struct group	*g;
  struct passwd	*p;
  struct stat	s;
  t_list        *e;

  if (!(e = malloc(sizeof(*e))))
    my_exit(errno, 73, "utils_list.c\0");
  if (stat(path, &s) == -1)
    return;
  if ((e->s = my_strdup(d->d_name)) && (e->c = get_type(s.st_mode))) {}
  e->r = get_rights(s);
  e->size = (int)s.st_size;
  if ((e->time_m = handle_time(ctime(&s.st_mtime), 'M')) &&
      (e->time_d = my_getnbr(handle_time(ctime(&s.st_mtime), 'd'))) &&
      (e->time_h = handle_time(ctime(&s.st_mtime), 'h')) &&
      (e->time_s = handle_time(ctime(&s.st_mtime), 'm')) &&
      (e->time_y = handle_time(ctime(&s.st_mtime), 'y')) &&
      (e->rtime = handle_spectime(ctime(&s.st_mtime)))) {}
  if (!(p = getpwuid(s.st_uid)) || !(g = getgrgid(s.st_gid)))
    my_exit(errno, 73, "utils_list.c\0");
  if ((e->uid = p->pw_name) && (e->gr = g->gr_name)
      && ((e->id = s.st_nlink) ? 1 : 1)) {}
  e->is_dir = get_type(s.st_mode) == 'd' ? true : false;
  if ((e->p = list) && (e->n = list->n) && (list->n->p = e) &&
      (list->n = e)) {}
}

void		my_put_fil(t_list     *list, char *path)
{
  struct group	*g;
  struct passwd	*p;
  struct stat	s;
  t_list        *e;

  if (!(e = malloc(sizeof(*e))))
    my_exit(errno, 73, "utils_list.c\0");
  if (stat(path, &s) == -1)
    return;
  if ((e->s = my_strdup(path)) && (e->c = get_type(s.st_mode))) {}
  e->r = get_rights(s);
  e->size = s.st_size;
  if ((e->time_m = handle_time(ctime(&s.st_mtime), 'M')) &&
      (e->time_d = my_getnbr(handle_time(ctime(&s.st_mtime), 'd'))) &&
      (e->time_h = handle_time(ctime(&s.st_mtime), 'h')) &&
      (e->time_s = handle_time(ctime(&s.st_mtime), 'm')) &&
      (e->time_y = handle_time(ctime(&s.st_mtime), 'y')) &&
      (e->rtime = handle_spectime(ctime(&s.st_mtime)))) {}
  if (!(p = getpwuid(s.st_uid)) || !(g = getgrgid(s.st_gid)))
    my_exit(errno, 73, "utils_list.c\0");
  if ((e->uid = p->pw_name) && (e->gr = g->gr_name)
      && ((e->id = s.st_nlink) ? 1 : 1)) {}
  e->is_dir = get_type(s.st_mode) == 'd' ? true : false;
  if ((e->p = list) && (e->n = list->n) && (list->n->p = e) &&
      (list->n = e)) {}
}

void		my_put_l(t_l_t_l     *list, t_list *l, char *path, int i)
{
  t_l_t_l        *e;

  if (!(e = malloc(sizeof(*e))))
    my_exit(errno, 73, "utils_list.c\0");
  e->l = l;
  e->file = *path + 48;
  ++path;
  e->i = i;
  e->s = path;
  e->p = list;
  e->n = list->n;
  list->n->p = e;
  list->n = e;
}
