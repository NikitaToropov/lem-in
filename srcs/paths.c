#include <lem_in.h>

int			*int_arr_copy(int *old)
{
	int		i;
	int		len;
	int		*new;

	i = 0;
	len = old[0];
	if (!(new = malloc(sizeof(int) * (len + 1))))
		exit(1);
	while (i <= len)
	{
		new[i] = old[i];
		i++;
	}
	return (new);
}

void	change_common_edges(t_path *way)
{
	int		i;
	int		j;

	i = way->num_of_paths - 1;
	while (i >= 0)
	{
		j = way->num_of_paths - 1;
		while (j >= 0)
		{
			if (j != i && swap_tails(&(way->path[i]), &(way->path[j])))
				j = way->num_of_paths - 1;
			else
				j--;
		}
		i--;
	}
}

// void	change_common_edges(t_path *way)
// {
// 	// int		*tmp;
// 	int		i;
// 	int		j;

// 	j = way->num_of_paths - 1;
// 	while (j >= 0)
// 	{
// 		i = way->num_of_paths - 1;
// 		while (i >= 0)
// 		{
// 			if (i == j)
// 			{
// 				i--;
// 				continue ;
// 			}
// 			// tmp = way->path[way->num_of_paths - 1];
// 			if (swap_tails(&(way->path[j]), &(way->path[i])))
// 			{
// 				i = way->num_of_paths - 1;
// 			}
// 			i--;
// 		}
// 		j--;
// 	}
// }

t_path		*make_new_way(t_path *way, int *new_path)
{
	t_path		*new;
	int			i;
	int			len;

	if (!(new = malloc(sizeof(t_path))))
		exit(1);
	len = 1;
	if (way)
		len += way->num_of_paths;
	if (!(new->path = malloc(sizeof(int*) * len)))
		exit(1);
	new->num_of_paths = len;
	i = 0;
	while (way && i < way->num_of_paths)
	{
		new->path[i] = int_arr_copy(way->path[i]);
		i++;
	}
	new->path[i] = new_path;
	if (new->num_of_paths > 1)
		change_common_edges(new);
	return (new);
}

void	free_way(t_path **way)
{
	int		i;

	i = 0;
	while (i < (*way)->num_of_paths)
		free((*way)->path[i++]);
	free((*way)->path);
	free(*way);
	way = NULL;
}