#include <lem_in.h>


void		loop_check(t_edges *way)
{
	t_edges		*edge1;
	t_edges		*edge2;

	edge1 = way;
	while (edge1->next)
	{
		edge2 = edge1->next;
		while (edge2)
		{
			if (edge2->to == edge1->to)
			{
				print_edges_struct(way);
				print_edges_struct(edge1);

				printf("LOOOOOOOP");
				exit(1);
			}
			edge2 = edge2->next;
		}
		edge1 = edge1->next;
	}
}

void		common_vertex(t_edges *first, t_edges *second)
{
	t_edges		*f;
	t_edges		*s;

	f = first->next;
	while (f->next)
	{
		s = second->next;
		while (s->next)
		{
			if (f->to->key == s->to->key)
			{
				print_edges_struct(first);
				print_edges_struct(second);
				printf("COMMON VERTEX");
				exit(1);
			}
			s = s->next;
		}
		f = f->next;
	}
}


void		check_valid(t_ways *ways)
{
	int		i = 0;
	int		n = 0;

	while (i < ways->num_of_ways)
	{
		loop_check(ways->way[i]);
		n = 0;
		while (i != n && n < ways->num_of_ways)
		{
			printf("\n\nn = %i, i = %i\n\n", n, i);
			common_vertex(ways->way[i], ways->way[n]);
			n++;
		}
		i++;
	}
}

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
			printf(" %i", tmp->to->key);
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

	if (old_ways && *old_ways)
	{
		i = 0;
		while (i < (*old_ways)->num_of_ways)
		{
			free_edges_struct(&(*old_ways)->way[i]);
			i++;
		}
		free((*old_ways)->way);
		(*old_ways)->way = NULL;
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


	new_ways = ft_memalloc(sizeof(t_ways));
	new_ways->way = ft_memalloc(sizeof(t_edges) * number);
	new_ways->num_of_ways = number;
	new_ways->way[number - 1] = new;

	if (number > 1)
	{
		copy_ways_by_the_edges(old_ways, new_ways);
		swap_all_common_tails(new_ways);
		// check_valid(new_ways);
	}
	return (new_ways);
}
