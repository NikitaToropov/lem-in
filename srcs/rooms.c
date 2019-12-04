#include <lem_in.h>

void		ft_free_rooms(t_vert **first)
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

t_vert		*ft_make_room(char *name, int x, int y, char mark)
{
	t_vert		*vert;

	if (!(vert = malloc(sizeof(t_vert))))
		exit(1);
	vert->name = name;
	vert->x = x;
	vert->y = y;
	vert->marker = mark;
	vert->next = NULL;
	return (vert);
}

void		ft_push_room_back(t_vert **first, t_vert *room)
{
	if (*first)
	{
		if ((*first)->next)
			ft_push_room_back(&(*first)->next, room);
		else
			(*first)->next = room;
	}
	else
		*first = room;
}