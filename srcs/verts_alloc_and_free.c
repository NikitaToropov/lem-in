#include <lem_in.h>

void		ft_free_vert_sruct(t_vert **first)
{
	t_vert		*tmp;

	while (*first)
	{
		tmp = *first;
		*first = (*first)->next;
		if (tmp->name)
			free(tmp->name);
		free(tmp);
	}
	first = NULL;
}

t_vert		*ft_make_vert(int number, char *name, int x_cord, int y_cord)
{
	t_vert		*vert;

	if (!(vert = malloc(sizeof(t_vert))))
		exit(1);
	vert->num = number;
	vert->name = name;
	vert->x = x_cord;
	vert->y = y_cord;
	vert->indicator = 0;
	vert->next = NULL;
	return (vert);
}