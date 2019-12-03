#include <lem_in.h>

void			ft_read_input(t_vert **verts, int *ants)
{
	// int			**adj_matrix;
	char		*line;
	char		indicator;

	indicator = NONE;
	while (ft_get_next_line(0, &line))
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);

		if (ft_it_is_room(line))
			// ft_put_room(line, verts, &indicator);
		else if (ft_it_is_link(line) && !indicator)
			// ft_put_link(line);
		else if (!ft_strcmp(line, "##start"))
			indicator = START;
		else if (!ft_strcmp(line, "##end"))
			indicator = FINISH;
		else if (line[0] == '#')
			indicator = NONE;
		free(line);
	}
}