#include <lem_in.h>

int			is_it_a_room(t_graph *graph, char *line, char *marker, int num_room)
{
	char	*x_in_str;
	char	*y_in_str;
	int		x;
	int		y;

	if ((marker == START && graph->start) ||
	(marker == FINISH && graph->finish))
		return (0);
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
	if (marker == START)
		graph->start = num_room;
	else if (marker == FINISH)
		graph->finish = num_room;
	return (1);
}

int			is_it_a_link(t_graph *graph, char *line, t_match *rooms)
{
	char		*first;
	char		*second;

	first = line;
	if (!(second = ft_strchr(line, '-')))
		return (0);
	*second = '\0';
	second++;
	if (!num_by_name(rooms, first) || !num_by_name(rooms, second))
		return (0);
	return (1);
}


t_graph		*ft_read_input(void)
{
	t_graph		*graph;
	t_match		*rooms;
	char		*line;
	int			num_room;
	char		marker;

	if (!get_next_line(0, &line) || !(graph = init_graph(line)))
		return (NULL);
	num_room = 0;
	rooms = NULL;
	while (get_next_line(0, &line) && !is_it_a_link(line))
	{
		if (!ft_strcmp(line, "##start"))
			marker = START;
		else if (!ft_strcmp(line, "##end"))
			marker = FINISH;
		else if (line[0] == '#' && line[1] != '#')
			marker = NONE;
		else if (is_it_a_room(graph, line, marker, num_room) && num_room > graph->length)
		{
			put_the_room(graph, line, num_room, rooms);
			graph->length = num_room + 1;
			num_room += 2;
		}
		else if (is_it_a_link(graph, line) && !marker)
		{
			num_room = 0;
			put_the_link(graph, line, num_room, rooms);
		}
		else
		{
				write(1, "---------------------PROBLEMS----------------------------------------------------\n", 28);
				// free_graph(graph);
				free(line);
				return (NULL);
		}
		graph->input = ft_strjoin_free(graph->input, line);
	}
}	