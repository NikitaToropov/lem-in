#include <lem_in.h>

void	suurballe(t_graph *graph)
{
	t_ways		*current_ways;
	// t_ways		*new_ways;

	// print_graph(graph);
	tree_traversal(graph->rooms, *print_vertex);
	current_ways = new_ways_struct(dijkstra(graph), NULL, 1);
	reverse_the_way_in_graph(graph->rooms, current_ways->way[0]);
	tree_traversal(graph->rooms, *print_vertex);
	restore_graph(graph);
	tree_traversal(graph->rooms, *print_vertex);
	// new_ways = new_ways_struct(dijkstra(graph), current_ways, 2);
	
	// free_ways_struct(&new_ways);
	free_ways_struct(&current_ways);



	







	// print_graph(graph);
	// print_graph(graph);

	// int			i;
	// t_edges		*new_way;
	// t_ways		*current_struct;
	// t_ways		*new_struct;
	
	// new_way = dijkstra(graph);
	// current_struct = new_ways_struct(new_way, NULL, 1);
	// upgrade_graph(graph, current_struct);
	// i = 2;
	// while (i <= graph->num_of_ants && (new_way = dijkstra(graph)))
	// {
	// 	new_struct = new_ways_struct(new_way, current_struct, i);
	// 	// upgrade_ways_and_graph(graph, new_struct);
	// 	if (number_of_output_lines(new_struct) >= number_of_output_lines(current_struct))
	// 	// {
	// 	// 	free_ways_struct(&new_struct);
	// 	// 	break ;
	// 	// }
	// 	free_ways_struct(&current_struct);
	// 	current_struct = new_struct;
	// 	i++;
	// }
}