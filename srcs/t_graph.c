#include <lem_in.h>

void			print_graph(t_graph *graph)
{
	printf("len    = %i\n", graph->length);
	printf("start  = %i\n", graph->start);
	printf("finish = %i\n", graph->finish);
	printf("ants   = %i\n", graph->num_of_ants);
	printf("%s\n", graph->input);
	pre_order(graph->rooms);
}

t_graph			*init_graph(char *line)
{
	t_graph		*graph;

	if (!(graph = malloc(sizeof(t_graph))))
		exit(1);
	if ((graph->num_of_ants = ft_atoi(line)) <= 0)
	{
		free (line);
		return (NULL);
	}
	graph->start = -1;
	graph->finish = -1;
	graph->length = 0;
	graph->input = NULL;
	graph->rooms = NULL;
	return (graph);
}

// void			free_graph(t_graph *s_graph)
// {
// 	if
// }