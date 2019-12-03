#include <lem_in.h>

int		main(void)
{
	// int		**adj_matrix;
	t_vert	*verts;
	t_links	*links;
	char	*line;
	int		num_of_ants;

	if (!ft_get_next_line(0, &line) || (num_of_ants = ft_atoi(line)) <= 0 ||
	!ft_strcmp(line, ft_itoa(num_of_ants)))
		write(1, "Error\sn", 6);
	free(line);
	if (num_of_ants > 0)
	{
		ft_read_input();
	}
	return (0);
}