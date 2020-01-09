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

int		main(int c, char v)
{
	t_graph		*graph;

	if (!(graph = ft_read_input()))
	{
		write (1, "Error\n", 6);
		return(0);
	}
	return (0);
}