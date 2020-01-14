#include <lem_in.h>

void		print_ways_struct(t_ways *way_struct)
{
	int			i;
	t_edges		*tmp;

	i = 0;
	printf("\n****||****||****|| PRINT WAY STRUCT ||****||****||****||***\n");
	printf("num_of_ways = %i\n", way_struct->num_of_ways);
	while (i < way_struct->num_of_ways)
	{
		printf("edge #%i    = ", i);
		tmp = way_struct->way[i];
		while (tmp)
		{
			printf(" %i,", tmp->to->key);
			tmp = tmp->next;
		}
		printf("\n");
	}
	printf("*****||****||****||****||****||****||****||****||****||****\n");
}

void		free_ways_struct(t_ways **old_struct)
{
	int		i;

	i = 0;
	if (old_struct && *old_struct)
	{
		while (i < (*old_struct)->num_of_ways)
			free_edges_struct(&(*old_struct)->way[i++]);
		free((*old_struct)->way);
		free(*old_struct);
		*old_struct = NULL;
	}
}

void		copy_ways_by_the_edges(t_ways *old, t_ways *new)
{
	int		i;

	i = 0;
	while (i < old->num_of_ways)
	{
		new->way[i] = copy_edges_struct(old->way[i]);
		i++;
	}
}

t_ways		*new_ways_struct(t_edges *new, t_ways *old_struct, int number)
{
	t_ways		*new_struct;

	if (!(new_struct = malloc(sizeof(t_ways))) ||
	!(new_struct->way = malloc(sizeof(t_edges) * number)))
		exit(1);
	new_struct->num_of_ways = number;
	new_struct->way[number - 1] = new;
	if (number > 1)
		copy_ways_by_the_edges(old_struct, new_struct);
	// upgrade_ways(new_struct, graph);
	return (new_struct);
}