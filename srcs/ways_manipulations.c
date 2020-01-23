#include <lem_in.h>

// void		loop_check(t_edges *way)
// {
// 	t_edges		*edge1;
// 	t_edges		*edge2;

// 	edge1 = way;
// 	while (edge1->next)
// 	{
// 		edge2 = edge1->next;
// 		while (edge2)
// 		{
// 			if (edge2 == edge1)
// 			{
// 				printf("LOOOOOOOP");
// 				exit(1);
// 			}
// 			edge2 = edge2->next;
// 		}
// 		edge1 = edge1->next;
// 	}
// }

t_edges		*cut_there(t_edges *vertex)
{
	if (vertex && vertex->prev)
	{
		vertex->prev->next = NULL;
		vertex->prev = NULL;
	}
	return (vertex);
}

t_edges		*it_is_common_vertex(t_edges *vert, t_edges *old)
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

void		swap_tails(t_edges *new_tail, t_edges *old_tail)
{
	t_edges		*new;
	t_edges		*old;
	t_edges		*old_for_insertion;
	t_edges		*new_for_insertion;
	t_edges		*for_del;

	new_for_insertion = new_tail->prev;	
	cut_there(new_tail);
	old_for_insertion = old_tail->prev;
	cut_there(old_tail);
	push_edge_back(&new_for_insertion, old_tail);
	push_edge_back(&old_for_insertion, new_tail);
	old = old_for_insertion;
	new = new_tail->next;

	while (new->to == old->to)
	{
		old = old->prev;
		new = new->next;
	}
	old = old->next;
	for_del = cut_there(old->next);
	cut_there(new);
	free_edges_struct(&for_del);
	push_edge_back(&old, new);
}

t_edges		*find_first_and_last_common_verts(t_edges *way, t_ways **first, t_ways **last)
{
	t_edges		*tmp;

	tmp = way;
	while (tmp && !(tmp->to->key % 2))
		tmp = tmp->next;
	*first = tmp->prev;
	while (tmp && tmp->next && tmp->to->key == (tmp->next->to->key + 1))
		tmp = tmp->next->next;
	*last = tmp;
}


void		swap_all_common_tails(t_ways *ways)
{
	t_edges		*new_tail;
	t_edges		*old_tail;
	t_edges		*tmp;
	int			n;
	int			i;

	n = ways->num_of_ways - 1;
	new_tail = ways->way[n]->next;
	old_tail = NULL;
	while (new_tail->next)
	{
		i = 0;
		while (i != n && i < ways->num_of_ways)
		{
			if ((old_tail = it_is_common_vertex(new_tail, ways->way[i]->next)))
			{
				print_edges_struct(ways->way[i]);
				print_edges_struct(ways->way[n]);
				swap_tails(new_tail, old_tail);
				print_edges_struct(ways->way[i]);
				print_edges_struct(ways->way[n]);
				// print_edges_struct(ways->way[n]);
				tmp = ways->way[i];
				ways->way[i] = ways->way[n];
				ways->way[n] = tmp;
				loop_check(ways->way[i]);
				loop_check(ways->way[n]);
	printf("\n\n\nTHIS SHIT\n\n\n\n");
				swap_all_common_tails(ways);

				return ;
			}
			i++;
		}
		new_tail = new_tail->next;
	}
}
