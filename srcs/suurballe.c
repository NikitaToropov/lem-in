#include <lem_in.h>

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

		new_ways = new_ways_struct(new_way, current_ways, num_of_ways);
		num_of_ways++;
		if (current_ways)
		{

			free_ways_struct(&current_ways);
		}
		current_ways = new_ways;
		restore_graph(graph);
		custom_graph(graph, current_ways);
	printf("num_of_ways = %i\n", num_of_ways);

	}

	restore_graph(graph);
	print_ways_struct(current_ways);
	// tree_traversal(graph->rooms, *print_vertex);
	free_ways_struct(&current_ways);
}



