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
	t_adjacency		*arr_adj;
	t_verts			*rooms;
	char			*line;
	int				num_of_ants;
	
	line = NULL;
	rooms = NULL;
	num_of_ants = 0;
	if (!get_next_line(0, &line) || (num_of_ants = ft_atoi(line)) <= 0)
	{
		write(1, "Error\n", 6);
	}
	write(1, line, ft_strlen(line));
	write(1, "\n", 1);
	free(line);
	if (num_of_ants > 0)
	{
		arr_adj = ft_read_input(&rooms);
		// print_rooms(rooms);
		// bhandari(m_list, num_of_ants);

		// ft_free_rooms(&rooms);
		// ft_free_mtrx(&m_list);
		// path = ft_shorter_path(m_list);
	}
	return (0);
}