#include <lem_in.h>

void	change_common_edges(t_path *way)
{
	int		*tmp;
	int		i;
	int		j;
	int		k;
	int		*first;
	int		*second;

	i = way->num_of_paths - 1;
	j = 0;
	while (j > 0)
	{
		k = 1;
		while (k < way->path[j][0])
		{
			if (ft_arrint())
			k++;
		}
	}
}

int			*int_array_copy(int *arr)
{
	
	if (!())
	return (new);
}

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
	}
	new->path[i] = new_path;
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