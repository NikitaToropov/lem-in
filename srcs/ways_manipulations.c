#include <lem_in.h>

void		loop_detector(t_edges *way)
{
	t_edges		*tmp;
	t_edges		*current;

	tmp = way->next;
	while (tmp->next)
	{
		current = tmp->next;
		while (current)
		{
			if (current->to == tmp->to)
			{
				printf("\n\n\n\nSHITSHITSHITSHITSHITSHITSHITSHIT\n");
	printf("SHITSHITSHITSHITSHITSHITSHITSHIT\n");
	printf("SHITSHITSHITSHITSHITSHITSHITSHIT\n\n\n\n");
			}
			current = current->next;
		}
		tmp = tmp->next;
	}
}

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

t_edges		*paste_and_cut(t_edges *end_of_tail, t_edges *insert)
{
	t_edges		*tmp;

	tmp = end_of_tail->next;
	end_of_tail->next = insert;
	return (tmp);
}

void		insert_second_tail(t_edges *way, t_edges *insert)
{
	t_edges		*tmp_way;
	t_edges		*tmp_ins;
	t_edges		*way_for_del;

	tmp_way = way;
	while (tmp_way && tmp_way)
	{
		tmp_ins = insert;
		while (tmp_ins)
		{
			if (!(tmp_way->to->key % 2) && tmp_way->to->key == (tmp_ins->to->key - 1))
			{
				way_for_del = tmp_way->next;
				tmp_way->next = tmp_ins->next;
				tmp_ins->next = NULL;
				free_edges_struct(&insert);
				free_edges_struct(&way_for_del);
				return ;
			}
			tmp_ins = tmp_ins->next;
		}
		tmp_way = tmp_way->next;
	}
	
}



void		swap_tails(t_ways *ways)
{
	t_edges		*end_of_tail;
	t_edges		*insert;
	int			i;
	int			n;


	n = ways->num_of_ways - 1;
	loop_detector(ways->way[n]);
	end_of_tail = vert_before_first_common(ways->way[n]);
	i = 0;
	while (i < ways->num_of_ways && end_of_tail)
	{
		if (i != n && (insert = find_new_tail_and_cut(ways->way[i], end_of_tail->next)))
		{
			insert = paste_and_cut(end_of_tail, insert);
			insert_second_tail(ways->way[i], insert);
			n = i;
			end_of_tail = vert_before_first_common(ways->way[n]);
			i = 0;

// printf("\n\nYOLO!!!!\n\n");	
// print_edges_struct(old_tail);
			continue ;
		}
		i++;
	}
}
