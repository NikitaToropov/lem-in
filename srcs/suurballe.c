#include <lem_in.h>

void	suurballe(t_graph *graph)
{
	int			i;
	t_edges		*new_way;
	t_ways		*current;
	t_ways		*new;

	new_way = dijkstra(graph);
	current = new_ways_struct(new_way, NULL, 1);
}