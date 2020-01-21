#include <lem_in.h>

t_edges		*current_vertex(t_edges *vert, t_edges *old)
{
	t_edges		*tmp;

	tmp = old->next;
	while (old && old->next)
	{
		if (vert->to == old->to)
			return (old);
		old = old->next;
	}
	return (NULL);
}

void		swap_tails(t_edges *new, t_edges *tail)
{
	t_edges		*new_rev;
	t_edges		*old_rev;
	t_edges		*new_for_del;
	// t_edges		*old_for_del;

	new_rev = new->prev;
	new->prev = NULL;
	new_for_del = new;

	new_rev->next = tail;
	old_rev = tail->prev;
	tail->prev->next = NULL;
	tail->prev = NULL;

	tail->prev->next = NULL;
	tail->prev = NULL;

	new->prev->next = tail;
	
}


void		swap_all_common_tails(t_ways *ways)
{
	t_edges		*new;
	t_edges		*tail;
	int			n;
	int			i;

	n = ways->num_of_ways - 1;
	new = ways->way[n]->next;
	tail = NULL;
	while (new->next)
	{
		i = 0;
		while (i < ways->num_of_ways)
		{
			if ((tail = current_vertex(new, ways->way[i])))
			{
				swap_tails(new, tail);
			}
			i++;
		}
		new = new->next;
	}
}
