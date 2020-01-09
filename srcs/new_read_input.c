#include <lem_in.h>

int			put_if_room(t_graph *graph, char *line, char *marker, int *num_room)
{
	char	*x_in_str;
	char	*y_in_str;
	int		x;
	int		y;

	x_in_str = NULL;
	y_in_str = NULL;
	if (x_in_str = ft_strchr(line, ' '))
		y_in_str = ft_strchr(x_in_str + 1, ' ');
	if (!y_in_str || !x_in_str || ft_strchr(y_in_str + 1, ' '))
		return (0);
	if (((x = ft_atoi(x_in_str + 1)) == -1 && x_in_str[1] != '-') ||
		(x == 0 && x_in_str[1] == '-'))
		return (0);
	if ((y = ft_atoi(y_in_str + 1)) == -1 && y_in_str[1] != '-') ||
		(y == 0 && y_in_str[1] == '-'))
		return (0);
	
	return (1);
}

t_graph		*ft_read_input(void)
{
	t_graph		*graph;
	char		*line;
	int			num_room;
	char		marker;

	graph = init_graph();
	get_next_line(0, &graph->input);
	graph->num_of_ants = ft_atoi(graph->input);
	// if (!get_next_line(0, &graph->input) ||
	// (graph->num_of_ants = ft_atoi(graph->input) <= 0))
	// {
	// 	free_graph(graph);
	// 	return (NULL);
	// }
	num_room = 0;
	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, "##start"))
			marker = START;
		else if (!ft_strcmp(line, "##end"))
			marker = FINISH;
		else if (line[0] == '#' && line[1] != '#')
			marker = NONE;
		else if (!put_if_room(line) && !put_if_link(line))
		{
				write(1, "---------------------PROBLEMS----------------------------------------------------\n", 28);
				// free_graph(graph);
				// free(line);
				return (NULL);
		}
		graph->input = ft_strjoin_free(graph->input, line);
	}
}