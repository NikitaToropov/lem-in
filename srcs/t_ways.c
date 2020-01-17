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
			// printf(" %s,", tmp->to->name);
			printf(" %i,", tmp->to->key);
			tmp = tmp->next;
		}
		printf("\n");
		i++;
	}
	printf("*****||****||****||****||****||****||****||****||****||****\n");
}

void		free_ways_struct(t_ways **old_ways)
{
	int		i;

	i = 0;
	if (old_ways && *old_ways)
	{
		while (i < (*old_ways)->num_of_ways)
		{
			free_edges_struct(&(*old_ways)->way[i++]);

		}
		free((*old_ways)->way);
		free(*old_ways);
		*old_ways = NULL;
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

t_ways		*new_ways_struct(t_edges *new, t_ways *old_ways, int number)
{
	t_ways		*new_ways;


	if (!(new_ways = malloc(sizeof(t_ways))) ||
	!(new_ways->way = malloc(sizeof(t_edges) * number)))
		exit(1);
		
	new_ways->num_of_ways = number;
	new_ways->way[number - 1] = new;
	if (number > 1)
	{
		copy_ways_by_the_edges(old_ways, new_ways);

		upgrade_ways(new_ways);
	}
	// print_ways_struct(new_ways);
	return (new_ways);
}
