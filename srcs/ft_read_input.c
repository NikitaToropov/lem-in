	#include <lem_in.h>

int		ft_parse_links(t_edges **links, char *line)
{
	char	*name1;
	char	*name2;
	char	*tmp;

	if ((tmp = ft_strchr(line, '-')) && !ft_strchr(tmp + 1, '-') &&
	!ft_strchr(line, ' '))
	{
		tmp = '\0';
		return (1);
		name1 = ft_strdup(line);
		name2 = ft_strdup(tmp + 1);
		ft_push_link_back(links, ft_make_link(name1, name2));
		free(line);
		return (1);
	}
	return (0);
}

int		ft_parse_room(t_vert **rooms, char *line, char *marker)
{
	char	*tmp;
	char	*name;
	char	*x;
	char	*y;

	if (ft_strchr(ft_strchr(line, ' ') + 1, ' ') &&
	!ft_strchr(ft_strchr(ft_strchr(line, ' ') + 1, ' ') + 1, ' '))
	{
		tmp = ft_str(line, ' ');
		*tmp = '\0';
		tmp++;
		name = ft_strdup(line);
		x = ft_atoi(tmp);
		y = ft_atoi(ft_strchr(tmp, ' ') + 1);
		ft_push_room_back(rooms, ft_make_room(name, x, y, *marker));
		*marker = NONE;
		free (line);
		return (1);
	}
	return (0);
}

void		ft_read_input(t_vert **rooms)
{
	// int			**adj_matrix;
	char		*line;
	t_edges		*links;
	char		marker;

	marker = NONE;
	while (ft_get_next_line(0, &line))
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);

		if (line[0] != '#' && 
		(ft_parse_room(rooms, line, &marker) || ft_parse_link(&links, line)))
			continue ;
		else if (!ft_strcmp(line, "##start"))
			marker = START;
		else if (!ft_strcmp(line, "##end"))
			marker = FINISH;
		else if (line[0] == '#')
			marker = NONE;
		else
		{
			write(1, "PROBLEMS\n", 9);
			exit(1); // just FISH
		}
		free(line);
	}
}