#include <lem_in.h>
void	print_t_match(t_match *rooms)
{
	t_match		*tmp;

	printf("\n___________PRINT T_MATCH GO___________\n");
	tmp = rooms;
	while (tmp)
	{
		
		printf("name room %s|\n", tmp->name_of_room);
		tmp = tmp->next;
	}
	printf("___________PRINT T_MATCH STOP_________\n");
}

int		num_by_name(t_match *rooms, char *name)
{
	t_match		*tmp;

	// printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
	tmp = rooms;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name_of_room, name))
			return (tmp->number_of_room);
		tmp = tmp->next;
	}

	return (-1);
}

int			is_it_a_room(t_graph *graph, char *line, char marker, int num_room)
{
	char	*x_in_str;
	char	*y_in_str;
	int		x;
	int		y;

		// printf("marker = %i\n", marker);
		// printf("graph->start = %i\n", graph->start);
		// printf("graph->finish = %i\n", graph->finish);
	if ((marker == START && graph->start >= 0) ||
	(marker == FINISH && graph->finish >= 0))
	{
		// printf("PROBLEM\n");
		// printf("marker = %i\n", marker);

		return (0);
	}
	
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
	if (num_by_name(rooms, first) < 0 || num_by_name(rooms, second) < 0)
	{
		second[-1] = '-';
		return (0);
	}
	second[-1] = '-';
	return (1);
}

void		push_back_t_match(t_match **room, char *name, int num_room)
{
	t_match		*new;
	t_match		*tmp;

	if (!(new = malloc(sizeof(t_match))))
		exit(1);
	new->name_of_room = name;
	new->number_of_room = num_room;
	new->next = NULL;
	if (*room == NULL)
		*room = new;
	else
	{
		tmp = *room;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
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
	// printf("num_of_antsn = %i\n", graph->num_of_ants);
	marker = 0;
	// printf("%s\n", graph->input);

	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, "##start"))
		{

			marker = START;
		}
		else if (!ft_strcmp(line, "##end"))
			marker = FINISH;
		else if (line[0] == '#' && line[1] != '#')
			marker = NONE;
		else if (is_it_a_room(graph, line, marker, num_room) && num_room >= graph->length)
		{
			marker = 0;
			put_the_room(graph, line, num_room, &rooms);
			graph->length = num_room + 1;
			num_room += 2;
		}
		else if (is_it_a_link(line, rooms) && !marker)
		{
			num_room = 0;
			// put_the_link(graph, line, num_room, rooms);
		}
		else
		{
				write(1, "---------------------PROBLEMS------------------\n", 48);
				// free_graph(graph);
				free(line);
				return (NULL);
		}
		// graph->input = ft_strjoin_free(graph->input, ft_strdup("\n"));
		// graph->input = ft_strjoin_free(graph->input, line);
	}
		// printf("%s\n", graph->input);
	// pre_order(graph->rooms);

	return (graph);
}