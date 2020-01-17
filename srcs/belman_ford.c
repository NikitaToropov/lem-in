#include <lem_in.h>










t_edges		*dijkstra(t_graph *graph)
{
	// Step 2: Relax all edges |V| - 1 times. A simple 
	// shortest path from src to any
}





int			num_of_output_lines(t_path *way, int num_of_ants)
{
	int		arr_len[way->num_of_paths];
	int		result;
	int		i;

	i = 0;
	result = way->path[0][0];
	while (i < way->num_of_paths)
	{
		arr_len[i] = way->path[i][0] - 1;
		if (result > arr_len[i++])
			result = arr_len[i - 1];
		i++;
	}
	while (num_of_ants)
	{
		i = 0;
		while (i < way->num_of_paths && num_of_ants)
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