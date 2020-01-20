#include <lem_in.h>

t_edges		*vert_before_first_common(t_edges *way)
{
	t_edges		*current;

	current = way;
	while (current && current->next && current->next->next)
	{
		if (current->next->next->to->key % 2)
			return (current);
		current = current->next;
	}
	return (NULL);
}
t_edges		*find_new_tail_and_cut(t_edges *way, t_edges *vert)
{
	t_edges		*current;
	t_edges		*result;

	current = way;
	while (current->next)
	{
		if (current->next->to == vert->to)
		{
			result = current->next;
			current->next = NULL;
			return (result);
		}
		current = current->next;
	}
	return (NULL);
}

void		insert_old_tail(t_edges *way, t_edges *tail)
{
	t_edges		*tmp_way;
	t_edges		*tmp_tail;
	t_edges		*way_for_del;

	tmp_way = way;
	while (tmp_way && tmp_way->next && tmp_way->next->next)
	{
		tmp_tail = tail;
		while (tmp_tail && tmp_tail->next && tmp_tail->next->next)
		{
			if (tmp_way->next->to->key == (tmp_tail->next->to->key - 1))
			{
				way_for_del = tmp_way->next;
				tmp_way->next = tmp_tail->next;
				tmp_tail->next = NULL;
				free_edges_struct(tail);
				free_edges_struct(way_for_del);
				return ;
			}
			tmp_tail = tmp_tail->next;
		}
		tmp_way = tmp_way->next;
	}

	printf("\n\n\SHITSHITSHITSHITSHITSHITSHITSHIT\n");
	printf("SHITSHITSHITSHITSHITSHITSHITSHIT\n");
	printf("SHITSHITSHITSHITSHITSHITSHITSHIT\n\n\n\n");

}

void		swap_tails(t_ways *ways)
{
	t_edges		*current;
	int			current_way_num;
	int			i;
	t_edges		*vert_before_old_tail;
	t_edges		*old_tail;
	t_edges		*new_tail;

	current_way_num = ways->num_of_ways - 1;
	current = ways->way[current_way_num];
	i = 0;
	vert_before_old_tail = vert_before_first_common(current);
	while (i < ways->num_of_ways && old_tail)
	{
		if (i != current_way_num && (new_tail = find_new_tail_and_cut(ways->way[i], new_tail->next)))
		{
			old_tail = vert_before_old_tail->next;
			vert_before_old_tail->next = new_tail;
			insert_old_tail(ways->way[i], old_tail);
			current = ways->way[i];
			current_way_num = i;
			i == 0;
			continue ;
		}
		i++;
	}
}