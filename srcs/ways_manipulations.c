#include <lem_in.h>

int			swap_tails(t_edges *first , t_edges *second)
{
	t_edges		*one;
	t_edges		*two;
	t_edges		*tmp_one;
	t_edges		*tmp_two;

	one = first;
	two = second;
	tmp_one = NULL;
	tmp_two = NULL;
	while (one && one->next && one->next->next)
	{

		while (two && two->next && two->next->next)
		{
	printf("\n\n\nTHIS SHIT\n\n\n\n");
			if (one->next->to == two->next->to)
			{
				if (!tmp_one)
					tmp_one = one->next;
				else
					tmp_two = one->next;
				one->next = two->next;
				two->next = NULL;
				one = second;
				if (tmp_two)
				{
					free_edges_struct(&tmp_one);
					free_edges_struct(&tmp_two);
					return (1);
				}
				two = tmp_one;
				continue ;
			}
			two = two->next;
		}
		one = second;
		one = one->next;
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
			if (j != i && swap_tails(ways->way[i], ways->way[j]))
				j = ways->num_of_ways - 1;
			else
				j--;
		}
		i--;
	}
}