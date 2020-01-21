#include <lem_in.h>

t_edges		*cut_there_before(t_edges *vertex)
{
	if (vertex && vertex->prev)
	{
		vertex->prev->next = NULL;
		vertex->prev = NULL;
	}
	return (vertex);
}

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
	t_edges		*new_for_insert;
	t_edges		*old_for_insert;
	t_edges		*new_tmp;
	t_edges		*old_rev;
	// t_edges		*new_for_del;
	// t_edges		*old_for_del;


	old_rev = tail->prev;
	cut_there_before(tail);

	new_for_insert = new->prev;
	cut_there_before(new);
	new_tmp = new->next;
	push_edge_back(&new_for_insert, tail);

	while (old_rev->prev && old_rev->prev->prev && 
	new_tmp->next && new_tmp->next->next &&
	new_tmp->next->to == old_rev->prev->to)
	{
		new_tmp = new_tmp->next;
		old_rev = old_rev->prev;
	}
	// print_edges_struct(old_rev);
	// print_edges_struct_reverse(old_rev);
	// print_edges_struct(new_tmp);

	old_for_insert = old_rev->prev;
	cut_there_before(new_tmp);
	cut_there_before(old_rev);
	push_edge_back(&old_for_insert, new_tmp);
	free_edges_struct(&new);
	free_edges_struct(&old_rev);
}


void		swap_all_common_tails(t_ways *ways)
{
	t_edges		*new;
	t_edges		*tail;
	int			n;
	int			i;

	print_ways_struct(ways);
	n = ways->num_of_ways - 1;
	new = ways->way[n]->next;
				// print_edges_struct(new);
				// print_edges_struct(ways->way[n]);
	tail = NULL;
	while (new->next)
	{
		i = 0;
		while (i != n && i < ways->num_of_ways)
		{
			if ((tail = current_vertex(new, ways->way[i])))
			{
				printf("\n\n0000000000000 BEFORE 0000000000000\n\n");
				printf("\n\n=========%i++++++++++++++\n", n);
				print_edges_struct(ways->way[n]);
				printf("\n\n=========%i++++++++++++++\n", i);
				print_edges_struct(ways->way[i]);
				
				swap_tails(new, tail);
				printf("\n\n0000000000000 AFTER 0000000000000\n\n");
				printf("=========%i++++++++++++++\n", n);
				print_edges_struct(ways->way[n]);
				printf("\n\n=========%i++++++++++++++\n", i);
				print_edges_struct(ways->way[i]);
				n = i;
				i = 0;
				new = ways->way[n];
				continue ;
			}
			i++;
		}
		new = new->next;
	}

}
