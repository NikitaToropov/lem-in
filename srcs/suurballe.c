#include <lem_in.h>

void			check_the_valid(t_graph *graph, t_ways *ways)
{
	t_edges		*tmp;
	t_edges		*edges;
	t_verts		*from;
	t_verts		*to;
	int			i;

	i = 0;
	while (i < ways->num_of_ways)
	{
		tmp = ways->way[i];
		while (tmp->next)
		{
			from = find_vertex(graph->rooms, tmp->to->key);
			to = find_vertex(graph->rooms, tmp->next->to->key);
			edges = from->edge;
			while (edges)
			{
				if (edges->to == to)
				{
					break ;
				}
				edges = edges->next;
			}
			if (!edges)
			{
				printf("++++++++++++++++++++++ PROBLEMS ++++++++++++++++++++++\n");
				print_vertex(from);
				print_edges_struct(from->edge);
				printf("++++++++++++++++++++++ PROBLEMS ++++++++++++++++++++++\n");
			}
			tmp = tmp->next;
		}
		i++;
	}
}

static int		caclulate_moves(t_edges *way)
{
	int moves;
	t_edges *ptr;
	ptr = way;
	moves = 0;
	while (ptr)
	{
		moves++;
		ptr = ptr->next;
	}
	return (moves - 1);
}

static int		num_of_output_lines(t_ways *ways, int num_of_ants)
{
	int		arr_len[ways->num_of_ways];
	int		result;
	int		i;


	arr_len[0] = caclulate_moves(ways->way[0]);
	result = arr_len[0];
	i = 0;
	while (i < ways->num_of_ways)
	{
		if ((arr_len[i] = caclulate_moves(ways->way[i])) < result)
			result = arr_len[i];
		i++;
	}
	while (num_of_ants > 0)
	{
		i = 0;
		while (i < ways->num_of_ways && num_of_ants > 0)
		{
			if (arr_len[i] <= result)
			{
				arr_len[i]++;
				num_of_ants--;
			}
			i++;
		}
		result++;
	}
	printf("\n\nres = %i\n", (result - 1));
	return (result - 1);
	
}

void	suurballe(t_graph *graph)
{
	t_ways		*current_ways;
	t_ways		*new_ways;
	t_ways		*best;
	t_edges		*new_way;
	int			num_of_ways;

	num_of_ways = 1;
	current_ways = NULL;
	best = NULL;
	// print_vertex(find_vertex(graph->rooms, 2688));
	print_vertex(find_vertex(graph->rooms, 2686));
	// exit(1);
	while ((new_way = belman_ford(graph)))
	{
		printf("++++++++++++++++++++ num_of_ways = %i ++++++++++++++++++++", num_of_ways);
		new_ways = new_ways_struct(new_way, current_ways, num_of_ways);

		num_of_ways++;
		if (!best)
			best = new_ways;

		if (num_of_output_lines(new_ways, graph->num_of_ants) < num_of_output_lines(best, graph->num_of_ants))
		{
			if (current_ways != best)
				free_ways_struct(&best);
			best = new_ways;
		}

		if (current_ways != best)
			free_ways_struct(&current_ways);
		current_ways = new_ways;
		restore_graph(graph);
		custom_graph(graph, current_ways);
	// print_vertex(find_vertex(graph->rooms, 2686));
	
	}

	if (current_ways != best)
		free_ways_struct(&current_ways);
	if (best)
		free_ways_struct(&best);
}



