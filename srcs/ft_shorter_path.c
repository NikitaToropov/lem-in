#include <lem_in.h>

void		ft_del_links_to(t_matrix *matrix, int room)
{
	int		i;

	i = 0;
	while (i < matrix->len)
	{
		matrix->mtrx[i][room] = '0';
		i++;
	}
}

int			ft_num_of_links(char *str, char c)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i)
}

t_path		*ft_shorter_paths(t_matrix *matrix, t_verts *rooms, int current_room)
{
	t_path		*step;
	int			i;

	if (!(step = malloc(sizeof(t_path))))
		exit (1);
	step->room = current_room;
	ft_del_links_to(matrix, current_room);
	step->num_of_links = ft_num_of_links(matrix->mtrx[matrix->start], '1');
	i = 0;
	while (i < step->num_of_links)
	{
		if (!(step->next[i] = malloc(sizeof(t_path))))
			exit (1);
	}
}