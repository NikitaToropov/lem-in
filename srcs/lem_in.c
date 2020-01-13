#include <lem_in.h>

int		main(void)
{
	t_graph		*graph;

	if (!(graph = read_input()))
	{
		write (1, "Error\n", 6);
		return(0);
	}
	print_graph(graph);
	free_graph(graph);
	return (0);
}