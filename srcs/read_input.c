#include <lem_in.h>

int			is_it_a_room(t_graph *graph, char *line, char marker, int num_room)
{
	char	*x_in_str;
	char	*y_in_str;
	int		x;
	int		y;

	if ((marker == START && graph->start >= 0) ||
	(marker == FINISH && graph->finish >= 0))
		return (0);
	
	x_in_str = NULL;
	y_in_str = NULL;

	if ((x_in_str = ft_strchr(line, ' ')))
		y_in_str = ft_strchr(x_in_str + 1, ' ');
	if (!y_in_str || !x_in_str || ft_strchr(y_in_str + 1, ' '))
		return (0);
	if (((x = ft_atoi(x_in_str + 1)) == -1 && x_in_str[1] != '-') ||
		(x == 0 && x_in_str[1] == '-'))
		return (0);
	if (((y = ft_atoi(y_in_str + 1)) == -1 && y_in_str[1] != '-') ||
		(y == 0 && y_in_str[1] == '-'))
		return (0);
	if (marker == START)
		graph->start = num_room;
	else if (marker == FINISH)
		graph->finish = num_room;
	return (1);
}

int			is_it_a_link(char *line, t_match *rooms)
{
	char		*first;
	char		*second;

	if (!(second = ft_strchr(line, '-')))
		return (0);
	*second = '\0';
	second++;
	first = line;
	if (number_and_name_match(rooms, first) < 0 ||
	number_and_name_match(rooms, second) < 0)
	{
		second[-1] = '-';
		return (0);
	}
	second[-1] = '-';
	return (1);
}

void		put_the_room(t_graph *graph, char *line, int num_room, t_match **room)
{
	char	*name;
	char	*tmp;

	name = ft_strdup(line);
	tmp = ft_strchr(name, ' ');
	*tmp = '\0';
	graph->rooms = insert(graph->rooms, num_room, name);
	graph->rooms = insert(graph->rooms, num_room + 1, ft_strdup("psevdo"));
	push_back_t_match(room, name, num_room);
}

void		put_the_link(t_graph *graph, char *line, t_match *rooms)
{
	char		*first;
	char		*second;
	int			first_num;
	int			second_num;
	t_verts		*first_vert;
	t_verts		*second_vert;

	first = line;
	second = ft_strchr(first, '-');
	*second = '\0';
	second++;
	first_num = number_and_name_match(rooms, first);
	second_num = number_and_name_match(rooms, second);
	if (!(first_vert = find_vertex(graph->rooms, first_num)) ||
	!(second_vert = find_vertex(graph->rooms, second_num)))
	{
		printf("first = %i\n", first_num);
		printf("second = %i\n", second_num);
		write(1, "__________SHIIIIT!!!!________\n", 30);
		exit(1);
	}
	push_edge_back(&first_vert->edge, second_vert);
	push_edge_back(&second_vert->edge, first_vert);
	second[-1] = '-';
}

t_graph		*read_input(void)
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
	marker = 0;
	while (get_next_line(0, &line))
	{
		push_line_back(graph->input, line);
		if (!ft_strcmp(line, "##start"))
			marker = START;
		else if (!ft_strcmp(line, "##end"))
			marker = FINISH;
		else if (line[0] == '#' && line[1] != '#')
			marker = NONE;
		else if (is_it_a_room(graph, line, marker, num_room) && num_room >= graph->latest)
		{
			marker = 0;
			put_the_room(graph, line, num_room, &rooms);
			graph->latest = num_room + 1;
			num_room += 2;
		}
		else if (is_it_a_link(line, rooms) && !marker)
		{
			num_room = 0;
			put_the_link(graph, line, rooms);
		}
		else
		{
				write(1, "---------------------PROBLEMS------------------\n", 48);
				while (get_next_line(0, &line))
					free(line);
				free_t_match(&rooms);
				free_graph(graph);
				return (NULL);
		}
	}
	free_t_match(&rooms);
	return (graph);
}