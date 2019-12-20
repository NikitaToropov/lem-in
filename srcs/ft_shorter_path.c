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
	return (i);
}

t_path		*ft_find_shorter_path(t_path *start_room, t_matrix *matrix, int lvl)
{
	t_path		*tmp_room;
	char		next_link;
	int			i;

	start_room = ft_add_room(matrix, matrix->start);
	tmp_room = start_room;
	while (tmp_room->room != matrix->finish)
	{
		i = 0;
		next_link = matrix->mtrx[tmp_room->room]
		while (i < tmp_room->num_of_links && (next_link = ft_strchr(next_link, '1')))
		{
			i++;
		}
		
	}
	
}

t_path		*ft_add_room(t_matrix *matrix, int current_room)
{
	t_path		*step;
	int			i;

	if (!(step = malloc(sizeof(t_path))))
		exit (1);
	step->room = current_room;
	if (current_room != matrix->finish)
		ft_del_links_to(matrix, current_room);
	step->num_of_links = ft_num_of_links(matrix->mtrx[matrix->start], '1');
	if (!(step->next = malloc(sizeof(t_path*) * step->num_of_links)))
		exit (1);
	return (step);
}