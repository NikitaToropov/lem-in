#include <lem_in.h>

void		ft_free_rooms(t_verts **first)
{
	t_verts		*tmp;

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

t_verts		*ft_make_room(char *name, int x, int y, char mark)
{
	t_verts		*vert;

	if (!(vert = malloc(sizeof(t_verts))))
		exit(1);
	vert->num = 0;
	vert->name = name;
	vert->x = x;
	vert->y = y;
	vert->marker = mark;
	vert->next = NULL;
	return (vert);
}

void		ft_push_room_back(t_verts **first, t_verts *room)
{
	t_verts			*tmp;


	if (*first)
	{
		tmp = *first;
		while (tmp->next)
			tmp = tmp->next;
		room->num = tmp->num + 1;
		tmp->next = room;
	}
	else
		*first = room;
}