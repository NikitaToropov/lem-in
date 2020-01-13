#include <lem_in.h>

void	free_t_match(t_match **rooms)
{
	if (!*rooms)
		return ;
	if ((*rooms)->next)
		free_t_match(&((*rooms)->next));
	free (*rooms);
	*rooms = NULL;
}

int		number_and_name_match(t_match *rooms, char *name)
{
	t_match		*tmp;

	tmp = rooms;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name_of_room, name))
			return (tmp->number_of_room);
		tmp = tmp->next;
	}
	return (-1);
}

void		push_back_t_match(t_match **room, char *name, int num_room)
{
	t_match		*new;
	t_match		*tmp;

	if (!(new = malloc(sizeof(t_match))))
		exit(1);
	new->name_of_room = name;
	new->number_of_room = num_room;
	new->next = NULL;
	if (*room == NULL)
		*room = new;
	else
	{
		tmp = *room;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
