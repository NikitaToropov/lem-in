#include <lem_in.h>

void	print_matrix(t_matrix *m_list)
{
	int		i;
	int		j;

	i = 0;
	printf("++++++++++++++++++++++++++++++++\n");
	while (i < m_list->len)
	{
		j = 0;
		printf("|");
		while (j < m_list->len)
		{
			printf("%i", m_list->mtrx[i][j]);
			j++;
		}
		printf("|\n");
		i++;
	}
	printf("len = %i\n", m_list->len);
	printf(". . . . . . . . . . . . . . . .\n");
	printf("start  = %i\n", m_list->start);
	printf("finish = %i\n", m_list->finish);
	printf("++++++++++++++++++++++++++++++++\n");
}

int			ft_find_room_by_mark(t_verts *rooms, char mark)
{
	while (rooms)
	{
		if (rooms->marker == mark)
			return (rooms->num);
		rooms = rooms->next;
	}
	return (-1);
}

void		ft_free_mtrx(t_matrix **m_list)
{
	(*m_list)->len -=1;
	while ((*m_list)->len >= 0)
	{
		free((*m_list)->mtrx[(*m_list)->len]);
		(*m_list)->len -= 1;
	}
	free((*m_list)->mtrx);
	free(*m_list);
	m_list = NULL;
}

int			ft_find_room_num(t_verts *rooms, char *name)
{
	while (rooms)
	{
		if (!ft_strcmp(rooms->name, name))
			return (rooms->num);
		rooms = rooms->next;
	}
	return (-1);
}

void		ft_fill_matrix(t_matrix *m_list, t_verts *rooms, t_edges *link)
{
	int		i;
	int		j;

	while (link)
	{
		i = ft_find_room_num(rooms, link->pair[0]);
		j = ft_find_room_num(rooms, link->pair[1]);
		m_list->mtrx[i][j] |= 1;
		m_list->mtrx[j][i] |= 1;
		link = link->next;
	}
}

int			ft_matrix_len(t_verts *rooms)
{
	if (!rooms)
		return (0);
	while (rooms->next)
		rooms = rooms->next;
	return (rooms->num + 1);
}

t_matrix	*ft_make_matrix(t_verts *rooms, t_edges *links)
{
	t_matrix	*list;
	int			i;
	int			j;
	
	if (!(list = malloc(sizeof(t_matrix))))
		exit(1);
	list->len = ft_matrix_len(rooms);
	if (!(list->mtrx = malloc(sizeof(int*) * list->len)))
		exit(1);
	i = 0;
	while (i < list->len)
	{
		if (!(list->mtrx[i] = malloc(sizeof(int) * list->len)))
			exit(1);
		j = 0;
		while (j < list->len)
		{
			list->mtrx[i][j] = 0;
			j++;
		}
		i++;
	}
	ft_fill_matrix(list, rooms, links);
	list->start = ft_find_room_by_mark(rooms, START);
	list->finish = ft_find_room_by_mark(rooms, FINISH);
	print_matrix(list);
	return (list);
}