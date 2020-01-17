#include <lem_in.h>

static int	add_dst_new_tail(t_edges *destination, t_edges *source)
{
	t_edges		*dst;
	t_edges		*src;
	t_edges		*tmp;

	dst = destination;
	while (dst && dst->next && dst->next)
	{
		src = source;
		while (src && src->next && src->next->next)
		{
			if (src->next->to == dst->next->to)
			{
				tmp = src->next;
				src->next = dst->next;
				dst->next = tmp;
				return (1);
			}
			src = src->next;
		}
		dst = dst->next;
	}
	return (0);
}

static void		remove_duplicats(t_edges *source)
{
	t_edges		*first;
	t_edges		*second;
	t_edges		*tmp;

	first = source;
	while (first && first->next && first->next->next)
	{
		second = first->next;
		while (second && second->next)
		{
			if (first->next->to == second->next->to)
			{
				tmp = first->next;
				first->next = second->next;
				second->next = NULL;
				free_edges_struct(&tmp);
				return ;
			}
			second = second->next;
		}
		first = first->next;
	}
}


int			swap_tails(t_edges *destination, t_edges *source)
{
	if (add_dst_new_tail(destination, source))
	{
		remove_duplicats(source);
		return (1);
	}
	return (0);
}

void		clean_the_way(t_edges *way)
{
	t_edges		*current;

	current = way;
	while (current && current->next)
	{
		if (current->next->to->key % 2)
		{
			if ((current->to->key + 1) == current->next->to->key &&
			current->next->next)
				pull_edge(&way, current->next->to);
			else
				current->next->to = current->next->to->edge->to;
		}
		current = current->next;
	}
}

void		upgrade_ways(t_ways *ways)
{
	int		i;
	int		j;

	clean_the_way(ways->way[ways->num_of_ways - 1]);
	i = ways->num_of_ways - 1;

	while (i >= 0)
	{

		j = ways->num_of_ways - 1;
		while (j >= 0)
		{
		// printf("\n\n\nTHIS SHIT\n\n\n\n");
			if (j != i && swap_tails(ways->way[i], ways->way[j]))
			{




				
				print_edges_struct(ways->way[i]);
				print_edges_struct(ways->way[j]);
				printf("\n\n");
				j = ways->num_of_ways - 1;
			}
			else
				j--;
		}
		i--;
	}
}