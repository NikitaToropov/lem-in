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

int			swap_tails(t_edges *old, t_edges *first_new, t_edges *last_new)
{
	t_edges		*current;
	t_edges		*first_old;
	t_edges		*last_old;
	t_edges		*old_for_insert;
	t_edges		*new_for_insert;

	current = old->next;
	while(current->next && current->to->key != (last_new->to->key - 1))
		current = current->next;
	if (current->to->key != (last_new->to->key - 1))
		return (0);
	first_old = current;
	while(current->next && current->to != first_new->to)
		current = current->next;
	if (current->to != first_new->to)
	{
		printf("\n\n\nPROBLEMS WITH last_old\n\n\n\n");
	}
	last_old = current;
	old_for_insert = first_old;
	new_for_insert = first_new;
	first_old = cut_there(first_old->next);
	first_new = cut_there(first_new->next);
	push_edge_back(&old_for_insert, cut_there(last_new->next));
	push_edge_back(&new_for_insert, cut_there(last_old->next));
	free_edges_struct(&first_new);
	free_edges_struct(&first_old);
	return (1);
}

int			find_first_and_last_common_verts(t_edges *way, t_edges **first, t_edges **last)
{
	t_edges		*tmp;

	tmp = way;
	while (tmp && !(tmp->to->key % 2))
		tmp = tmp->next;
	if (!tmp)
		return (0);
	*first = tmp->prev;
	while (tmp && tmp->next && tmp->to->key == (tmp->next->to->key + 1))
		tmp = tmp->next->next;
	*last = tmp;
	if (!tmp || !(tmp->to->key %2))
		printf("\n\n\nPROBLEMS WITH last\n\n\n\n");
	return (1);
}


void		swap_all_common_tails(t_ways *ways)
{
	t_edges		*first_common;
	t_edges		*last_common;
	t_edges		*tmp;
	int			i;
	int			last_way_num;

	last_way_num = ways->num_of_ways - 1;
	if (find_first_and_last_common_verts(ways->way[last_way_num], &first_common, &last_common))
	{
		i = 0;
		while (i < last_way_num)
		{
			if (i != last_way_num &&
			swap_tails(ways->way[i], first_common, last_common))
			{
				tmp = ways->way[i];
				ways->way[i] = ways->way[last_way_num];
				ways->way[last_way_num] = tmp;
				swap_all_common_tails(ways);
				return ;
			}
			i++;
		}
	}
}
