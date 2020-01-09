#include <lem_in.h>

t_graph			*init_graph(void)
{
	t_graph		*graph;

	if (!(graph = malloc(sizeof(t_graph))))
		exit(1);
	graph->start = -1;
	graph->finish = -1;
	graph->length = 0;
	graph->num_of_ants = 0;
	graph->input = NULL;
	graph->rooms = NULL;
	return (graph);
}

// void			free_graph(t_graph *s_graph)
// {
// 	if
// }