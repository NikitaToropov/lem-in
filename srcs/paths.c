#include <lem_in.h>

int		swap_tails(int **new, int **old)
{
	int		i;
	int		j;
	int		*tail_for_new;
	int		*tail_for_old;
	int		*tmp;

	tail_for_new = NULL;
	tail_for_old = NULL;
	i = 1;
	while (i < *old[0])
	{
		j = 1;
		while (j < *new[0])
		{
			if (*old[i] == *new[j])
			{
				if (!tail_for_old)
					tail_for_old = new[j];
				else
					tail_for_new = old[i];
			}
			j++;
		}
		i++;
	}
	if (!tail_for_new || !tail_for_old)
		return (NULL);
	tmp = *new;
	if (!(*new = malloc(sizeof(int) * (*tmp[1] - *))))
		exit(1);
}

void	change_common_edges(t_path *way)
{
	int		*tmp;
	int		i;

	tmp = way->path[way->num_of_paths - 1];
	i = way->num_of_paths - 2;
	whlie (i >= 0)
	{
		if (swap_tails(tmp, way->path[i]))
			tmp = way->path[i];
		i--;
	}
}

// int			*int_array_copy(int *arr)
// {
	
// 	if (!())
// 	return (new);
// }

t_path		*make_new_way(t_path *way, int *new_path)
{
	t_path		*new;
	int			i;
	int			j;

	if (!(new = malloc(sizeof(t_path))))
		exit(1);
	if (!(new->path = malloc(sizeof(int*) * (way->num_of_paths + 1))))
		exit(1);
	new->num_of_paths = way->num_of_paths + 1;
	i = 0;
	while (i < way->num_of_paths)
	{
		new->path[i] = way->path[i];
		i++;
	}
	new->path[i] = new_path;
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