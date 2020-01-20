#include <lem_in.h>

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
	result = arr_len[1];
	i = 1;
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
	t_edges		*new_way;
	int			num_of_ways;

	
	num_of_ways = 1;
	current_ways = NULL;
	// tree_traversal(graph->rooms, *print_vertex);

	while ((new_way = dijkstra(graph)))
	{
		// printf("num_of_way = %i\n", num_of_ways);
		// print_edges_struct(new_way);

		new_ways = new_ways_struct(new_way, current_ways, num_of_ways);
		num_of_ways++;

		if (current_ways)
		{
		
	// printf("\n\n\nTHIS SHIT\n\n\n\n");
	num_of_output_lines(current_ways, graph->num_of_ants);
	num_of_output_lines(new_ways, graph->num_of_ants);
			// if (num_of_output_lines(new_ways, graph->num_of_ants) > num_of_output_lines(current_ways, graph->num_of_ants))
			// {
			// 	free_ways_struct(&new_ways);
			// 	break ;
			// }
			free_ways_struct(&current_ways);
		}
		current_ways = new_ways;
		restore_graph(graph);
		custom_graph(graph, current_ways);
	}

	restore_graph(graph);
	// tree_traversal(graph->rooms, *prinzt_vertex);

	// print_ways_struct(current_ways);
	// tree_traversal(graph->rooms, *print_vertex);
	free_ways_struct(&current_ways);
}



