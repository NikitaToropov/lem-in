/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:03:33 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/17 18:44:14 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		is_it_a_room(t_graph *graph, char *line, char *marker, int num_room)
{
	char	*x_in_str;
	char	*y_in_str;
	int		x;
	int		y;

	if ((*marker == START && graph->start >= 0) ||
	(*marker == FINISH && graph->finish >= 0) || num_room == graph->length)
		return (0);
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
	if (*marker == START)
		graph->start = num_room;
	else if (*marker == FINISH)
		graph->finish = num_room;
	*marker = 0;
	return (1);
}

int		is_it_a_link(char *line, t_match *rooms)
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

void	put_the_room(t_graph *graph, char *line, int *num_room, t_match **room)
{
	char	*name;
	char	*tmp;
	t_verts *real;
	t_verts *psevdo;

	name = ft_strdup(line);
	tmp = ft_strchr(name, ' ');
	*tmp = '\0';
	graph->rooms = insert(graph->rooms, *num_room, name);
	graph->rooms = insert(graph->rooms, *num_room + 1, ft_strdup("psevdo"));
	psevdo = find_vertex(graph->rooms, *num_room + 1);
	real = find_vertex(graph->rooms, *num_room);
	push_edge_front(&psevdo->edge, new_edge(real));
	push_back_t_match(room, name, *num_room);
	*num_room += 2;
}

void	put_the_link(t_graph *graph, char *line, t_match *rooms, int num_room)
{
	char		*first;
	char		*second;
	t_verts		*first_vert;
	t_verts		*second_vert;

	if (graph->length == -1)
		graph->length = num_room;
	first = line;
	second = ft_strchr(first, '-');
	*second = '\0';
	second++;
	first_vert = find_vertex(graph->rooms, number_and_name_match(rooms, first));
	second_vert = find_vertex(graph->rooms, number_and_name_match(rooms, second));
	second[-1] = '-';
	push_edge_back(&first_vert->edge, new_edge(second_vert));
	push_edge_back(&second_vert->edge, new_edge(first_vert));
}

t_graph	*read_input(void)
{
	t_graph		*graph;
	t_match		*rooms;
	char		*line;
	int			num_room;
	char		marker;

	if (get_next_line(0, &line) <= 0 || !(graph = init_graph(line)))
		return (NULL);
	num_room = 0;
	rooms = NULL;
	marker = 0;
	while (graph && get_next_line(0, &line))
	{
		push_line_back(graph->input, line);
		if (!ft_strcmp(line, "##start"))
			marker = START;
		else if (!ft_strcmp(line, "##end"))
			marker = FINISH;
		else if (line[0] == '#' && line[1] != '#')
			marker = NONE;
		else if (is_it_a_room(graph, line, &marker, num_room))
			put_the_room(graph, line, &num_room, &rooms);
		else if (is_it_a_link(line, rooms) && !marker)
			put_the_link(graph, line, rooms, num_room);
		else
			free_graph(&graph);
	}
	while (get_next_line(0, &line))
		free(line);
	free_t_match(&rooms);
	return (graph);
}
