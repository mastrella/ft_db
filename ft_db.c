#include "ft_db.h"

t_entry	*new_entry(char* id, char *name, char *age)
{
	t_entry	*new;

	if (!(new = (t_entry*)malloc(sizeof(t_entry))))
		return (NULL);
	if (!id || !name || !age)
	{
    new->id = NULL;
		new->name = NULL;
		new->age = NULL;
	}
	else
	{
    new->id = ft_memalloc(256);
		new->id = ft_memcpy(new->id, id, 256);
		new->name = ft_memalloc(256);
		new->name = ft_memcpy(new->name, name, 256);
		new->age = ft_memalloc(256);
		new->age = ft_memcpy(new->age, age, 256);
	}
	new->next = NULL;
	return (new);
}

void	add_entry(t_entry **alst, t_entry *new)
{
	t_entry	*tmp;

	if (*alst)
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*alst = new;
}

void	remove_entry(t_entry **begin_list, void *id)
{
	t_entry	*tmp;
	t_entry	*i;

	while (*begin_list && strcmp(((*begin_list)->id), id) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	i = *begin_list;
	while (i && i->next)
	{
		if (strcmp((i->next->id), id) == 0)
		{
			tmp = i->next;
			i->next = tmp->next;
			free(tmp);
		}
		if (i->next)
		{
			i = i->next;
		}
	}
}


int ft_db(char **argv)
{
  char				command[5];
  char        content[256];
  char				name[256];
  char        age[256];
  char        id[256];
  t_entry      *first_entry;
  t_entry      *new;
  t_entry      *tmp;
  FILE         *file;
  // int          fe_check;

  // fe_check = 1;
  first_entry = NULL;
  printf("Please enter the pathname of the existing database you'd like to import.\n"
  "If you don't have one just press ENTER to create your first entry.\n\n");
  bzero(content, 256);
  fgets(content, 256, stdin);
  if (strcmp(content, "\n") == 0)
  {
    printf("Create a new entry:\n");
    ft_memcpy(id, "0", 256);
    printf("Name : ");
    bzero(name, 255);
    fgets(name, 255, stdin);
    if(name[strlen(name) - 1] == '\n')
      name[strlen(name) - 1] = '\0';
    printf("Age  : ");
    bzero(age, 255);
    fgets(age, 255, stdin);
    if(age[strlen(age) - 1] == '\n')
      age[strlen(age) - 1] = '\0';
    first_entry = new_entry(id, name, age);
  }
  // else //probably need to use new_entry and add_entry (as seen in '-c')
  // {
  //   file = fopen (content,"r");
  //   while (gnl == 1)
  //   {
  //     tmp = first_entry;
  //     if (gnl == 1)
  //       id = line    //next line from file (line in gnl);
  //     if (gnl == 1)
  //       name = line  //next line from file (line in gnl);
  //     if (gnl == 1)
  //       age = line   //next line from file (line in gnl);
  //     if (fe_check == 1)
  //     {
  //       first_entry = new_entry(id, name, age);
  //       fe_check = 0;
  //     }
  //     else
  //     {
  //       new = new_entry(id, name, age);
  //       add_entry(&tmp, new);
  //     }
  //     if (!(tmp->next))
  //       break;
  //     tmp = tmp->next;
  //   }
  //   fclose (file);
  // }

  while (1)
  {
    tmp = first_entry;

    printf ("Commands for Program: (%s)\n"
    "-e  EXIT PROGRAM.\n"
    "-c  Create new entry.\n"
    "-u  Update (edit) entry.\n"
    "-d  Delete entry.\n"
    "-s  Save current database to file.\n"
    "-p  Print current database.\n"
    "-pn  Print all entries sorted by name.\n"
    "-pa  Print all entries sorted by age.\n"
    "\nPlease enter one of the commands above...  (to exit type '-e')\n\n", argv[0]);
    bzero(command, 5);
    fgets(command, 5, stdin);

    if (strcmp(command, "-e\n") == 0)
      return(0);
    else if (strcmp(command, "-c\n") == 0)
    {
      printf("Create a new entry:\n");
      while (tmp->next)
        tmp = tmp->next;
      ft_memcpy(id, ft_itoa(atoi((tmp->id)) + 1), 256);
      printf("Name : ");
      bzero(name, 255);
      fgets(name, 255, stdin);
      if(name[strlen(name) - 1] == '\n')
        name[strlen(name) - 1] = '\0';
      printf("Age  : ");
      bzero(age, 255);
      fgets(age, 255, stdin);
      if(age[strlen(age) - 1] == '\n')
        age[strlen(age) - 1] = '\0';
      new = new_entry(id, name, age);
      add_entry(&tmp, new);
    }
    else if (strcmp(command, "-p\n") == 0)
    {
      printf("Printing current database..\n");
      printf("|   ID   |         NAME         |  AGE  |\n");
      printf("-------------------------------------------\n");
      while (tmp)
      {
        printf("|  %4s  | %20s |  %3s  |\n", tmp->id, tmp->name, tmp->age);
        if (!(tmp->next))
        	break;
        tmp = tmp->next;
      }
    }
    else if (strcmp(command, "-d\n") == 0)
    {
      printf("Which element ID would you like to remove?\n");
      bzero(id, 255);
      fgets(id, 255, stdin);
      if(id[strlen(id) - 1] == '\n')
        id[strlen(id) - 1] = '\0';
      remove_entry(&tmp, &id);
    }
    else if (strcmp(command, "-s\n") == 0)
    {
      file = fopen ("mydb.txt","w");
      while (tmp)
      {
        fprintf(file, "\n");
        fprintf(file, "%s\n", tmp->id);
        fprintf(file, "%s\n", tmp->name);
        fprintf(file, "%s\n", tmp->age);
        if (!(tmp->next))
          break;
        tmp = tmp->next;
      }
      fclose (file);
    }
  }
  return (1);
}

int main(int argc, char **argv)
{
  if (argc > 0)
    ft_db(argv);
  return (0);
}
