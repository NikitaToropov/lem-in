#include <lem_in.h>

int		main(void)
{
	t_graph		*graph;

	if (!(graph = ft_read_input()))
	{
		write (1, "Error\n", 6);
		return(0);
	}
	return (0);
}