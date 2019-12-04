#include <lem_in.h>

void		print_rooms(t_vert *rooms)
{
	while (rooms)
	{
		printf("-------------------------------\n");
		printf("name    %s\n", rooms->name);
		printf("x       %i\n", rooms->x);
		printf("y       %i\n", rooms->y);
		printf("marker  %i\n", (int)(rooms->marker));
		rooms = rooms->next;
		printf("-------------------------------\n");
	}
}

int		main(void)
{
	// int		**adj_matrix;
	t_vert		*rooms;
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
		ft_read_input(&rooms);
		print_rooms(rooms);
	}
	return (0);
}