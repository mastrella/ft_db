#ifndef FT_DB_H
# define FT_DB_H

#include <stdio.h>   //printf, fgets
#include <strings.h>  //bzero
#include <string.h>  //strcmp
#include <stdlib.h> //atoi, itoa

typedef struct      s_entry
{
  char    *id;
  char    *name;
  char    *age;
  struct s_entry *next;
}           t_entry;

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_itoa(int n);
char				*ft_strnew(size_t size);

#endif


// make databse
// - validate data
// - insert elements (rows?/columns?fields?)
// - sort/update elements
// - show/retrieve/select elements
// - remove elements
// - (FUTURE - save list to document)
// - (FUTURE - retreive list from document)
//
// element (Row)
// - Column 0 = Element ID
// - Column 1 =
// - Column 2 =
// - Column 3 =
//
// Example interface-commands:
// - SHOW
// - ADD (ID/NEW) (COLUMN NAME) (DATA)
// - REMOVE (ID)
// - SORT (COLUMN NAME) BY (!!STILL TO DECIDE!!)
// - EXIT
