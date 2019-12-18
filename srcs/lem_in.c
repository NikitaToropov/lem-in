#include <lem_in.h>

void		print_rooms(t_verts *rooms)
{
	while (rooms)
	{
		printf("-------------------------------\n");
		printf("name    %s\n", rooms->name);
		printf("num     %i\n", rooms->num);
		printf("x       %i\n", rooms->x);
		printf("y       %i\n", rooms->y);
		printf("marker  %i\n", (int)(rooms->marker));
		rooms = rooms->next;
		printf("-------------------------------\n");
	}
}

int		main(void)
{
	t_matrix	*m_list;
	t_verts		*rooms;
	// t_path		*path;
	char		*line;
	int			num_of_ants;
	
	line = NULL;
	rooms = NULL;
	num_of_ants = 0;
	if (!ft_get_next_line(0, &line) || (num_of_ants = ft_atoi(line)) <= 0)
	// !ft_strcmp(line, ft_itoa(num_of_ants)))
	{
		write(1, "Error\n", 6);
		write(1, "Error\n", 6);

	}
	write(1, line, ft_strlen(line));
	write(1, "\n", 1);
	free(line);
	if (num_of_ants > 0)
	{
		m_list = ft_read_input(&rooms);
		print_rooms(rooms);
		ft_free_rooms(&rooms);
		ft_free_mtrx(&m_list);
		// path = ft_shorter_path(m_list);
	}
	return (0);
}