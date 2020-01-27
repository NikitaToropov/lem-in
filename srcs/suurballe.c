#include <lem_in.h>

// static int		caclulate_moves(t_edges *way)
// {
// 	int moves;
// 	t_edges *ptr;
// 	ptr = way;
// 	moves = 0;
// 	while (ptr)
// 	{
// 		moves++;
// 		ptr = ptr->next;
// 	}
// 	return (moves - 1);
// }

// static int		num_of_output_lines(t_ways *ways, int num_of_ants)
// {
// 	int		arr_len[ways->num_of_ways];
// 	int		result;
// 	int		i;


// 	arr_len[0] = caclulate_moves(ways->way[0]);
// 	result = arr_len[0];
// 	i = 0;
// 	while (i < ways->num_of_ways)
// 	{
// 		if ((arr_len[i] = caclulate_moves(ways->way[i])) < result)
// 			result = arr_len[i];
// 		i++;
// 	}
// 	while (num_of_ants > 0)
// 	{
// 		i = 0;
// 		while (i < ways->num_of_ways && num_of_ants > 0)
// 		{
// 			if (arr_len[i] <= result)
// 			{
// 				arr_len[i]++;
// 				num_of_ants--;
// 			}
// 			i++;
// 		}
// 		result++;
// 	}
// 	printf("\n\nres = %i\n", (result - 1));
// 	return (result - 1);
	
// }

void	suurballe(t_graph *graph)
{
	t_ways		*current_ways;
	t_ways		*new_ways;
	int			num_of_ways;

	if ((belman_ford_for_reverse_way_in_graph(graph)))
		current_ways = new_ways_struct(graph, 1);
	else
		return ;
	num_of_ways = 2;
		tree_traversal(graph->rooms, *restore_vertex);

	while ((belman_ford_for_reverse_way_in_graph(graph)))
	{
		new_ways = new_ways_struct(graph, num_of_ways);
		free_ways_struct(&new_ways);
		tree_traversal(graph->rooms, *restore_vertex);
	}
}



