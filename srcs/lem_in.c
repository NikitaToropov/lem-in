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
	char		*input;
	t_matrix	*m_list;
	t_verts		*rooms;
	int			num_of_ants;
	
	line = NULL;
	rooms = NULL;
	num_of_ants = 0;
	
	input = ft_read_input(&rooms);
	print_rooms(rooms);
	return (0);
}