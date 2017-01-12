/*
** project.h for project_header in /home/Neferett/bin/IMPORT/include
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Nov 21 01:13:04 2016 Bonaldi Jordan
** Last update Sun Dec  4 20:13:22 2016 Bonaldi Jordan
*/

#ifndef H_CHECK
#define H_CHECK

#define _DEFAULT_SOURCE

#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#include "lib.h"
#include "printf.h"

typedef	struct	s_flag
{
  Boolean	l;
  Boolean	R;
  Boolean	d;
  Boolean	r;
  Boolean	t;
  Boolean	help;
  char		*path;
}		t_flag;

typedef struct	s_list
{
  char		*s;
  char		c;
  char		*r;
  char		*time_m;
  int		time_d;
  char		*time_h;
  char		*time_s;
  char		*time_y;
  char		*rtime;
  int		size;
  int		id;
  char		*uid;
  char		*gr;
  Boolean	is_dir;
  struct s_list *p;
  struct s_list	*n;
}		t_list;

typedef	struct		s_l_t_l
{
  char			*s;
  int			i;
  t_list		*l;
  Boolean		file;
  struct s_l_t_l	*n;
  struct s_l_t_l	*p;
}			t_l_t_l;

Boolean		disp(char *, t_flag *, t_l_t_l *);
Boolean		wrong_flag(char, t_flag *);
Boolean		help_handler(t_flag *);
Boolean		free_flag(t_flag *);
Boolean		free_all(t_l_t_l *, t_flag *, char **);
Boolean		my_rev_list(t_list *);
int		set_dir_list(char *, t_list *, Boolean *);
void		set_dir_R(char *, t_flag *);
int		gms(t_list *);
int		gmu(t_list *);
int		get_max_s(t_list *);
t_flag		*handle_flag(int , char **);
t_list		*create();
t_l_t_l		*create_t_l_t();
char		get_type(int);
char		*get_rights(struct stat);
char		*handle_time(char *, char);
char		*handle_spectime(char *);
void		handle_error(int, char *);
void		disp_list(t_list	*, t_flag *);
void		my_put_first_in_list(t_list *, struct dirent *, char *);
void		my_put_l(t_l_t_l *, t_list *, char *, int i);
void		my_put_fil(t_list *, char *);
Boolean		ls_printer(t_l_t_l *, t_flag *, int);
Boolean		my_sort_list(t_list *);
Boolean		my_sort_list_time(t_list *);
Boolean		disp_list_rev(t_list *, t_flag *);
int		my_size_tab(char **);
void		printer_not_dir(t_list *, t_flag *);
void		my_exit(int, int, char *);

#endif
