#include <lem_in.h>

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

void		upgrade_ways(t_ways *new_ways, t_ways *old_ways)
{}
