/*
** my_strcat.c for my_strcat in /home/Neferett/CPool_Day07/lib/my
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Tue Oct 11 09:26:17 2016 Bonaldi Jordan
** Last update Sun Nov 27 21:14:12 2016 Bonaldi Jordan
*/

#include "lib.h"

char	*my_strcat(char *dest, char *src)
{
  char	*arr;
  int	i;
  int	length;

  i = 0;
  if (!(arr = malloc(my_strlen(dest) + my_strlen(src) + 1)))
    return (NULL);
  my_strcpy(arr, dest);
  length = my_strlen(dest);
  while (src[i])
    {
      arr[length + i] = src[i];
      i += 1;
    }
  arr[length + i] = '\0';
  free(dest);
  return (arr);
}
